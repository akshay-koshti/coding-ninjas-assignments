/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/

#include <bits/stdc++.h>
using namespace std;

//iterative solution
int getMaxMoney(int *a, int n){
vector<int> temp(n);
temp[0] = a[0];
temp[1] = max(a[0], a[1]);
int ans=INT_MIN;
for(int i=2; i<n; i++){
temp[i] = max(temp[i-1], a[i]+temp[i-2]);
}
for(int i=0; i<n; i++)
if(ans < temp[i]) ans = temp[i];
return ans;
}

//recursive solution
//use an array to stre the values
//otherwise it will be having worst time complexity
//use comsept of dynamic programming
/*
int getMaxMoney(int *a, int n){
if(n == 0) return 0;
if(n == 1) return a[0];
if(n == 2) return max(a[0], a[1]);
int sum1=getMaxMoney(a+1, n-1);
int sum2=a[0]+getMaxMoney(a+2, n-2);
return max(sum1, sum2);
}
*/

int main(){
int n;
cin >> n;
int *a=new int[n];
for(int i=0; i<n; i++)
cin >> a[i];
cout << getMaxMoney(a, n);
delete[] a;
return 0;
}