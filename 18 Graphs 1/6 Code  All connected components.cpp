/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

void bfs(vector<vector<int>> &a, int v, int source){
queue<int> q;
q.push(source);
vector<int> ans;
while(!q.empty()){
int front = q.front();
q.pop();
if(visited[front])
continue;
ans.push_back(front);
visited[front] = 1;
for(int i=0; i<v; i++){
if(a[front][i] && visited[i] == 0)
q.push(i);
}}
sort(ans.begin(), ans.end());
for(auto x:ans)
cout << x << " ";
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
visited = vector<int>(v);
for(int i=0; i<v; i++){
if(visited[i] == 0){
bfs(a, v, i);
cout << endl;
}}
return 0;
}