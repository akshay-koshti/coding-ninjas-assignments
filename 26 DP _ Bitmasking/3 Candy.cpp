/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/

//note this is not having any main 
//modify accordingly
#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

long long find(int a[][MAXN], int n, int child, int mask)
{
	if(child >= n)
		return 1;
	if(dp[mask])
		return dp[mask];
	long long ans = 0;
	for(int i=0; i<n; i++)
	{
		if(!(mask&(1<<i)) && a[child][i])
		{
			ans += find(a, n, child+1, mask|(1<<i));
		}
	}
	dp[mask] = ans;
	return ans;
}

long long solve(int a[][MAXN], int n)
{
	dp = vector<long long>(1<<n);
	return find(a, n, 0, 0);
}