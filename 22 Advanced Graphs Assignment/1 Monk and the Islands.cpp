/*
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &graph, int n){
vector<int> visited(n);
vector<int> dp(n);
queue<int> q;
q.push(0);
while(!q.empty()){
int front = q.front();
q.pop();
for(int i=0; i<graph[front].size(); i++){
if(!visited[graph[front][i]]){
visited[graph[front][i]] = 1;
q.push(graph[front][i]);
dp[graph[front][i]] = dp[front]+1;
if(graph[front][i] == n-1)
return dp[n-1];
}}}
return dp[n-1];
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
graph[y-1].push_back(x-1);
}
cout << solve(graph, n) << endl;
}
return 0;
}