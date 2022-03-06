/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <bits/stdc++.h>
using namespace std;

//this can be done using bfs and dfs
//here disjoint sets are used

int find_set(vector<int> &disjoint_sets, int target){
while(target != disjoint_sets[target])
target = disjoint_sets[target];
return target;
}

string check(vector<pair<int, int>> &edges, int v, int e, int source, int sink){
vector<int> disjoint_sets(v);
for(int i=0; i<v; i++) disjoint_sets[i] = i;
for(int i=0; i<e; i++){
int first = find_set(disjoint_sets, edges[i].first);
int second = find_set(disjoint_sets, edges[i].second);
disjoint_sets[second] = first;
first = find_set(disjoint_sets, source);
second = find_set(disjoint_sets, sink);
if(first == second) return "true";
}
return "false";
}

int main(){
int v, e, source, sink;
cin >> v >> e;
vector<pair<int, int>> edges(e, make_pair(0, 0));
for(int i=0; i<e; i++)
cin >> edges[i].first >> edges[i].second;
cin >> source >> sink;
cout << check(edges, v, e, source, sink);
return 0;
}