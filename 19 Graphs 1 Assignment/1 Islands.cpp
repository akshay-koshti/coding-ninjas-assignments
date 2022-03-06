/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

#include <bits/stdc++.h>
using namespace std;

int find_set(vector<int> &ds, int v){
while( v != ds[v])
v = ds[v];
return v;
}

int solve(int n, int m, vector<int> &u, vector<int> &v){
vector<int> ds(n);
for(int i=0; i<n; i++) ds[i] = i;
int count = n;
for(int i=0; i<m; i++){
int first = find_set(ds, u[i]-1);
int second = find_set(ds, v[i]-1);
if(first != second){
ds[second] = first;
count--;
}}
return count;
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