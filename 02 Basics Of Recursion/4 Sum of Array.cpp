/*
The task is to find the sum of an array by recursion.

Input
4
2 3 4 5
Output
14
*/

#include <bits/stdc++.h>
using namespace std;

int sum(int *a, int n){
if(n == 1) return a[0];
return a[n-1]+sum(a, n-1);
}

int main(){
int n;
cin >> n;
int *a=new int[n];
for(int i=0; i<n; i++) cin >> a[i];
cout << sum(a, n);
delete[] a;
return 0;
}