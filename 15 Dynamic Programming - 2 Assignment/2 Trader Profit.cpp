/*
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format
The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Constraints
1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000
Output Format
For each query print the maximum profit earned by Mike on a new line. 
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0
*/

#include <bits/stdc++.h>
using namespace std;

int *a, dp[50][20][2];

int solve(int *a, int n, int k, int status){
if(n == 0 || k == 0) return 0;
if(dp[n][k][status] != -1) return dp[n][k][status];
int sum = 0;
if(status == 1){
int option1 = sum + a[0] + solve(a+1, n-1, k-1, status^1);
int option2 = sum + solve(a+1, n-1, k, status);
dp[n][k][status] = max(option1, option2);
return dp[n][k][status];
}else{
int option1 = sum - a[0] + solve(a+1, n-1, k, status^1);
int option2 = sum + solve(a+1, n-1, k, status);
dp[n][k][status] = max(option1, option2);
return dp[n][k][status];
}}

int main(){
ifstream fin("input.txt");
int T;
fin >> T;
while(T--){
int k, n;
fin >> k >> n;
a = new int[n];
for(int i=0; i<n; i++) fin >> a[i];
memset(dp, -1, sizeof(dp));
cout << solve(a, n, k, 0) << endl;
delete[] a;
}
fin.close();
return 0;
}