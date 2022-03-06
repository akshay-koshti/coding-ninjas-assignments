/*
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
vector<int> a;
map<int, pair<bool, int>> m;
for(int i=0; i<n; i++)
m.insert(make_pair(arr[i], make_pair(true, i)));
int start=0, max=0, len1=0, len2=0;
for(int i=0; i<n; i++){
if(m[arr[i]].first == true){
len1 = len2 = 0;
for(int j=1; m.count(arr[i]+j)==1; j++)
len1++, m[arr[i]+j].first = false;
for(int j=1; m.count(arr[i]-j)==1; j++)
len2++, m[arr[i]-j].first = false;
if(len1+len2 > max) max = len1+len2, start = m[arr[i]-len2].second;
else if(len1+len2 == max && start > m[arr[i]-len2].second) start = m[arr[i]-len2].second;
/*
we can do better by making a variable num=arr[i];
so that we can make our code simple
for forward dirrection: ++num
and for backward dirrection: --num
no need to use len1 and len2
*/
}}
a.push_back(arr[start]);
for(int j=1; m.count(arr[start]+j)==1; j++)
a.push_back(arr[start]+j);
return a;
}

int main(){
int n;
cin >> n;
int *arr=new int[n];
for(int i=0; i<n; i++) cin >> arr[i];
vector<int> v=longestConsecutiveIncreasingSequence(arr, n);
for(auto x:v) cout << x << endl;
delete[] arr;
return 0;
}