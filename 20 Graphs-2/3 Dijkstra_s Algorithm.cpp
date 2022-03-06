/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &edges, int v){
vector<int> visited(v), dis(v, INT_MAX);
dis[0] = 0;
for(int round=1; round<v; round++){
int min_v, min_dis = INT_MAX;
for(int i=0; i<v; i++){
if(!visited[i] && dis[i] < min_dis)
min_v = i, min_dis = dis[i];
}
if(min_dis == INT_MAX)	
break;
visited[min_v] = 1;
for(int j=0; j<v; j++){
if(edges[min_v][j]){
if(!visited[j] && dis[min_v]+edges[min_v][j] < dis[j])
dis[j] = dis[min_v]+edges[min_v][j];
}}}
for(int i=0; i<v; i++)
cout << i << " " << dis[i] << endl;
}

int main(){
int v, e;
cin >> v >> e;
vector<vector<int>> edges(v, vector<int>(v));
for(int i=0; i<e; i++){
int v1, v2, w;
cin >> v1 >> v2 >> w;
if(edges[v1][v2] != 0 && edges[v1][v2] > w)
edges[v1][v2] = w, edges[v2][v1] = w;
else
edges[v1][v2] = w, edges[v2][v1] = w;
}
solve(edges, v);
return 0;
}