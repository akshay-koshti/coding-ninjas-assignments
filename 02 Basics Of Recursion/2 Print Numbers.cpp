/*
The task is to print all numbers from 1 to n using recursion.

Input
4
Output
1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

void print(int n){
if(n == 1){
cout << n << " ";
}
else{
print(n - 1);
cout << n << " ";
}}

int main(){
int n;
cin >> n;
print(n);
return 0;
}