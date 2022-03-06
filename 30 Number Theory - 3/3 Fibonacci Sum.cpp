/*
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857
*/

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

inline void multiply(long long a[2][2], long long b[2][2])
{
	long long ans[2][2] = {{0, 0}, {0, 0}};
	for(long long i=0; i<2; i++)
		for(long long j=0; j<2; j++)
		{
			long long count = 0;
			for(long long k=0; k<2; k++)
				count = (count + ((a[i][k]%mod)*(b[k][j]%mod))%mod)%mod;
			ans[i][j] = count;
		}
	for(long long i=0; i<2; i++)
		for(long long j=0; j<2; j++)
			a[i][j] = ans[i][j];
}

inline void power(long long mat[2][2], long long n)
{
	if(n < 2)
		return;
	power(mat, n/2);
	multiply(mat, mat);
	if(n%2)
	{
		long long temp[2][2] = {{1, 1}, {1, 0}};
		multiply(mat, temp);
	}
}

long long fibo(long long n)
{
	if(n == 0)
		return 0;
	long long mat[2][2] = {{1, 1}, {1, 0}};
	power(mat, n-1);
	return mat[0][0]%mod;
}

long long fiboSum(long long a, long long b)
{return (fibo(b+2)%mod - fibo(a+1)%mod + mod)%mod;
	
}