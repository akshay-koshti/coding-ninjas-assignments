/*
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S
and the two type of queries
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x
Input Format
Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
Output
For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
Input Format
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2
Output Format
1
2
2
invalid
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> queries;
vector<int> bit(200001);
vector<int> a;
unordered_map<int, int> m;

void insert(int index, int value, int n)
{
	if(index > n)
		return;
	bit[index] += value;
	insert(index+(index&(-index)), value, n);
}

int query(int value)
{
	int ans = 0;
	for(; value>0; value -= (value&(-value)))
		ans += bit[value];
	return ans;
}

int search(int value)
{
	int l = 0, r = a.size()-1, mid, ans = a.size();
	while(l <= r)
	{
		mid = (l+r)/2;
		if(query(m[a[mid]]) >= value)
		{
			ans = mid;
			r = mid-1;
		}
		else
			l = mid+1;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		char c;
		int x;
		cin >> c >> x;
		queries.push_back(make_pair(c, x));
		m[x] = 1;
	}
	for(auto x:m)
		a.push_back(x.first);
	sort(a.begin(), a.end());
	for(int i=0; i<a.size(); i++)
		m[a[i]] = 1+i;
	for(int i=0; i<n; i++)
	{
		if(queries[i].first == 'I')
		{
			if(query(m[queries[i].second]) == query(m[queries[i].second]-1))
				insert(m[queries[i].second], 1, a.size());
		}
		else if(queries[i].first == 'D')
		{
			if(query(m[queries[i].second]) != query(m[queries[i].second]-1))
				insert(m[queries[i].second], -1, a.size());
		}
		else if(queries[i].first == 'K')
		{
			int k = search(queries[i].second);
			if(k == a.size())
				cout << "invalid\n";
			else
				cout << a[k] << endl;
		}
		else
		{
			int index = lower_bound(a.begin(), a.end(), queries[i].second)-a.begin();
			--index;
			if(index < 0)
				cout << 0 << endl;
			else
				cout << query(m[a[index]]) << endl;
		}
	}
	return 0;
}