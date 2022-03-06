/*
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.
Input Format:
First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)
Output Format:
Print a single integer denoting the window number that Aahad will get ticket from.
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3.
*/

#include <bits/stdc++.h>
using namespace std;

/*
it is working on a maths formula
i + t*n >= a[i];
it is the base and core logic for solving this problem
note that we can also solve this question by the complexity on O(n)
try to make logic as follows
for(int i=0; i<n; i++){
t = (a[i]-i)/n;
if a[i]-i == 0
then there will be no change in t
other wise t = t+1
since we want the rround number
and intiger division will give 5.6 as 5
but we want maximum of
i + t*n >= a[i];
}
*/

int TajMahal(vector<int> &a, int n){
vector<int> t_value(n);
for(int i=0; i<n; i++){
int left=0, right=1000000000, mid;
while(left <= right){
mid = (left+right)/2;
if((i+mid*n) >= a[i]){
t_value[i] = (i+mid*n);
right = mid-1;
}
else left = mid+1;
}}
int min=0;
for(int i=1; i<n; i++)
if(t_value[min] > t_value[i]) min = i;
return min+1;
}

int main(){
int n;
cin >> n;
vector<int> a(n);
for(int i=0; i<n; i++) cin >> a[i];
cout << TajMahal(a, n);
return 0;
}