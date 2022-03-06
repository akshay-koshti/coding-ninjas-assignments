/*
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements in a single line (separated by space)
Constraints :
0 <= N <= 10^7
0 <= d <= N
Sample Input 1:
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
*/

#include <iostream>
using namespace std;

void Rotate(int arr[], int d, int n){
d %= n;
int *temp=new int[d];
for(int i=0; i<d; i++) temp[i] = arr[i];
for(int i=d; i<n; i++) arr[i-d] = arr[i];
for(int j=0, i=n-d; i<n; i++) arr[i] = temp[j++];
delete[] temp;
}

int main(){
int n, x;
cin >> n;
int *arr=new int[n];
for(int i=0; i<n; i++)
cin >> arr[i];
cin >> x;
//call the Rotate and print the array
delete[] arr;
return 0;
}