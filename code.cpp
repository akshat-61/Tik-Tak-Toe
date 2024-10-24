#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char Player = 'O';
const char Ai = 'X';
const char empty = ' ';

vector<char> board(9, empty);

int main()
{
    cout << "Tic Tac Toe game with AI";
    resetgame();

    while (true)
    {
        printboard();
        if (!checkwinner(board, Player) && !checkwinner(board, Ai) && !checktie(board))
        {
            playermove();

            if (!checkwinner(board, Player) && !checktie(board))
            {
                int move = bestmove();
                board[move] = AI;
                cout << "AI played at position " << move + 1 << endl;
            }
        }
        if (checkwinner(board, Player))
        {
            printboard();
            cout << "Player Wins! ";
            break;
        }
        else if (checkwinner(board, Ai))
        {
            printboard();
            cout << "AI Wins! ";
            break;
        }
        else if (checktie(board))
        {
            printboard();
            cout << "The match is Tie! ";
            break;
        }
    }
    return 0;

    void printboard()
    {
        cout << "\n";
        for (int i = 0; i < 9; i++)
        {
            cout << " " << board[i];

            if ((i + 1) % 3 == 0)
            {
                cout << "\n";
                if (i != 8)
                    cout << "---|---|---\n";
            }
            else
            {
                cout << " |";
            }
        }
        cout << "\n";
    }

    bool checkwinner(const vector<char> &b, char player)
    {

        const vector<vector<int>> winningcombos = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}};
        for (auto combo : winningcombos)
        {
            if (b[combos[0]] == player && b[combo[1]] == player && b[combo[2]] == player)
            {
                return true;
            }
        }
        return false;
    }

    void resetgame()
    {
        board = vector<char>(9, empty);
    }
}