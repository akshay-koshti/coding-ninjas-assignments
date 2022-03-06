/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>
using namespace std;

int cadaine(vector<int> &a){
int max_till_now=INT_MIN, max_ending_here=0;
for(int i=0; i<a.size(); i++){
max_ending_here = max(a[i], a[i]+max_ending_here);
max_till_now = max(max_till_now, max_ending_here);
}
return max_till_now;
}

int max_rectangle(vector<vector<int>> &a, int m, int n){
int ans=INT_MIN;
for(int i=0; i<n; i++){
vector<int> cadaine_array(m);
for(int j=i; j<n; j++){
for(int k=0; k<m; k++){
cadaine_array[k] += a[k][j];
}
int temp=cadaine(cadaine_array);
ans = max(temp, ans);
}}
return ans;
}

int main(){
int m, n;
cin >> m >> n;
vector<vector<int>> a(m, vector<int>(n));
for(int i=0; i<m; i++)
for(int j=0; j<n; j++)
cin >> a[i][j];
cout << max_rectangle(a, m, n);
return 0;
}