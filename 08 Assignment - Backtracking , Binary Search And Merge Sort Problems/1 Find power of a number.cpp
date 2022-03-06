#include <bits/stdc++.h>
using namespace std;

int ans(int x, int n){
if(n == 0) return 1;
return x*ans(x, n-1);
}

int main(){
int x, n;
cin >> x >> n;
cout << ans(x, n);
return 0;
}