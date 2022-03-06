/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/

#include <bits/stdc++.h>
using namespace std;
#define L (2*current+1)
#define R (2*current+2)

void lazy_propagation(vector<int64_t> &tree, vector<int64_t> &lazy, int64_t start, int64_t end, int64_t current){
tree[current] += (end-start+1)*lazy[current];
if(start < end){
lazy[L] += lazy[current];
lazy[R] += lazy[current];
}
lazy[current] = 0;
}

void update(vector<int64_t> &tree, vector<int64_t> &lazy, int64_t start, int64_t end, int64_t current, int64_t left, int64_t right, int64_t value){
lazy_propagation(tree, lazy, start, end, current);
if(start > right || left > end)
return;
if(left <= start && end <= right){
lazy[current] = value;
lazy_propagation(tree, lazy, start, end, current);
return;
}
int64_t mid = (start+end)/2;
update(tree, lazy, start, mid, L, left, right, value);
update(tree, lazy, mid+1, end, R, left, right, value);
tree[current] = tree[L]+tree[R];
}

int64_t find(vector<int64_t> &tree, vector<int64_t> &lazy, int64_t start, int64_t end, int64_t current, int64_t left, int64_t right){
lazy_propagation(tree, lazy, start, end, current);
if(start > right || left > end){
return 0;
}
if(left <= start && end <= right){
return tree[current];
}
int64_t mid = (start+end)/2;
int64_t l = find(tree, lazy, start, mid, L, left, right);
int64_t r = find(tree, lazy, mid+1, end, R, left, right);
return l+r;
}

int main(){
int64_t T;
cin >> T;
while(T--){
int64_t n, q;
cin >> n >> q;
vector<int64_t> tree(4*n);
vector<int64_t> lazy(4*n);
while(q--){
int64_t type, x, y, value;
cin >> type >> x >> y;
if(type == 0){
cin >> value;
update(tree, lazy, 0, n-1, 0, x-1, y-1, value);
}else{
cout << find(tree, lazy, 0, n-1, 0, x-1, y-1) << endl;
}}}
return 0;
}
