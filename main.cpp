# include <iostream>
# include <ctype.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentMarker;
int currentPlayer;

void drawBoard(){
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-----------" << endl;
}

void editBoard(int location){
    int row;
    if(location % 3 == 0){
        row = location / 3 - 1;
    }
    else{
        row = location / 3;
    }
    int column = location - (row*3) - 1;
    board[row][column] = currentMarker;
}

int full(){
    for(int x = 0; x < 3; x++){
        //loop rows
        for(int y = 0; y < 3; y++){
            //loop cols
            if(isdigit(board[x][y])) return 0; // if there are any numbers left on board, return 0 (not full)
        }
    }
    return 1; // return 1 if the board is full
}

int winner(){
    for(int i = 0; i < 3; i++){
        //check rows
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) return currentPlayer;

        //check columns
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) return currentPlayer;
    }
    //check diagonals
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) return currentPlayer;
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return currentPlayer;

    return 0; // return 0 if nobody has won yet
}

int main(){
    drawBoard();
    cout << "\n" << endl;
    currentMarker = 'X';
    currentPlayer = 1;
    editBoard(1);
    editBoard(2);
    editBoard(3);
    drawBoard();
    cout << "\n" << endl;

    cout << winner() << endl;
    cout << full() << endl;
    return 0;
}