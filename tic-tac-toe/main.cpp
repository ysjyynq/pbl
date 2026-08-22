#include <iostream>
#include <random>
#include <limits>
using namespace std;

void clr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawBoard(char board[9])
{
    cout << endl;
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "--+--+--" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "--+--+--" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

int playerMove(char board[9])
{
    while (1)
    {
        int choice;
        cout << "player move (input 1-9)" << endl;
        if (!(cin >> choice))
        {
            cout << "Invalid input, please enter input 1-9" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (choice < 1 || choice > 9)
        {
            cout << "Invalid input, please enter input 1-9" << endl;
            continue;
        }
        else if (board[choice - 1] != ' ')
        {
            cout << "Position occupied" << endl;
            continue;
        }
        return choice;
    }
}

int computerMove(char board[9], mt19937& gen)
{
    uniform_int_distribution<int> distrib(0, 8);

    while (1)
    {
        int choice = distrib(gen);
        if (board[choice] == ' ')
        {
            board[choice] = 'o';
            return choice;
        }
    }
}

bool checkWin(char board[9])
{
    const int win[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; ++i)
    {
        if (board[win[i][0]] != ' ' &&
            board[win[i][0]] == board[win[i][1]] &&
            board[win[i][0]] == board[win[i][2]])
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char p = 'x';
    int move = 0;

    random_device rd;
    mt19937 gen(rd());

    drawBoard(board);
    cout << endl;
    while (move < 9)
    {
        int playerChoice = playerMove(board);
        board[playerChoice - 1] = p;
        ++move;
        clr();
        drawBoard(board);
        cout << endl;

        if (checkWin(board))
        {
            cout << "Player wins" << endl;
            return 0;
        }

        if (move == 9) {break;}

        int computerChoice = computerMove(board, gen);
        ++move;
        clr();
        drawBoard(board);
        cout << endl;

        cout << "Computer moved to " << computerChoice + 1 << endl;
        if (checkWin(board))
        {
            cout << "Computer wins" << endl;
            return 0;
        }
    }
    cout << "Tie" << endl;
}
