/*
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <bits/stdc++.h>
using namespace std;
#include <cstdio>
#define max 10000

char* uniqueChar(char *str){
int k=0;
vector<bool> h(130, false);
for(int i=0; str[i]!='\0'; i++){
int idx=str[i];
if(!h[idx]) str[k++] = str[i];
h[idx] = true;
}
str[k] = '\0';
return str;
}

int main(){
char str[max];
scanf("%s", str);
cout << uniqueChar(str);
return 0;
}