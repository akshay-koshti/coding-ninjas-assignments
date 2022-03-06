#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++)
cin >> a[i];

int min=INT_MAX, profit=0;
for(int i=0; i<n; i++){
if(min > a[i]) min = a[i];
else if(a[i]-min > profit) profit = a[i]-min;
}
cout << profit;
return 0;
}