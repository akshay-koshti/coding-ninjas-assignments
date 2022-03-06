/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bit(30001);

void insert(int r, int n)
{
	for(; r<=n; r += (r&(-r)))
		bit[r]++;
}

int query(int l)
{
	int ans = 0;
	for(; l>0; l -= (l&(-l)))
		ans += bit[l];
	return ans;
}

int main()
{
	int n, q;
	cin >> n;
	vector<pair<int, int>> a;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin >> x;
		a.push_back(make_pair(x, i));
	}
	sort(a.begin(), a.end());
	vector<pair<pair<int, int>, pair<int, int>>> queries;
	cin >> q;
	for(int i=1; i<=q; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		queries.push_back({{k, i}, {l, r}});
	}
	sort(queries.begin(), queries.end(), greater<pair<pair<int, int>, pair<int, int>>>());
	vector<int> ans(200002);
	for(pair<pair<int, int>, pair<int, int>> each:queries)
	{
		int k = each.first.first;
		int i = each.first.second;
		int l = each.second.first;
		int r = each.second.second;
		int j = a.size()-1;
		while(j >= 0)
		{
			if(a[j].first > k)
			{
				insert(a[j].second, n);
				a.pop_back();
			}
			else
				break;
			--j;
		}
		int temp = query(r) - query(l-1);
		ans[i] = temp;
	}
	for(int i=1; i<=queries.size(); i++)
		cout << ans[i] << "\n";
	//"\n" is much faster than endl
	//if we use endl than our test case may get failed due to time out
	return 0;
}