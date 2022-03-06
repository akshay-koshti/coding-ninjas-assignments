/*
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
int len1=s1.length(), len2=s2.length();
vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));
for(int i=0; i<=len1; i++)
dp[i][0] = 0;
for(int j=0; j<=len2; j++)
dp[0][j] = 0;
for(int i=1; i<=len1; i++){
for(int j=1; j<=len2; j++){
if(s1[len1-i] == s2[len2-j]){
dp[i][j] = 1+dp[i-1][j-1];
}else{
dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}}}
return dp[len1][len2];
}

int main(){
string s1, s2;
cin >> s1 >> s2;
cout << lcs(s1, s2);
return 0;
}