/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
int sum, max_sum, best_prefix_sum, best_suffix_sum;
};

void build_tree(vector<int> &a, vector<node> &tree, int start, int end, int current){
if(start == end){
tree[current].sum = a[start];
tree[current].max_sum = a[start];
tree[current].best_prefix_sum = a[start];
tree[current].best_suffix_sum = a[start];
return ;
}
int mid = (start+end)/2;
build_tree(a, tree, start, mid, 2*current);
build_tree(a, tree, mid+1, end, 2*current+1);
tree[current].sum = tree[2*current].sum + tree[2*current+1].sum;
tree[current].best_prefix_sum = max(tree[2*current].best_prefix_sum, tree[2*current].sum+tree[2*current+1].best_prefix_sum);
tree[current].best_suffix_sum = max(tree[2*current+1].best_suffix_sum, tree[2*current].best_suffix_sum+tree[2*current+1].sum);
tree[current].max_sum = max({tree[2*current].max_sum, tree[2*current+1].max_sum, tree[2*current].best_suffix_sum+tree[2*current+1].best_prefix_sum});
}

node find_max(vector<node> &tree, int start, int end, int current, int left, int right){
node temp;
temp.sum = 0;
temp.max_sum = -15000;
temp.best_prefix_sum = -15000;
temp.best_suffix_sum = -15000;
if(start > right || left > end){
return temp;
}
if(left <= start && end <= right){
return tree[current];
}
int mid = (start+end)/2;
node l = find_max(tree, start, mid, 2*current, left, right);
node r = find_max(tree, mid+1, end, 2*current+1, left, right);
temp.sum = l.sum + r.sum;
temp.best_prefix_sum = max(l.best_prefix_sum, l.sum+r.best_prefix_sum);
temp.best_suffix_sum = max(r.best_suffix_sum, r.sum+l.best_suffix_sum);
temp.max_sum = max({l.max_sum, r.max_sum, l.best_suffix_sum+r.best_prefix_sum});
return temp;
}

int main(){
int n, q;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
vector<node> tree(4*n);
build_tree(a, tree, 0, n-1, 1);
cin >> q;
while(q--){
int x, y;
cin >> x >> y;
node temp = find_max(tree, 0, n-1, 1, x-1, y-1);
cout << temp.max_sum << endl;
}
return 0;
}