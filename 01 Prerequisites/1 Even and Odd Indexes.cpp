#include <bits/stdc++.h>
using namespace std;

int main(){
int n, even=0, odd=0;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++)
cin >> a[i];
for(int i=0; i<n; i++)
if((!(a[i]&1)) && (!(i&1))) even += a[i];
else if((a[i]&1) && (i&1)) odd += a[i];
cout << even << " " << odd;
return 0;
}