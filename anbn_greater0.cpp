#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a;
    cout << "Enter string\n";
    cin >> a;
    stack<char> s;
    s.push('Z');
    string state = "q0";

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'a' && s.top() == 'Z')
        {
            s.push(a[i]);
            state = "q0";
        }
        else if (a[i] == 'a' && s.top() == 'a')
        {
            s.push(a[i]);
            state = "q0";
        }
        else if (a[i] == 'b' && s.top() == 'a')
        {
            s.pop();
            state = "q1";
        }
        else
        {
            s.push(a[i]);
        }
    }

    if (state == "q1" && s.top() == 'Z')
    {
        cout << "Accepted\n";
    }
    else
    {
        cout << "Rejected\n";
    }

    return 0;
}
