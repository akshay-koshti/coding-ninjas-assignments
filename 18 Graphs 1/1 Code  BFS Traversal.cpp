/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &a, int v){
vector<int> visited(v);
queue<int> q;
q.push(0);
while(!q.empty()){
int front = q.front();
q.pop();
if(visited[front])
continue;
cout << front << " ";
visited[front] = 1;
for(int i=0; i<v; i++){
if(a[front][i] && visited[i] == 0)
q.push(i);
}
if(q.empty()){
for(int i=0; i<v; i++){
if(visited[i] == 0){
q.push(i);
break;
}}}}}

int main(){
int v, e;
cin >> v >> e;
vector<vector<int>> a(v, vector<int>(v));
for(int i=0; i<e; i++){
int x, y;
cin >> x >>y;
a[x][y] = 1;
a[y][x] = 1;
}
bfs(a, v);
return 0;
}