/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector< vector<int> > dp;

int solve(char *s1, int n1, char *s2, int n2){
if(n1 == 0 || n2 == 0) return n1+n2;
if(dp[n1][n2] > 0) return dp[n1][n2];
int ans;
if(s1[0] == s2[0]){
ans = 1+solve(s1+1, n1-1, s2+1, n2-1);
}else{
int option1 = 1+solve(s1, n1, s2+1, n2-1);
int option2 = 1+solve(s1+1, n1-1, s2, n2);
ans = min(option1, option2);
}
dp[n1][n2] = ans;
return ans;
}

int smallestSuperSequence(char *s1, int n1, char *s2, int n2){
dp = vector< vector<int> >(n1+1, vector<int>(n2+1));
return solve(s1, n1, s2, n2);
}

int main(){
char s1[100], s2[100];
cin >> s1 >> s2;
cout << smallestSuperSequence(s1, strlen(s1), s2, strlen(s2)) << endl;
return 0;
}