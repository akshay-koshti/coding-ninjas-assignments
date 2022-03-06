/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include <bits/stdc++.h>
using namespace std;
#define L (2*current+1)
#define R (2*current+2)

struct node{
int n_even, n_odd;
};

void build_tree(vector<int> &a, vector<node> &tree, int start, int end, int current){
if(start == end){
if(a[start]%2 == 0)
tree[current].n_even = 1, tree[current].n_odd = 0;
else
tree[current].n_even = 0, tree[current].n_odd = 1;
return;
}
int mid = (start+end)/2;
build_tree(a, tree, start, mid, L);
build_tree(a, tree, mid+1, end, R);
tree[current].n_even = tree[L].n_even+tree[R].n_even;
tree[current].n_odd = tree[L].n_odd+tree[R].n_odd;
}

node find(vector<node> &tree, int start, int end, int current, int left, int right){
if(start > right || left > end){
node temp;
temp.n_even = 0;
temp.n_odd = 0;
return temp;
}
if(left <= start && end <= right){
return tree[current];
}
int mid = (start+end)/2;
node l = find(tree, start, mid, L, left, right);
node r = find(tree, mid+1, end, R, left, right);
node result;
result.n_even = l.n_even+r.n_even;
result.n_odd = l.n_odd+r.n_odd;
return result;
}

void update(vector<int> &a, vector<node> &tree, int start, int end, int current, int index, int value){
if(start == end){
a[index] = value;
if(value%2 == 0)
tree[current].n_even = 1, tree[current].n_odd = 0;
else
tree[current].n_even = 0, tree[current].n_odd = 1;
return;
}
int mid = (start+end)/2;
if(index > mid)
update(a, tree, mid+1, end, R, index, value);
else update(a, tree, start, mid, L, index, value);
tree[current].n_even = tree[L].n_even+tree[R].n_even;
tree[current].n_odd = tree[L].n_odd+tree[R].n_odd;
}

int main(){
int n, q;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
vector<node> tree(4*n);
build_tree(a, tree, 0, n-1, 0);
cin >> q;
while(q--){
int type, x, y;
cin >> type >> x >> y;
if(type == 0){
update(a, tree, 0, n-1, 0, x-1, y);
}else{
node ans = find(tree, 0, n-1, 0, x-1, y-1);
if(type == 1)
cout << ans.n_even << endl;
else
cout << ans.n_odd << endl;
}}
return 0;
}