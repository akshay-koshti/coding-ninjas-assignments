/*
The task is to find the friquency of characters 'a', 's' and 'p' in a given string.

Input
5
asaas
Output
3 2 0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
string s;
cin >> n >> s;
vector<int> hash(150);
for(auto x:s)
hash[x]++;
cout << hash['a'] << " " << hash['s'] << " " << hash['p'];
return 0;
}