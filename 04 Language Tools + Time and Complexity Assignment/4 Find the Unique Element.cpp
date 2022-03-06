/*
Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array
Constraints :
1 <= N <= 10^6
Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1
*/

#include <iostream>
using namespace std;
#include <vector>

int FindUnique(int arr[], int size){
vector<int> h(size+1);
//in their compiler this code was producing error that vector is not decleared in this scope
//so the solution is to use 
//std::vector<int>
for(int i=0; i<size; i++) h[arr[i]]++;
for(int i=1; i<=size; i++) if(h[i] == 1) return i;
}

int main(){
int n;
cin >> n;
int *arr=new int[n];
for(int i=0; i<n; i++) cin >> arr[i];
cout << FindUnique(arr, n);
delete[] arr;
return 0;
}