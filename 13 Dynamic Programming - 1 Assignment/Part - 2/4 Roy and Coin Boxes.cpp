/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> counts;

void solve(vector<pair<int, int>> &a){
int sum=0, n=a.size();
for(int i=1; i<n; i++){
sum += a[i].first;
counts[sum]++;
sum -= a[i].second;
}
for(int i=n-2; i>0; i--)
counts[i] += counts[i+1];
}

int main(){
int n, d, q;
cin >> n >> d;
counts = vector<int>(n+1);
vector<pair<int, int>> a(n+1, pair<int, int>{0, 0});
for(int i=0; i<d; i++){
int x, y;
cin >> x >> y;
++a[x].first;
++a[y].second;
}
solve(a);
cin >> q;
while(q--){
int day_num;
cin >> day_num;
cout << counts[day_num] << endl;
}
return 0;
}