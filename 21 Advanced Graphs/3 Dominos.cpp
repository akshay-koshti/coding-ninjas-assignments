/*
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

void dfs1(vector<vector<int>> &graph, int start, stack<int> &s){
if(visited[start])
return;
visited[start] = 1;
for(int i=0; i<graph[start].size(); i++){
int next = graph[start][i];
if(!visited[next])
dfs1(graph, next, s);
}
s.push(start);
}

void dfs2(vector<vector<int>> &graph, int start){
if(visited[start])
return;
visited[start] = 1;
for(int i=0; i<graph[start].size(); i++){
int next = graph[start][i];
if(!visited[next])
dfs2(graph, next);
}
}

void kosaraju(vector<vector<int>> &graph, int n){
visited = vector<int>(n);
stack<int> s;
int count = 0;
for(int i=0; i<n; i++){
if(!visited[i])
dfs1(graph, i, s);
}
visited = vector<int>(n);
while(!s.empty()){
int t = s.top();
s.pop();
if(!visited[t]){
++count;
dfs2(graph, t);
}}
cout << count << endl;
}

int main(){
int T;
cin >> T;
while(T--){
int n, m;
cin >> n >> m;
vector<vector<int>> graph(n);
for(int i=0; i<m; i++){
int x, y;
cin >> x >> y;
graph[x-1].push_back(y-1);
}
kosaraju(graph, n);
}
return 0;
}