/*
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(1000005);
vector<vector<int>> dp(1000005, vector<int>(11));

void make_sieve()
{
	for(int i=2; i<=1000000; i++)
	{
		if(sieve[i] == 0)
		{
			for(int j=i; j<=1000000; j+=i)
				++sieve[j];
		}
	}
	for(int i=1; i<=1000000; i++)
	{
		for(int j=0; j<=10; j++)
		{
			if(sieve[i] == j)
				dp[i][j] = 1+dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
}

int main()
{
	make_sieve();
	int T;
	cin >> T;
	while(T--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		cout << dp[b][n]-dp[a-1][n] << endl;
	}
	return 0;
}