/*
The task is to find the first occurance of the element x in the input array by recursion.
First occurance means first hit when searching from 0th to n-1th.
If the element is not present print -1.

Input
4
9 8 9 10
9
Output
0
*/

#include <bits/stdc++.h>
using namespace std;

int firstIndex(int input[], int size, int x) {
if(size == 0) return -1;
if(input[0] == x) return 0;
int idx=firstIndex(input+1, size-1, x);
if(idx == -1) return idx;
else return idx+1;
}

int main(){
int n, s;
cin >> n;
int *a=new int[n];
for(int i=0; i<n; i++) cin >> a[i];
cin >> s;
cout << firstIndex(a, n, s);
delete[] a;
return 0;
}