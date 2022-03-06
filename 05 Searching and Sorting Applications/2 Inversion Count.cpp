/*
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli merge(int *a, lli p, lli q, lli r){
lli i=p, j=q+1, k=0, count=0;
lli *temp=new lli[r-p+1];
while(i <= q && j <= r){
if(a[i] <= a[j]) temp[k++] = a[i++];
else temp[k++] = a[j++], count += q+1-i;
}
while(i <= q) temp[k++] = a[i++];
while(j <= r) temp[k++] = a[j++];
for(i=r; i>=p; i--)
a[i] = temp[--k];
delete[] temp;
return count;
}

lli merge_sort(int *a, lli p, lli r){
lli count=0;
if(p < r){
lli q=(p+r)/2;
count += merge_sort(a, p, q);
count += merge_sort(a, q+1, r);
count += merge(a, p, q, r);
}
return count;
}

lli solve(int a[], lli n){
return merge_sort(a, 0, n-1);
}

int main(){
lli n;
cin >> n;
lli *a=new long long[n];
for(lli i=0; i<n; i++) cin >> a[i];
cout << solve(a, n);
delete[] a;
return 0;
}