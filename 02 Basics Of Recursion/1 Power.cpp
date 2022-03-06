/*
The task is to find the power of an intiger (x^n) by recursion.

Input
3 4
Output
81
*/

#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
if(n == 0) return 1;
return x*power(x, n-1);
}

int main(){
int a, b;
cin >> a >> b;
cout << power(a, b);
return 0;
}