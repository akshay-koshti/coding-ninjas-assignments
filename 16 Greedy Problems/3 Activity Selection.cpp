/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.
Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include <bits/stdc++.h>
using namespace std;

int comprater(pair<int, int> a, pair<int, int> b){
if(a.second <= b.second) return 1;
return 0;
}

int solve(vector< pair<int, int> > &a){
int n = a.size();
sort(a.begin(), a.end(), comprater);
int count = 0, end = -1;
for(int i=0; i<n; i++){
if(a[i].first >= end){
++count;
end = a[i].second;
}}
return count;
}

int main(){
int n;
cin >> n;
vector< pair<int, int> > a(n);
for(int i=0; i<n; i++)
cin >> a[i].first >> a[i].second;
cout << solve(a);
return 0;
}