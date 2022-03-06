/*
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int maximum;
	node *path[26];
};

node* create()
{
	node *temp = new node;
	temp->maximum = 0;
	for(int i=0; i<26; i++) temp->path[i] = NULL;
	return temp;
}

void insert(node *root, string &s, int start, int w)
{
	if(start == s.length()) return;
	if(root->path[s[start]-'a'] == NULL) root->path[s[start]-'a'] = create();
	root = root->path[s[start]-'a'];
	root->maximum = max(root->maximum, w);
	insert(root, s, start+1, w);
}

int query(node *root, string &s)
{
	for(int i=0; i<s.length(); i++)
	{
		if(root->path[s[i]-'a'] == NULL) return -1;
		root = root->path[s[i]-'a'];
	}
	return root->maximum;
}

int main()
{
	node *root = create();
	int n, q;
	cin >> n >> q;
	for(int i=0; i<n; i++)
	{
		string s;
		int w;
		cin >> s >> w;
		insert(root, s, 0, w);
	}
	while(q--)
	{
		string s;
		cin >> s;
		cout << query(root, s) << endl;
		}
	return 0;
}