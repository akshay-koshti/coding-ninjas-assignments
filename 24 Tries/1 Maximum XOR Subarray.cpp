/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *child[2];
};

node* create_node()
{
	node *temp = new node;
	temp->value = 0;
	temp->child[0] = temp->child[1] = NULL;
	return temp;
}

void insert_node(node *root, int value)
{
	for(int i=31; i>=0; i--)
	{
		bool bit = value&(1<<i);
		if(root->child[bit] == NULL) root->child[bit] = create_node();
		root = root->child[bit];
	}
	root->value = value;
}

int query(node *root, int value)
{
	for(int i=31; i>=0; i--)
	{
		bool bit = value&(1<<i);
		if(root->child[1-bit] != NULL) root = root->child[1-bit];
		else if(root->child[bit] != NULL) root = root->child[bit];
	}
	return root->value^value;
}

int solve(vector<int> &a, int n)
{
	int result = INT_MIN, xor_value = 0;
	node *root = create_node();
	insert_node(root, 0);
	for(int i=0; i<n; i++)
	{
		xor_value = xor_value^a[i];
		insert_node(root, xor_value);
		result = max(result, query(root, xor_value));
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	cout << solve(a, n);
	return 0;
}