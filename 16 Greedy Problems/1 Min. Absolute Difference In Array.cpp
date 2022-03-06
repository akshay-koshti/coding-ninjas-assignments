/*
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constraints :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Output :
1
*/

#include <climits>
#include <algorithm>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {
sort(arr, arr+n);
int minimum=INT_MAX;
for(int i=1; i<n; i++)
minimum = min(minimum, arr[i] - arr[i-1]);
return minimum;
}