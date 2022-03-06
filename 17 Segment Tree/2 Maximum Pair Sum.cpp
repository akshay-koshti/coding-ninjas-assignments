/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include <bits/stdc++.h>
using namespace std;

void build_tree(vector<int> &a, vector<pair<int, int>> &tree, int start, int end, int current_node){
if(start == end){
tree[current_node].first = a[start];
tree[current_node].second = INT_MIN;
return;
}
int mid = (start+end)/2;
build_tree(a, tree, start, mid, 2*current_node);
build_tree(a, tree, mid+1, end, 2*current_node+1);
tree[current_node].first = max(tree[2*current_node].first, tree[2*current_node+1].first);
tree[current_node].second = max(min(tree[2*current_node].first, tree[2*current_node+1].first), max(tree[2*current_node].second, tree[2*current_node+1].second));
}

pair<int, int> find_max(vector<pair<int, int>> &tree, int start, int end, int current_node, int left, int right){
if(start > right || end < left)
return pair<int, int>{INT_MIN, INT_MIN};
if(left <= start && end <= right)
return tree[current_node];
int mid = (start+end)/2;
pair<int, int> ans1 = find_max(tree, start, mid, 2*current_node, left, right);
pair<int, int> ans2 = find_max(tree, mid+1, end, 2*current_node+1, left, right);
pair<int, int> temp;
temp.first = max(ans1.first, ans2.first);
//temp.second = min(max(ans1.first, ans2.second), max(ans1.second, ans2.first));
temp.second = max(min(ans1.first, ans2.first), max(ans1.second, ans2.second));
return temp;
}

void update(vector<int> &a, vector<pair<int, int>> &tree, int start, int end, int current_node, int index, int value){
if(start == end){
a[index] = value;
tree[current_node].first = value;
return;
}
int mid = (start+end)/2;
if(index > mid)
update(a, tree, mid+1, end, 2*current_node+1, index, value);
else
update(a, tree, start, mid, 2*current_node, index, value);
tree[current_node].first = max(tree[2*current_node].first, tree[2*current_node+1].first);
tree[current_node].second = max(min(tree[2*current_node].first, tree[2*current_node+1].first), max(tree[2*current_node].second, tree[2*current_node+1].second));
}

int main(){
int n, q;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
vector<pair<int, int>> tree(3*n);
build_tree(a, tree, 0, n-1, 1);
cin >> q;
while(q--){
int x, y;
char c;
cin >> c >> x >>y;
if(c == 'Q'){
pair<int, int> temp = find_max(tree, 0, n-1, 1, x-1, y-1);
cout << temp.first+temp.second << endl;
}
else
update(a, tree, 0, n-1, 1, x-1, y);
}
return 0;
}