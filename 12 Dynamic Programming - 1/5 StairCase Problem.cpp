/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/

#include <bits/stdc++.h>
using namespace std;

//iterative solution
long staircase(int n){
vector<long> a(n+1);
a[0] = a[1] = 1;
a[2] = 2;
for(int i=3; i<=n; i++)
a[i] = a[i-1] + a[i-2] + a[i-3];
return a[n];
}

/*
vector<long> a;

long moves(int n){
if(n == 0) return 1;
if(n == 1) return 1;
if(n == 2) return 2;
if(a[n] > 0) return a[n];
a[n] = moves(n-1) + moves(n-2) + moves(n-3) + 3;
return a[n];
}

long staircase(int n){
a = vector<long>(n+1);
return moves(n);
}
//this recursive solution needs to be debugged 
//it is a little bit wrong
*/

int main(){
int n;
cin >> n;
cout << staircase(n);
return 0;
}