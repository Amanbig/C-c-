#include <iostream>
#include <vector>
using namespace std;

char ar[3][3] = {' ', ' ', ' ',
                 ' ', ' ', ' ',
                 ' ', ' ', ' '};
int br[3][3] = {8, 3, 4,
                1, 5, 9,
                6, 7, 2};
vector<int> v,c;
void print_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
                cout << ar[i][j] << " | ";
            else
                cout << ar[i][j];
        }
        cout << endl;
        if (i != 2)
            cout << "---------" << endl;
    }
    cout << endl;
}

void userinput()
{
    cout << "Enter row and column\n";
    int a, b;
    cin >> a>>b;
    if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && ar[a][b] == ' ')
    {
        ar[a][b] = 'O';
        v.push_back(br[a][b]);
    }
    else
    {
        cout << "Invalid input\n";
        userinput();
    }
}
pair<int, int> find(int a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (br[i][j] == a)
            {
                return make_pair(i, j);
            }
        }
    }
}
void move()
{
    int move = 0,move1=0;
    pair<int, int> p;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            move = 15 - v[i] - v[j];
            move1 = 15 - c[i] - c[j];
            if(move1 > 0 && move1 <= 9){
                p = find(move1);
                if (p.first != -1 && p.second != -1 && ar[p.first][p.second] == ' ')
                {
                    ar[p.first][p.second] = 'X';
                    return;
                }
            }
            else if (move > 0 && move <= 9)
            {
                p = find(move);
                if (p.first != -1 && p.second != -1 && ar[p.first][p.second] == ' ')
                {
                    ar[p.first][p.second] = 'X';
                    c.push_back(br[p.first][p.second]);
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ar[i][j] == ' ')
            {
                ar[i][j] = 'X';
                c.push_back(br[i][j]);
                return;
            }
        }
    }
}
bool check_winner(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (ar[i][0] == player && ar[i][1] == player && ar[i][2] == player)
            return true;
        if (ar[0][i] == player && ar[1][i] == player && ar[2][i] == player)
            return true;
    }
    if (ar[0][0] == player && ar[1][1] == player && ar[2][2] == player)
        return true;
    if (ar[0][2] == player && ar[1][1] == player && ar[2][0] == player)
        return true;
    return false;
}
bool checkdraw()
{
    int c = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ar[i][j] == 'X' || ar[i][j] == 'O')
            {
                c++;
            }
        }
    }
    if (c == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout << "[------Tic-tac-toe Game------]\n";
    cout << endl;
    print_board();
    while (true)
    {
        if (checkdraw())
        {
            cout << "Draw\n";
            break;
        }
        cout << "[------User turn------]\n";
        cout << endl;
        userinput();
        print_board();
        if (check_winner('O'))
        {
            cout << "Player won\n";
            break;
        }
        cout << "[------Computer's turn------]\n";
        cout << endl;
        move();
        print_board();
        if (check_winner('X'))
        {
            cout << "Computer won\n";
            break;
        }
    }
    return 0;
}
