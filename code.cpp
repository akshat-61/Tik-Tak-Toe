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

    void resetgame()
    {
        board = vector<char>(9, empty);
    }
}