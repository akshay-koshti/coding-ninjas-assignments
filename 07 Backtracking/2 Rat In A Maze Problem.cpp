/*
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

void help_rat(int maze[][20], int n, int I, int J){
if(I == n-1 && J == n-1){
v[n-1][n-1]++;
for(int i=0; i<n; i++)
for(int j=0; j<n; j++)
cout << v[i][j] << " ";
cout << endl;
v[n-1][n-1]--;
return;
}
if(maze[I][J] == 0 || v[I][J]) return;
v[I][J] = 1;
if(I > 0) help_rat(maze, n, I-1, J);
if(J > 0) help_rat(maze, n, I, J-1);
if(J+1 < n) help_rat(maze, n, I, J+1);
if(I+1 < n) help_rat(maze, n, I+1, J);
v[I][J] = 0;
}

void ratInAMaze(int maze[][20], int n){
v = vector<vector<int>>(n, vector<int>(n));
help_rat(maze, n, 0, 0);
}

int main(){
int n; 
cin >> n ;
int maze[20][20];
for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
	cin >> maze[i][j];
}		
}
ratInAMaze(maze, n);
return 0;
}