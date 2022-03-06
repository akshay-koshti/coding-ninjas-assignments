/*
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, count = 0;
	cin >> n;
	vector<bool> dp(n+1, true);
	dp[0] = dp[1] = false;
	for(int i=1; i*i<=n; i++)
	{
		if(dp[i])
		{
			for(int j=i*i; j<=n; j+=i)
				dp[j] = false;
		}
	}
	for(int i=1; i<=n; i++)
		if(dp[i]) ++count;
	cout << count;
	return 0;
}