/*
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8
*/

#include <bits/stdc++.h>
using namespace std;

int turnOffFirstSetBit(int n){
for(int i=0; i<32; i++){
if(n&(1<<i)){
return (n&(~(1<<i)));
}}}


int main(){
int n;
cin >> n;
cout << turnOffFirstSetBit(n);
return 0;
}