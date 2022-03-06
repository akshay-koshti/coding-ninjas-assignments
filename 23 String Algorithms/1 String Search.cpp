/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :
Line 1 : String S
Line 2 : String T
Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/

#include <bits/stdc++.h>
using namespace std;

int findString(char s[], char t[]) {
	int lenp=strlen(t);
	int* lps= new int [lenp];
	lps[0]=0;
	int j=0;
	int i=1;
	while(i<lenp)
	{
		if(t[i]==t[j])
		{
			lps[i]=j+1;
			j++;
			i++;
		}else{
			if(j!=0)
			{
				j=lps[j-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
	int lent=strlen(s);
	i=0;
	j=0;
	int p=0;
	while(i<lent && j<lenp)
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}else{
			if(j!=0){
				j=lps[j-1];
			}else{
				i++;
			  p=i;  
			}
		}
	}
	  if(j==lenp)
		{
			return p;
		}
	return -1;
}
