#include <iostream>
#include <cmath>
using namespace std;
class node
{
public:
    char s;
    node *next;
    node()
    {
        next = NULL;
    }
};
template <class T>
class stack
{
    node *top = NULL;

public:
    void push(T c)
    {
        node *news = new node;
        news->s = c;
        if (empty())
        {
            top = news;
        }
        else
        {
            news->next = top;
            top = news;
        }
    }
    void pop()
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
    char peek()
    {
        char a = top->s;
        return a;
    }
    bool empty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
            return false;
    }
};
class expression
{
public:
    bool isOperator(char);
    int precedence(char);
    string InfixToPostfix(string);
    int postfixevaluation(string);
};
bool expression::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int expression::precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string expression::InfixToPostfix(string infix)
{
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.peek() != '(') && (!s.empty()))
            {
                char temp = s.peek();
                postfix += temp;
                s.pop();
            }
            if (s.peek() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(s.peek()))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.peek())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.peek())))
                    {
                        postfix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}
int expression::postfixevaluation(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.peek();
            st.pop();
            int op1 = st.peek();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.peek();
}
int main()
{
    string s;
    expression e;
    string d;
    while (1)
    {
        cout << "Enter 1 - input expression\n";
        cout << "Enter 2 - output expreeesion\n";
        cout << "Enter 3 - postfix expression\n";
        cout << "Enter 4 - result of expression\n";
        cout << "Enter 5 - exit\n";
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter expression(infix)\n";
            cin >> s;
            break;
        case 4:
            d = e.InfixToPostfix(s);
            cout << e.postfixevaluation(d) << endl;
            break;
        case 2:
            cout << s << endl;
            break;
        case 3:
            cout << e.InfixToPostfix(s) << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "No match to your selection\n";
            break;
        }
    }
}