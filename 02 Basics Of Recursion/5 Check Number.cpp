/*
The task is to search an element in an array by recursion.
Print true if present, otherwise print false.

Input
3
1 3 4
4
Output
true
*/

#include <bits/stdc++.h>
using namespace std;

bool checkNumber(int input[], int n, int x){
if(n == 0) return false;
if(input[n-1] == x) return true;
else return checkNumber(input, n-1, x);
}

int main(){
int n, s;
cin >> n;
int *a=new int[n];
for(int i=0; i<n; i++) cin >> a[i];
cin >> s;
cout << checkNumber(a, n, s);
delete[] a;
return 0;
}