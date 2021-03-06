/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include <bits/stdc++.h>
using namespace std;
#define L (2*current+1)
#define R (2*current+2)

int power[100001];

void build_power(){
power[0] = 1;
for(int i=1; i<100001; i++)
power[i] = (2*power[i-1])%3;
}

void build_tree(vector<int> &a, vector<int> &tree, int start, int end, int current){
if(start == end){
tree[current] = a[start];
return;
}
int mid = (start+end)/2;
build_tree(a, tree, start, mid, L);
build_tree(a, tree, mid+1, end, R);
tree[current] = (power[end-mid]*tree[L] + tree[R])%3;
}

int find(vector<int> &tree, int start, int end, int current, int left, int right){
if(start > right || left > end)
return 0;
if(left <= start && end <= right)
return (tree[current]*power[right-end])%3;
int mid = (start+end)/2;
int l = find(tree, start, mid, L, left, right);
int r = find(tree, mid+1, end, R, left, right);
return (l+r)%3;
}

void update(vector<int> &a, vector<int> &tree, int start, int end, int current, int index){
if(start == end){
a[index] = 1;
tree[current] = 1;
return;
}
int mid = (start+end)/2;
if(start <= index && index <= mid)
update(a, tree, start, mid, L, index);
else
update(a, tree, mid+1, end, R, index);
tree[current] = (power[end-mid]*tree[L]+tree[R])%3;
}

int main(){
build_power();
int n, q;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++){
char ch;
cin >> ch;
a[i] = (ch-'0');
}
vector<int> tree(4*n);
build_tree(a, tree, 0, n-1, 0);
cin >> q;
while(q--){
int type, x, y;
cin >> type;
if(type == 0){
cin >> x >> y;
cout << find(tree, 0, n-1, 0, x, y) << endl;
}else{
cin >> x;
if(a[x] == 0)
update(a, tree, 0, n-1, 0, x);
}}
return 0;
}