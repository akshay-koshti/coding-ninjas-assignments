/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#include <bits/stdc++.h>
using namespace std;

long nowCount(int n, int *a){
if(n == 0) return 1;
if(n == 1) return 1;
if(a[n] > 0) return a[n];
long count=0;
for(int i=1; i<=n; i++){
count = (count + nowCount(i-1, a) * nowCount(n-i, a))%1000000007;
}
a[n] = count;
return count;
}

int countBST(int n){
int a[n+1];
a[0] = 1, a[1] = 1;
for(int i=2; i<=n; i++) a[i] = 0;
return nowCount(n, a);
}

int main(){
int n;
cin >> n;
cout << countBST(n);
return 0;
}