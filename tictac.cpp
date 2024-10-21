#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int current_player;
char current_marker;
void drawboard()
{
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}
bool placemaker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}
int checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;
    return 0;
}
void switchPlayer()
{
    if (current_player == 1)
    {
        current_player = 2;
        if (current_marker == 'X' || current_marker == 'x')
        {
            current_marker = 'O';
        }
        else
        {
            current_marker = 'X';
        }
    }
    else
    {
        current_player = 1;
        if (current_marker == 'X' || current_marker == 'x')
        {
            current_marker = 'O';
        }
        else
        {
            current_marker = 'X';
        }
    }
}
void game()
{
    cout << "=====GAME STARTS=====" << endl;
    cout << "Player 1 enter your choice (X or 0): ";
    char choice;
    cin >> choice;
    if (choice != 'X' && choice != 'O' && choice != 'x' && choice != 'o')
    {
        cout << "=====Invalid choice=====" << endl;
        cout << "!!!!! START AGAIN !!!!!";
        return;
    }
    current_marker = choice;
    current_player = 1;
    drawboard();
    int player_won = 0;
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << current_player << "'s turn, enter your slot: ";
        int slot;
        cin >> slot;
        if (slot < 0 || slot > 9)
        {
            cout << "Invalid slot!" << endl;
            cout << "-- Enter valid slot--";
            i--;
            continue;
        }
        if (!placemaker(slot))
        {
            cout << "Slot already occupied!" << endl;
            cout << "--Enter valid slot--";
            i--;
            continue;
        }
        drawboard();
        player_won = checkWinner();
        if (player_won == 1)
        {
            cout << "!!--Player 1 won--!!" << endl;
            cout << "Game Finish!" << endl;
            break;
        }
        else if (player_won == 2)
        {
            cout << "!!--Player 2 won--!!" << endl;
            cout << "Game Finish!" << endl;
            break;
        }
        switchPlayer();
    }
    if (player_won == 0)
    {
        cout << "It's a tie!" << endl;
        cout << "Game Finish!" << endl;
    }
}
int main()
{
    game();
    return 0;
}