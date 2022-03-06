#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin >> n;
vector<vector<int>> a(n, vector<int>(n));
for(int i=0; i<n; i++)
for(int j=0; j<n; j++)
cin >> a[i][j];

int sum=0;
for(int i=1; i<n-1; i++)
sum += a[0][i] + a[i][0] + a[i][n-1] + a[n-1][i];
for(int i=0; i<n/2; i++)
sum += a[i][i] + a[i][n-1-i] + a[n-1-i][i] + a[n-1-i][n-1-i];
if(n&1) sum += a[n/2][n/2];
cout << sum;
return 0;
}