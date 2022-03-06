/*
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
*/

#include <bits/stdc++.h>
using namespace std;
#define max 2000001

vector<int> sieve(max);

void make_sieve()
{
	for(int i=0; i<max; i++)
		sieve[i] = i;
	for(int i=2; i*i<max; i++)
	{
		if(sieve[i] == i)
			for(int j=i*i; j<max; j+=i)
				if(sieve[j] > i)
					sieve[j] = i;
	}
}

void solve(int n)
{
	vector<bool> visited(n+1);
	vector<int> ans(n);
	int k = 0;
	for(int i=n; i>=1; i--)
	{
		if(!visited[i])
		{
			vector<int> temp;
			visited[i] = true;
			temp.push_back(i);
			int x = i;
			while(x != 1)
			{
				for(int j=i-sieve[i]; j>=1; j-=sieve[i])
					if(!visited[j])
					{
						visited[j] = true;
						temp.push_back(j);
					}
				while(x%sieve[i] == 0)
					x /= sieve[i];
				sieve[i] = sieve[x];
			}
			sort(temp.begin(), temp.end(), greater<int>());
			for(int j=0; j<temp.size(); j++)
				ans[k++] = temp[j];
		}
	}
	for(auto x:ans)
		cout << x << " ";
}

int main()
{
	int n;
	cin >> n;
	make_sieve();
	solve(n);
	return 0;
}