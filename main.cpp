#include<iostream>
using namespace std;
//initial board representation, negative for black pieces, positive for white pieces, 0 for empty squares
int board[8][8]={
    {-6,-5,-4,-3,-2,-4,-5,-6},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {6,5,4,3,2,4,5,6},
};
//function to convert piece representation to character for printing
void pieceToChar(int x){
    switch (x){
        case 0:
        cout << ". ";
        break;
        case 1:
        cout << "P ";
        break;
        case -1:
        cout << "p ";
        break;
        case 2:
        cout << "K ";
        break;
        case -2:
        cout << "k ";
        break;
        case 3:
        cout << "Q ";
        break;
        case -3:
        cout << "q ";
        break;
        case 4:
        cout << "B ";
        break;
        case -4:
        cout << "b ";
        break;
        case 5:
        cout << "N ";
        break;
        case -5:
        cout << "n ";
        break;
        case 6:
        cout << "R ";
        break;
        case -6:
        cout << "r ";
        break;
        default:
        cout << "try again";
        break;
    }
}
//function to print the board
void board_print(){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            pieceToChar(board[i][j]);
    }
    cout << "\n";
    }
}
//structure to represent a move, with starting and ending coordinates
struct move{
    int x1,y1,x2,y2;
};
//main function to test the board printing
int main()
{
    board_print();
}
