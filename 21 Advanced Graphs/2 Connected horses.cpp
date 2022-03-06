/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

vector<vector<int>> visited;
vector<long long> factorial(1000000);

int find(vector<vector<int>> &board, int n, int m, int i, int j){
if(i < 0 || j < 0 || i >= n || j >= m)
return 0;
if(visited[i][j])
return 0;
if(board[i][j] == 0)
return 0;
visited[i][j] = 1;
int ans = 1;
ans = (ans+find(board, n, m, i-2, j-1))%mod;;
ans = (ans+find(board, n, m, i-2, j+1))%mod;
ans = (ans+find(board, n, m, i-1, j-2))%mod;
ans = (ans+find(board, n, m, i-1, j+2))%mod;
ans = (ans+find(board, n, m, i+1, j-2))%mod;
ans = (ans+find(board, n, m, i+1, j+2))%mod;
ans = (ans+find(board, n, m, i+2, j-1))%mod;
ans = (ans+find(board, n, m, i+2, j+1))%mod;
return ans;
}

int solve(vector<vector<int>> &board, int n, int m){
factorial[1] = 1;
for(int i=2; i<1000000; i++)
factorial[i] = (factorial[i-1]*i)%mod;
visited = vector<vector<int>>(n, vector<int>(m));
long long ans = 1;
for(int i=0; i<n; i++){
for(int j=0; j<m; j++){
if(board[i][j]){
int temp = find(board, n, m, i, j);
if(temp)
ans = (ans*factorial[temp])%mod;
}}}
return ans;
}

int main(){
int T;
cin >> T;
while(T--){
int n, m, q;
cin >> n >> m >> q;
vector<vector<int>> board(n, vector<int>(m));
for(int i=0; i<q; i++){
int x, y;
cin >> x >> y;
board[x-1][y-1] = 1;
}
cout << solve(board, n, m) << endl;
}
return 0;
}