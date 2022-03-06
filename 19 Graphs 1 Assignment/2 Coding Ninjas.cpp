/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> visited;

bool find(char graph[][102], char *a, int n, int m, int i, int j){
if(i < 0 || i > n-1 || j < 0 || j > m-1)
return false;
if(a[0] == '\0')
return true;
if(graph[i][j] != a[0])
return false;
if(visited[i][j])
return false;
visited[i][j] = 1;
if(find(graph, a+1, n, m, i-1, j-1)) return true;
if(find(graph, a+1, n, m, i-1, j)) return true;
if(find(graph, a+1, n, m, i-1, j+1)) return true;
if(find(graph, a+1, n, m, i, j-1)) return true;
if(find(graph, a+1, n, m, i, j+1)) return true;
if(find(graph, a+1, n, m, i+1, j-1)) return true;
if(find(graph, a+1, n, m, i+1, j)) return true;
if(find(graph, a+1, n, m, i+1, j+1)) return true;
}

int solve(char graph[][102], int n, int m){
char a[] = "CODINGNINJA";
for(int i=0; i<n; i++){
for(int j=0; j<m; j++){
if(graph[i][j] == 'C'){
visited = vector<vector<int>>(n, vector<int>(m));
bool ans = find(graph, a, n, m, i, j);
if(ans) return ans;
}}}
return 0;
}

int main(){
char graph[102][102];
int n, m;
cin >> n >> m;
for(int i=0; i<n; i++)
cin >> graph[i];
cout << solve(graph, n, m);
return 0;
}