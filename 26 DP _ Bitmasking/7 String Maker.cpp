/*
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C
Constraints :
1 <= |A|, |B|, |C| <= 50
Sample Input :
abc
abc 
abc
Sample Output :
8
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

vector<vector<vector<int>>> dp;

long long helper(string a, string b, string c)
{
	int l1 = a.length(), l2 = b.length(), l3 = c.length();
	if(l3 == 0)
		return 1;
	if(l1 == 0 && l2 == 0)
		return 0;
	if(dp[l1][l2][l3] != -1)
		return dp[l1][l2][l3];
	long long ans = 0;
	for(int i=0; i<l1; i++)
	{
		if(a[i] == c[0])
			ans = (ans+helper(a.substr(i+1), b, c.substr(1)))%mod;
	}
	for(int i=0; i<l2; i++)
	{
		if(b[i] == c[0])
			ans = (ans+helper(a, b.substr(i+1), c.substr(1)))%mod;
	}
	dp[l1][l2][l3] = ans;
	return ans;
}

long long solve(string a, string b, string c)
{
	dp = vector<vector<vector<int>>>(a.size()+1, vector<vector<int>>(b.size()+1, vector<int>(c.size()+1, -1)));
	return helper(a, b, c);
}

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c);
	return 0;
}