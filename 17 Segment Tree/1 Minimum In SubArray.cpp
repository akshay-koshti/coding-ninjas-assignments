/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
2
1
*/

#include <bits/stdc++.h>
using namespace std;

void bild_tree(vector<int> &a, vector<int> &tree, int start, int end, int node){
if(start == end){
tree[node] = a[start];
return;
}
int mid = (start+end)/2;
bild_tree(a, tree, start, mid, 2*node);
bild_tree(a, tree, mid+1, end, 2*node+1);
tree[node] = min(tree[2*node], tree[2*node+1]);
}

int find_min(vector<int> &tree, int start, int end, int node, int left, int right){
if(start > right || end < left)
return INT_MAX;
if(left <= start && end <= right)
return tree[node];
int mid = (start+end)/2;
int ans1 = find_min(tree, start, mid, 2*node, left, right);
int ans2 = find_min(tree, mid+1, end, 2*node+1, left, right);
return min(ans1, ans2);
}

void update(vector<int> &a, vector<int> &tree, int start, int end, int node, int index, int value){
if(start == end){
a[index] = value;
tree[node] = value;
return;
}
int mid = (start+end)/2;
if(index > mid)
update(a, tree, mid+1, end, 2*node+1, index, value);
else
update(a, tree, start, mid, 2*node, index, value);
tree[node] = min(tree[2*node], tree[2*node+1]);
}

int main(){
int n, q;
cin >> n >> q;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
vector<int> tree(4*n);
bild_tree(a, tree, 0, n-1, 1);
while(q--){
int x, y;
char c;
cin >> c >> x >>y;
if(c == 'q'){
int ans = find_min(tree, 0, n-1, 1, x-1, y-1);
cout << ans << endl;
}
else if(c == 'u')
update(a, tree, 0, n-1, 1, x-1, y);
}
return 0;
}