/*
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include <bits/stdc++.h>
using namespace std;

bool is_valid(int board[][9], int num, int i, int j){
for(int k=0; k<9; k++)
if(board[i][k] == num) return false;
for(int k=0; k<9; k++)
if(board[k][j] == num) return false;
int m=i/3, n=j/3;
for(int x=3*m; x<3*m+3; x++)
for(int y=3*n; y<3*n+3; y++)
if(board[x][y] == num) return false;
return true;
}

bool sudokuSolver(int board[][9]){
for(int i=0; i<9; i++){
for(int j=0; j<9; j++){
if(board[i][j] == 0){
for(int k=1; k<=9; k++){
if(is_valid(board, k, i, j)){
board[i][j] = k;
bool ans=sudokuSolver(board);
if(ans) return true;
else board[i][j] = 0;
}}
if(board[i][j] == 0) return false;
}}}
return true;
}

int main(){
int board[9][9];
for(int i=0; i<9; i++)
for(int j=0; j<9; j++)
cin >> board[i][j];
cout << sudokuSolver(board);
return 0;
}