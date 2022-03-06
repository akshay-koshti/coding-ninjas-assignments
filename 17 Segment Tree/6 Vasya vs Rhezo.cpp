/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/

#include <bits/stdc++.h>
using namespace std;
#define L (2*current+1)
#define R (2*current+2)

void build_tree(vector<int> &a, vector<int> &b, vector<int> &tree, int start, int end, int current){
if(start == end){
tree[current] = start;
return;
}
int mid = (start+end)/2;
build_tree(a, b, tree, start, mid, L);
build_tree(a, b, tree, mid+1, end, R);
int l = tree[L], r = tree[R];
if(a[l] > a[r]) tree[current] = l;
else if(a[r] > a[l]) tree[current] = r;
else{
if(b[l] < b[r]) tree[current] = l;
else if(b[r] < b[l]) tree[current] = r;
else tree[current] = min(l, r);
}}

int find(vector<int> &a, vector<int> &b, vector<int> &tree, int start, int end, int current, int left, int right){
if(start > right || left > end) return INT_MAX;
if(left <= start && end <= right){
return tree[current];
}
int mid = (start+end)/2;
int l = find(a, b, tree, start, mid, L, left, right);
int r = find(a, b, tree, mid+1, end, R, left, right);
if(l == INT_MAX || r == INT_MAX) return min(l, r);
if(a[l] > a[r]) return l;
else if(a[r] > a[l]) return r;
else{
if(b[l] < b[r]) return l;
else if(b[r] < b[l]) return r;
else return min(l, r);
}}

int main(){
int n, q;
cin >> n;
vector<int> a(n), b(n);
for(int i=0; i<n; i++) cin >> a[i];
for(int i=0; i<n; i++) cin >> b[i];
vector<int> tree(4*n);
build_tree(a, b, tree, 0, n-1, 0);
cin >> q;
while(q--){
int x, y;
cin >> x >> y;
cout << 1+find(a, b, tree, 0, n-1, 0, x-1, y-1) << endl;
}
return 0;
}