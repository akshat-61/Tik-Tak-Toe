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

    void resetgame()
    {
        board = vector<char>(9, empty);
    }
}