/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int *a, int n){
vector<int> left(n, 1), right(n, 1);
for(int i=1; i<n; i++){
for(int j=0; j<i; j++){
if(a[j] < a[i] && left[i] < left[j]+1)
left[i] = left[j]+1;
}}
for(int i=n-2; i>=0; i--){
for(int j=i+1; j<n; j++){
if(a[j] < a[i] && right[i] < right[j]+1)
right[i] = right[j]+1;
}}
int ans=left[0]+right[0]-1;
for(int i=1; i<n; i++){
if(left[i]+right[i]-1 > ans) ans = left[i]+right[i]-1;
}
return ans;
}

int main(){
ifstream fin("input.txt");
int n;
fin >> n;
int *a=new int[n];
for(int i=0; i<n; i++) fin >> a[i];
cout << longestBitonicSubarray(a, n);
delete[] a;
fin.close();
return 0;
}