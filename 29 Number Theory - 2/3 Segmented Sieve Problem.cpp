/*
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/

//note vectors are slower than arrays
//endl is slower than \n
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define max 2147483647

vector<bool> sieve;
vector<long long> primes;

void make_sieve(long long n)
{
	sieve = vector<bool>(n+1, true);
	sieve[0] = sieve[1] = false;
	for(long long i=2; i*i<=n; i++)
	{
		if(sieve[i])
		{
			for(long long j=i*i; j<=n; j+=i)
				sieve[j] = false;
		}
	}
	for(long long i=2; i<=n; i++)
		if(sieve[i])
			primes.push_back(i);
}

void solve(long long l, long long r)
{
	 int size = r-l+1;
	 bool is_prime[size];
	 for(int i=0; i<size; i++)
		 is_prime[i] = true;
	long long start;
	for(int k=0; k<primes.size(); k++)
	{
		int x = primes[k];
		if(x*x > r)
			break;
		start = (l/x)*x;
		if(start < l)
			start += x;
		long long j = start;
		for(; start<=r; start+=x)
			is_prime[start-l] = false;
		if(j == x)
			is_prime[j-l] = true;
	}
	for(long long i=0; i<size; i++)
		if(is_prime[i])
			printf("%lld\n", i+l);
}

int main()
{
	long long T, l, r;
	make_sieve(sqrt(max));
	cin >> T;
	while(T--)
	{
		cin >> l >> r;
		solve(l, r);
	}
	return 0;
}