/*
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<int> &u, vector<int> &v){
int count = 0;
vector<vector<int>> a(n, vector<int>(n));
for(int i=0; i<m; i++){
a[u[i]-1][v[i]-1] = 1;
a[v[i]-1][u[i]-1] = 1;
}
for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
if(a[i][j]){
for(int k=0; k<n; k++){
if(a[j][k] && k != i && k != j && a[i][k]) ++count;
}}}}
return count/6;
}

int main(){
int n, m;
cin >> n >> m;
vector<int> u(m), v(m);
for(int i=0; i<m; i++) cin >> u[i];
for(int i=0; i<m; i++) cin >> v[i];
cout << solve(n, m, u, v);
return 0;
}