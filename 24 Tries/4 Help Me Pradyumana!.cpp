/*
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	bool end;
	node *path[26];
};

node* create()
{
	node *temp = new node;
	temp->end = false;
	for(int i=0; i<26; i++) temp->path[i] = NULL;
	return temp;
}

void insert(node *root, string &s, int start)
{
	if(start == s.length()) return;
	if(root->path[s[start]-'a'] == NULL) root->path[s[start]-'a'] = create();
	root = root->path[s[start]-'a'];
	if(start == s.length()-1) root->end = true;
	insert(root, s, start+1);
}

void dfs(node *root, string &s, string helper)
{
	if(root->end)
	{
		cout << s << helper << endl;
	}
	for(int i=0; i<26; i++)
	{
		if(root->path[i] != NULL)
		{
			dfs(root->path[i], s, helper+char(i+'a'));
		}
	}
}

void print(node *root, string &s)
{
	node *temp_root = root;
	for(int i=0; i<s.length(); i++)
	{
		if(root->path[s[i]-'a'] == NULL)
		{
			cout << "No suggestions\n";
			insert(temp_root, s, 0);
			return;
		}
		root = root->path[s[i]-'a'];
	}
	dfs(root, s, "");
}

int main()
{
	int n, q;
	cin >> n;
	node *root = create();
	string s;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		insert(root, s, 0);
	}
	cin >> q;
	while(q--)
	{
		cin >> s;
		print(root, s);
	}
	return 0;
}