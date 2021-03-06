/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b){
if(a[2] < b[2]) return true;
return false;
}

int find_set(vector<int> &ds, int t){
while(t != ds[t])
t = ds[t];
return t;
}

void solve(vector<vector<int>> &edges, int v, int e){
sort(edges.begin(), edges.end(), comp);
vector<int> ds(v);
for(int i=0; i<v; i++) ds[i] = i;
for(int i=0; i<e; i++){
int first = find_set(ds, edges[i][0]);
int second = find_set(ds, edges[i][1]);
if(first != second){
ds[second] = first;
sort(edges[i].begin(), --(edges[i].end()));
cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
}}}

int main(){
int v, e;
cin >> v >> e;
vector<vector<int>> edges(e, vector<int>(3));
for(int i=0; i<e; i++)
cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
solve(edges, v, e);
return 0;
}