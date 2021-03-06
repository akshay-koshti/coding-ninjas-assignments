/*
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ānā and the player to move divides the number- ānā with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0
*/

#include <bits/stdc++.h>
using namespace std;

int mex(int a, int b, int c)
{
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	for(int i=0; i<max({a, b, c})+2; i++)
		if(s.count(i) == 0)
			return i;
}

int grundy(int n)
{
	if(n <= 0)
		return 0;
	return mex(grundy(n/6), grundy(n/2), grundy(n/3));
}

int main()
{
	int n;
	cin >> n;
	cout << grundy(n) << endl;
	return 0;
}