#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> ar;
vector<bool> visited;
int ver = 0;

void bst(int start, int goal)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> path;

    pq.push({0, start});
    visited[start] = true;

    while (!pq.empty())
    {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        path.push_back(current);

        if (current == goal)
        {
            cout << "Path: ";
            for (int node : path)
            {
                cout << node << " ";
            }
            cout << endl;
            return;
        }

        for (int neighbor = 0; neighbor < ver; ++neighbor)
        {
            if (!visited[neighbor] && ar[current][neighbor] != 0)
            {
                visited[neighbor] = true;
                pq.push({ar[current][neighbor], neighbor});
            }
        }
    }

    cout << "Path not found." << endl;
}

int main()
{
    int a, b;
    cout << "Enter number of vertices: ";
    cin >> a;
    ver = a;
    int choice, goal;

    ar.resize(a, vector<int>(a, 0));
    visited.resize(a, false);

    while (choice != 0)
    {
        int c, d;
        cout << "Enter 1 - input edge" << endl;
        cout << "Enter 0 - execute best first search" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter initial vertex: ";
            cin >> c;
            while (c >= ver)
            {
                cout << "Enter initial vertex again: ";
                cin >> c;
            }
            cout << "Enter final vertex: ";
            cin >> d;
            while (d >= ver)
            {
                cout << "Enter final vertex again: ";
                cin >> d;
            }
            cout << "Enter edge cost: ";
            cin >> ar[c][d];
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Not a valid choice." << endl;
        }
    }

    cout << "Enter initial vertex for Best First Search: ";
    cin >> b;

    cout << "Enter goal vertex for Best First Search: ";
    cin >> goal;

    cout << "Best First Search starting from vertex " << b <<"to "<<goal<< endl;
    bst(b, goal);

    return 0;
}
