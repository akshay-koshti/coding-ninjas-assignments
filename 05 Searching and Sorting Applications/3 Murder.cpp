/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli merge(lli *a, lli p, lli q, lli r){
lli i=p, j=q+1, k=0, count=0;
lli *temp=new lli[r-p+1];
while(i <= q && j <= r){
if(a[i] < a[j]) temp[k++] = a[i++], count += (a[i-1]*(r-j+1));
else temp[k++] = a[j++];
}
while(i <= q) temp[k++] = a[i++];
while(j <= r) temp[k++] = a[j++];
for(i=r; i>=p; i--)
a[i] = temp[--k];
delete[] temp;
return count;
}

lli merge_sort(lli *a, lli p, lli r){
lli count=0;
if(p < r){
lli q=(p+r)/2;
count += merge_sort(a, p, q);
count += merge_sort(a, q+1, r);
count += merge(a, p, q, r);
}
return count;
}

lli solve(lli a[], lli n){
return merge_sort(a, 0, n-1);
}

int main(){
int T;
cin >> T;
while(T--){
lli n;
cin >> n;
lli *a=new long long[n];
for(lli i=0; i<n; i++) cin >> a[i];
cout << solve(a, n) << endl;;
delete[] a;
}
return 0;
}