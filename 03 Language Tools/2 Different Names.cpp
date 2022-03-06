/*
In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
*/

#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define max 100005

int main(){
char s[max];
s[0] = ' ';
gets(s+1);
int len=strlen(s);
map<string, int> m;
queue<string> a;
for(int i=len-1; i>=0; i--){
while(s[i] != ' ') --i;
s[i] = '\0';
string str=(s+i+1);
m[str]++;
a.push(str);
}
int status=0;
while(!a.empty()){
string x=a.front();
a.pop();
if(m[x] > 1){
cout << x << " " << m[x] << endl;
status = 1;
m[x] = 1;
}}
if(!status) cout << -1;
return 0;
}