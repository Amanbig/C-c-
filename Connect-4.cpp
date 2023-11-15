#include <iostream>
#include <vector>
using namespace std;

#define ROWS 6
#define COLS 7

vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));

void print_board()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
}

bool is_winner(char player)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
                return true;
        }
    }

    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
                return true;
        }
    }

    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
                return true;
        }
    }

    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 3; j < COLS; j++)
        {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player)
                return true;
        }
    }

    return false;
}

bool is_draw()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; 
            }
        }
    }
    return true; 
}

bool is_terminal()
{
    return is_winner('X') || is_winner('O') || is_draw();
}

int evaluate()
{
    if (is_winner('X'))
    {
        return 1;
    }
    else if (is_winner('O'))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bool is_valid_move(int col)
{
    return board[0][col] == ' ';
}

int get_next_open_row(int col)
{
    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (board[row][col] == ' ')
        {
            return row;
        }
    }
    return -1;
}
int minimax(vector<vector<char>> &board, int depth, bool maximizing_player, int alpha, int beta)
{
    if (depth == 0 || is_terminal())
    {
        return evaluate();
    }
    if (maximizing_player)
    {
        int max_eval = -99999999;
        for (int i = 0; i < COLS; i++)
        {
            if (is_valid_move(i))
            {
                int row = get_next_open_row(i);
                board[row][i] = 'X';
                int eval = minimax(board, depth - 1, false, alpha, beta);
                board[row][i] = ' ';
                max_eval = max(max_eval, eval);
                alpha = max(alpha, eval);
                if (beta <= alpha)
                {
                    break;
                }
            }
        }
        return max_eval;
    }
    else
    {
        int min_eval = 99999999;
        for (int i = 0; i < COLS; i++)
        {
            if (is_valid_move(i))
            {
                int row = get_next_open_row(i);
                board[row][i] = 'O';
                int eval = minimax(board, depth - 1, true, alpha, beta);
                board[row][i] = ' ';
                min_eval = min(min_eval, eval);
                beta = min(beta, eval);
                if (beta <= alpha)
                {
                    break;
                }
            }
        }
        return min_eval;
    }
}

int find_best_move()
{
    int best_eval = -9999999;
    int best_move = -1;
    int alpha = -9999999;
    int beta = 9999999;
    for (int i = 0; i < COLS; i++)
    {
        if (is_valid_move(i))
        {
            int row = get_next_open_row(i);
            board[row][i] = 'X';
            int eval = minimax(board, 4, false, alpha, beta);
            board[row][i] = ' ';
            if (eval > best_eval)
            {
                best_eval = eval;
                best_move = i;
                alpha = max(alpha, eval);
            }
        }
    }
    return best_move;
}

void play_game()
{
    cout << "Connect Four Game" << endl;
    print_board();

    while (!is_terminal())
    {
        int player_col;
        cout << "Enter your move (0-6): ";
        cin >> player_col;

        if (is_valid_move(player_col))
        {
            int player_row = get_next_open_row(player_col);
            board[player_row][player_col] = 'O';
            print_board();
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (is_terminal())
        {
            break;
        }

        cout << "AI's turn..." << endl;
        int ai_col = find_best_move();
        int ai_row = get_next_open_row(ai_col);
        board[ai_row][ai_col] = 'X';
        print_board();
    }

    if (is_winner('O'))
    {
        cout << "You win!" << endl;
    }
    else if (is_winner('X'))
    {
        cout << "AI wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
}

int main()
{
    play_game();
    return 0;
}
