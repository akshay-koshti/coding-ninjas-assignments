/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

bool subSetSum(vector<int> &a, int n, int w){
vector<vector<bool>> dp(2, vector<bool>(w+1));
dp[0][0] = true;
int flag = 1;
for(int i=1; i<=n; i++){
for(int j=1; j<=w; j++){
if(a[i-1] <= j){
dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-a[i-1]];
}}
flag = flag^1;
}
return dp[flag][w];
}

int main(){
int n, sum;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
cin >> sum;
int ans = subSetSum(a, n, sum);
if(ans) cout << "Yes" << endl;
else cout << "No" << endl;
return 0;
}