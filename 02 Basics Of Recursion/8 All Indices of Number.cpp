/*
The task is to print all the indices of an input array where the element x is present, do this by recursion.
Return only the size of the output array and insert all the demanded indices in the output array.

Input
4
9 8 10 8
8
Output
1, 3
*/

#include <bits/stdc++.h>
using namespace std;

int val=0;
int allIndexes(int input[], int size, int x, int output[]){
if(size == 0) return 0;
int ans=0;
if(input[0] == x) output[ans++] = val;
++val;
ans += allIndexes(input+1, size-1, x, output+ans);
return ans;
}

int main(){
int n, s;
cin >> n;
int *a=new int[n], *b=new int[n];
for(int i=0; i<n; i++) cin >> a[i];
cin >> s;
int size=allIndexes(a, n, s, b);
for(int i=0; i<size; i++)
cout << b[i] << " ";
delete[] a;
delete[] b;
return 0;
}