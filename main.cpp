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

int count=0, capacity=5;//global variables for adding elements to move structure
struct move *moves = (struct move*)malloc(capacity*sizeof(struct move));//dynamically allocated memory for move structure

//function for adding a move to the structure
void add_move(int row, int col, int i){
        //move addition
        moves[count].x1= row;
        moves[count].y1= col;
        moves[count].x2= row-i;
        moves[count].y2= col;
        //increment/decrement
        count++;
}

//function to store all the possible moves for a rook moving upwards
void valid_rook_moves_going_upward( int row, int col){
    int x,i=1;
    while (row-i>=0){
        x=board[row][col]*board[row-i][col];
        if (x==0){    //empty square
            if (count == capacity){
                capacity*=2;
                moves= (struct move*)realloc(moves, capacity*sizeof(struct move));//reallocation
                add_move(row, col,i);
                i++;
            }
            else{
                add_move(row, col,i);
                i++;
            }
        }
        else if(x>0){
            break;  //friendly piece
        }
        else{       //enemy piece, capturable
            if (count == capacity){
                capacity*=2;
                moves= (struct move*)realloc(moves, capacity*sizeof(struct move));//reallocation
                add_move( row, col, i);
                break;
            }
            else{
                add_move( row, col,i);
                break;
            }
        }
    }
}

//main function to test the board printing
int main()
{
    board_print();
}
