/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
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
0 1 3
1 2 1
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &edges, int v){
vector<bool> visited(v, false);
vector<int> parent(v), dis(v, 	INT_MAX);
dis[0] = 0;
for(int r=1; r<v; r++){
int min_vertex = -1;
for(int i=0; i<v; i++){
if(!visited[i] && (min_vertex == -1 || dis[i] < dis[min_vertex]))
min_vertex = i;
}
visited[min_vertex] = true;
for(int i=0; i<v; i++){
if(edges[min_vertex][i] && !visited[i] && edges[min_vertex][i] < dis[i]){
dis[i] = edges[min_vertex][i];
parent[i] = min_vertex;
}}}
for(int i=1; i<v; i++){
if(parent[i] <= i)
cout << parent[i] << " " << i << " " << dis[i] << endl;
else
cout << i << " " << parent[i] << " " << dis[i] << endl;
}}

int main(){
int v, e;
cin >> v >> e;
vector<vector<int>> edges(v, vector<int>(v));
for(int i=0; i<e; i++){
int v1, v2, w;
cin >> v1 >> v2 >> w;
if(edges[v1][v2]){
if(edges[v1][v2] > w)
edges[v1][v2] = w, edges[v2][v1] = w;
}else{
edges[v1][v2] = w, edges[v2][v1] = w;
}}
solve(edges, v);
return 0;
}