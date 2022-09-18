
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct node {
    char *name;
    int price;
    struct node * next;
} Node;

Node* head = NULL;

void insert(char *name, int price);
void print_the_list();
void sort();
void search();
void delete_node();
int MAX_STRING_LENGTH=30;

int main() {
    head = NULL;
    char *product_name=NULL;
    int product_price=NULL;
    int n=NULL,i=NULL;
    printf("How many items you want to enter?: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 1; i <= n; i++){
        fflush(stdin);
        printf("Item %d name: ",i);
        fflush(stdin);
        product_name = (char*) malloc(MAX_STRING_LENGTH*sizeof(char));
        gets(product_name); // Same as scanf
        printf("Price: ");
        scanf("%d",&product_price);
        insert(product_name, product_price);
        }
    print_the_list();
    char d=NULL;
    printf("Do you want to sort the list in ascending order?(y/n): ");
    fflush(stdin);
    scanf("%c", &d);
    if (d == 'y' || d == 'Y') {
        printf("Sorting the list!");
        sort();
    } else
        printf("alright!");

    print_the_list();
    delete_node();
    printf("Printing the modified list");
    print_the_list();
    search();
    return 0;
}

void insert(char* name, int price){
    Node* new_node = (Node* ) malloc(sizeof(Node));
    new_node->price = price;
    new_node->name   = name;
    new_node->next   = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        Node * temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void print_the_list()
{
    printf("\n");
    printf("The Shop data is as follows: \n");
    Node* temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%25s",temp->name);
        printf("%25d",temp->price);
        temp=temp->next;
        printf("\n");
    }
}

void sort(){
    char *swap_ptr_name=NULL;
    int swap_ptr_price=NULL;
    Node* current_minimum=NULL;
    Node* current_node=NULL;
    for (current_minimum = head; current_minimum != NULL; current_minimum = current_minimum->next) {
        for (current_node = current_minimum->next; current_node != NULL;  current_node = current_node->next) {
            if (strcmp(current_node->name,current_minimum->name) < 0) {
                swap_ptr_name   = current_minimum->name;
                swap_ptr_price = current_minimum->price;

                current_minimum->name   = current_node->name;
                current_minimum->price = current_node->price;

                current_node->name   = swap_ptr_name;
                current_node->price = swap_ptr_price;
            }
        }
    }
}

void search()
{
    char *keyword=NULL;
    Node* current=head;
    printf("Enter the item to check its price: ");
    fflush(stdin);
    keyword=(char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    gets(keyword);
    for (current=head;current!=NULL;current=current->next)
    {
        if (strcmp(current->name,keyword)==0) {//||(strcmp(current->author,keyword))==0) {
            puts(current->name);
            printf("%d",current->price);
        }
    }
}


void delete_node()
{
    char *keyword=NULL;
    char d=NULL;
    Node* current=head;
    Node* temp=NULL;
    printf("Enter an item to delete: ");
    fflush(stdin);
    keyword=(char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    gets(keyword);
    for (current=head;current!=NULL;current=current->next)
    {
        if (strcmp(current->name,keyword)==0) {
            puts(current->name);
            printf("%d\n",current->price);
            printf("Are you sure you want to delete[y/n]: ");
            fflush(stdin);
            scanf("%c",&d);
            if (d=='y' || d=='Y') {
                if (current==head)
                {
                    head=current->next;
                    free(current);
                }
                else
                {
                    temp->next=current->next;
                    free(current);
                }
            }
        }
        temp=current;
    }
}