#include <bits/stdc++.h>
#include <thread>         
#include <chrono>
#define N 4
using namespace std;

void visual(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 

bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false;
    for (i = 0; i < row; i++) 
        if (board[i][col]) 
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
bool nqueen(int board[N][N], int row) 
{ 
    if (row >= N) 
        return true; 
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, row, i)) { 
            system("clear");
            visual(board);
            this_thread::sleep_for (std::chrono::seconds(1));
            board[row][i] = 1; 
            if (nqueen(board, row + 1)) 
                return true; 
            system("clear");
            visual(board);
            this_thread::sleep_for (std::chrono::seconds(1));
            board[row][i] = 0; 
        } 
    } 
  
    return false; 
} 

int main(){
    int board[N][N];
    memset(board,0,sizeof(board));
    nqueen(board,0);
    system("clear");
    visual(board);
}