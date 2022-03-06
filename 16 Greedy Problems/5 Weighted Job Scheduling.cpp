/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

#include <bits/stdc++.h>
using namespace std;

class job{
public:
long long start, finish, profit;
};

bool comp(job a, job b){
return a.finish<b.finish;
}

long long search(vector<job> &a, long long n, long long start){
long long left = 0, right = n-1, mid, index = -1;
while(left <= right){
mid = (left+right)/2;
if(a[mid].finish <= start){
index = mid;
left = mid+1;
}
else right = mid-1;
}
return index;
}

long long solve(vector<job> &a, long long n){
sort(a.begin(), a.end(), comp);
vector<long long> dp(n);
dp[0] = a[0].profit;
for(long long i=1; i<n; i++){
long long temp = a[i].profit;
int index = search(a, i, a[i].start);
if(index != -1) temp += dp[index];
dp[i] = max(temp, dp[i-1]);
}
return dp[n-1];
}

int main(){
long long n;
cin >> n;
vector<job> a(n);
for(long long i=0; i<n; i++)
cin >> a[i].start >> a[i].finish >> a[i].profit;
cout << solve(a, n);
return 0;
}