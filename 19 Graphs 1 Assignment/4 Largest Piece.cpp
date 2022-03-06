/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<vector<int>> visited;

int find(char cake[][55], int n, int i, int j){
if(i < 0 || i > n-1 || j < 0 || j > n-1)
return 0;
if(cake[i][j] == '0')
return 0;
if(visited[i][j])
return 0;
visited[i][j] = 1;
int count = 0;
count += find(cake, n, i-1, j);
count += find(cake, n, i, j-1);
count += find(cake, n, i, j+1);
count += find(cake, n, i+1, j);
return 1+count;
}

int solve(int n, char cake[][55]){
visited = vector<vector<int>>(n, vector<int>(n));
int maximum = 0, temp;
for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
if(visited[i][j] == 0 && cake[i][j] == '1'){
temp = find(cake, n, i, j);
maximum = max(maximum, temp);
}}}
return maximum;
}

int main(){
int n;
cin >> n;
char cake[55][55];
for(int i=0; i<n; i++)
scanf("%s", cake[i]);
cout << solve(n, cake);
return 0;
}