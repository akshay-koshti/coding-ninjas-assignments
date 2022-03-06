/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

#include <bits/stdc++.h>
using namespace std;
#include <cstring>

long long countPalindromeSubstrings(char *s){
int n = strlen(s), count = n;
for(int i=0; i<n; i++){
int l = i-1, r = i+1;
while(l >= 0 && r < n && s[l] == s[r]) --l, ++r, ++count;
}
for(int i=0; i<n-1; i++){
if(s[i] == s[i+1]){
++count;
int l = i-1, r = i+2;
while(l >= 0 && r < n && s[l] == s[r]) --l, ++r, ++count;
}}
return count;
}

int main(){
char s[100];
cin >> s;
cout << countPalindromeSubstrings(s);
return 0;
}