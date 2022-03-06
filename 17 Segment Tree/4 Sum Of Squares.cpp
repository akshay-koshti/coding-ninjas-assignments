/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/

#include <bits/stdc++.h>
using namespace std;
#define L (2*current+1)
#define R (2*current+2)

class node{
public:
int64_t squares_sum, sum;
};

class lazy_node{
public:
int type, value;
};

void build_tree(vector<int> &a, vector<node> &tree, int start, int end, int current){
if(start == end){
tree[current].squares_sum = a[start]*a[start];
tree[current].sum = a[start];
return;
}
int mid = (start+end)/2;
build_tree(a, tree, start, mid, L);
build_tree(a, tree, mid+1, end, R);
node l = tree[L], r = tree[R];
tree[current].squares_sum = l.squares_sum+r.squares_sum;
tree[current].sum = l.sum+r.sum;
}

void lazy_propagation(vector<node> &tree, vector<lazy_node> &lazy, int start, int end, int current){
if(lazy[current].type != -1){
if(lazy[current].type == 0){
tree[current].squares_sum = (end-start+1)*lazy[current].value*lazy[current].value;
tree[current].sum = (end-start+1)*lazy[current].value;
}else if(lazy[current].type == 1){
tree[current].squares_sum += (end-start+1)*lazy[current].value*lazy[current].value + 2*tree[current].sum*lazy[current].value;
tree[current].sum += (end-start+1)*lazy[current].value;
}
if(start < end){
if(lazy[L].type != 0)
lazy[L].type = lazy[current].type;
if(lazy[R].type != 0)
lazy[R].type = lazy[current].type;
if(lazy[current].type == 0){
lazy[L].value = lazy[current].value;
lazy[R].value = lazy[current].value;
}else if(lazy[current].type == 1){
lazy[L].value += lazy[current].value;
lazy[R].value += lazy[current].value;
}}}
lazy[current].type = -1, lazy[current].value = 0;
}

node find(vector<node> &tree, vector<lazy_node> &lazy, int start, int end, int current, int left, int right){
lazy_propagation(tree, lazy, start, end, current);
if(start > right || end < left){
node temp;
temp.squares_sum = 0;
temp.sum = 0;
return temp;
}
if(left <= start && end <= right){
return tree[current];
}
int mid = (start+end)/2;
node l = find(tree, lazy, start, mid, L, left, right);
node r = find(tree, lazy, mid+1, end, R, left, right);
node result;
result.squares_sum = l.squares_sum+r.squares_sum;
result.sum = l.sum+r.sum;
return result;
}

void update(vector<node> &tree, vector<lazy_node> &lazy, int start, int end, int current, int type, int left, int right, int value){
lazy_propagation(tree, lazy, start, end, current);
if(start > right || left > end) return;
if(left <= start && end <= right){
lazy[current].type = type;
lazy[current].value = value;
lazy_propagation(tree, lazy, start, end, current);
return;
}
int mid = (start+end)/2;
update(tree, lazy, start, mid, L, type, left, right, value);
update(tree, lazy, mid+1, end, R, type, left, right, value);
tree[current].squares_sum = tree[L].squares_sum + tree[R].squares_sum;
tree[current].sum = tree[L].sum + tree[R].sum;
}

int main(){
int T;
cin >> T;
for(int itr=1; itr<=T; itr++){
int n, q;
cin >> n >> q;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
vector<node> tree(4*n);
build_tree(a, tree, 0, n-1, 0);
lazy_node temp;
temp.type = -1, temp.value = 0;
vector<lazy_node> lazy(4*n, temp);
cout << "Case " << itr << ":\n";
while(q--){
int type, i, j, value;
cin >> type >> i >> j;
if(type == 2){
node ans = find(tree, lazy, 0, n-1, 0, i-1, j-1);
cout << ans.squares_sum << endl;
}else{
cin >> value;
update(tree, lazy, 0, n-1, 0, type, i-1, j-1, value);
}}}
return 0;
}