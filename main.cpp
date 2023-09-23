#include <iostream>
#include <ctype.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-----------" << endl;
}

void editBoard(int location)
{
    int row;
    if (location % 3 == 0)
    {
        row = location / 3 - 1;
    }
    else
    {
        row = location / 3;
    }
    int column = location - (row * 3) - 1;
    board[row][column] = currentMarker;
}

int full()
{
    for (int x = 0; x < 3; x++)
    {
        // loop rows
        for (int y = 0; y < 3; y++)
        {
            // loop cols
            if (isdigit(board[x][y]))
                return 0; // if there are any numbers left on board, return 0 (not full)
        }
    }
    return 1; // return 1 if the board is full
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        // check rows
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return currentPlayer;

        // check columns
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return currentPlayer;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return currentPlayer;

    return 0; // return 0 if nobody has won yet
}

int isEmpty(int location)
{
    int row;
    if (location % 3 == 0)
    {
        row = location / 3 - 1;
    }
    else
    {
        row = location / 3;
    }
    int column = location - (row * 3) - 1;
    if(board[row][column] == 'X' || board[row][column] == 'O')
    {
        return 0; // return 0 if the spot is already occupied
    }
    else
    {
        return 1; // return 1 if the spot is free
    }

}

void switchMarker()
{
    if (currentMarker == 'X')
        currentMarker = 'O';
    else if (currentMarker == 'O')
        currentMarker = 'X';
}

void switchPlayer()
{
    if (currentPlayer == 1)
        currentPlayer = 2;
    else if (currentPlayer == 2)
        currentPlayer = 1;
}

void gameLoop()
{
    cout << "Would you like to play [1]-Player or [2]-Player?" << endl;
    char choice;
    cin >> choice;
    if (choice == '2')
    {
        cout << "Player 1, choose [X] or [O]" << endl;
        char choice;
        cin >> choice;
        if (choice == 'X')
        {
            cout << "Player 1 is X, and Player 2 is O" << endl;
            currentMarker = 'X';
        }
        else if (choice == 'O')
        {
            cout << "Player 1 is O, and Player 2 is X" << endl;
            currentMarker = 'O';
        }
        currentPlayer = 1;

        while (!full() && !winner())
        { // main game loop runs while nobody has won and game is not full
            drawBoard();
            int validMove = 0; // while the player has not made a valid move
            while(validMove == 0)
            {
                cout << "Player " << currentPlayer << " it's your turn. Select a square to mark with an " << currentMarker << " [0-9].";
                int choice;
                cin >> choice;
                if(isEmpty(choice)) // if the chosen square is empty
                {
                    validMove = 1; //... then proceed
                    editBoard(choice);
                }
                else
                {
                    cout << "Invalid move - square already occupied. Try again." << endl;
                }
                
            }
            winner(); // check if anybody has won
            switchMarker();
            switchPlayer();
            cout << "\n" << endl;
        }
        cout << "\n" << endl;
        drawBoard();
        if (full() && !winner())
        { //if the game board is full and nobody has won, it is a tie game
            cout << "Tie game, no winner!" << endl;
        }
        else if (winner())
        { //if somebody has won
            switchPlayer(); // switch back to the player that has won
            cout << "Player " << currentPlayer << " has won!" << endl;
        }
    }
    else if (choice == '1')
    {
        // 1 player game
        // TODO
        cout << "Not yet implemented, exiting..." << endl;
    }
    else
    {
        cout << "Invalid choice, exiting..." << endl;
    }
}

int main()
{
    gameLoop();
    return 0;
}