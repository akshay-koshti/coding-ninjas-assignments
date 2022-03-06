/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <bits/stdc++.h>
using namespace std;

string bfs(vector<vector<int>> &a, int v){
vector<int> visited(v);
queue<int> q;
q.push(0);
while(!q.empty()){
int front = q.front();
q.pop();
if(visited[front])
continue;
visited[front] = 1;
for(int i=0; i<v; i++){
if(a[front][i] && visited[i] == 0)
q.push(i);
}}
for(int i=0; i<v; i++)
if(visited[i] == 0) return "false";
return "true";
}

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
cout << bfs(a, v);
return 0;
}