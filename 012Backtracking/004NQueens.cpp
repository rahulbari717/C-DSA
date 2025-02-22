/*
Question: place N queens in NxN chessboard such that no 2 queen can attack each other
N = 4; 
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printBoard (vector<vector<char>> board){
    int n = board.size();

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){

    int n = board.size();
    // check for horizotal 
    for (int j=0; j<n; j++){
        if (board[row][j] == 'Q'){
            return false;
        }
    }

    // check for vertical
    for (int i=0; i<row; i++){
        if (board[i][col] == 'Q'){
            return false;
        }
    }

    // check for left diagonal
    for (int i=row, j=col; i>=0 && j>=0; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    // check for right diagonal
    for (int i=row, j=col; i>=0 && j<n; i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if (row == n){
        printBoard(board);
        return 1;
    }

    int count = 0;

    for (int j=0; j<n; j++){    // cols
    // check if queen is safe
        if (isSafe(board, row, j)){
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
    return count;               // no. of possible ways to place N queens
}

int main (){
    vector<vector<char>> board;
    int n = 4;
    cout << "size of board: " << n << endl;

    for (int i=0; i<n; i++){
        vector<char> newRow;
        for (int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }


    int count = nQueens(board, 0);
    cout << "Total number of ways to place N queens: " << count << endl;
    // printBoard(board);
    return 0;
}
