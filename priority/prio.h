#include <iostream>
using namespace std;
class node
{
public:
   int data;
   int id;
   node *next;
   node()
   {
      next = NULL;
   }
};

class prio
{
public:
   node *head = NULL;
   void enqueue(int d,int id);
   void dequeue();
   int peek();
   void display();
   bool empty();
};

void prio::enqueue(int d,int id)
{
   node *news = new node();
   news->data = d;
   news->id=id;
   if (head == NULL)
   {
      head = news;
   }
   else if (head->next == NULL)
   {
      if (head->data >= news->data)
      {
         news->next = head;
         head = news;
      }
      else
      {
         head->next = news;
      }
   }
   else
   {
      node *temp = head;
      bool b = false;
      while (temp->next != NULL)
      {
         if (temp->next->data >= news->data)
         {
            b = true;
            break;
         }
         else
         {
            b = false;
         }
         temp = temp->next;
      }
      if (b)
      {
         news->next = temp->next;
         temp->next = news;
      }
      else
      {
         temp->next = news;
      }
   }
}

void prio::dequeue()
{
   if (head == NULL)
   {
      cout << "List is empty\n";
   }
   else if (head->next == NULL) // Case for queue with only one element
   {
      node *temps = head;
      head = NULL;
      delete temps;
   }
   else
   {
      node *temp = head;
      while (temp->next->next != NULL)
      {
         temp = temp->next;
      }
      node *temps = temp->next;
      temp->next = NULL;
      delete temps;
   }
}


void prio::display()
{
   node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << endl;
      temp = temp->next;
   }
}

int prio::peek()
{
   return head->data;
}

bool prio::empty()
{
   return head == NULL;
}