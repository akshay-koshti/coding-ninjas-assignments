/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(long long n)
{
	long long ans = 1, mod = 1000000007;
	vector<bool> sieve(n+1, true);
	sieve[0] = sieve[1] = false;
	for(int i=2; i*i<=n; i++)
	{
		if(sieve[i])
		{
			for(int j=i*i; j<=n; j+=i)
				sieve[j] = false;
		}
	}
	for(int i=2; i<=n; i++)
	{
		if(sieve[i])
		{
			long long sum = 0;
			for(int j=1; pow(i, j)<=n; j++)
			{
				sum += n/pow(i, j);
			}
			ans = (ans * (++sum)%mod)%mod;
		}
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}