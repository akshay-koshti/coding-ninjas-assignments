#include <iostream>
using namespace std;

string keyPad[]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int n, string output[]){
if(n == 0 || n == 1){
output[0] = "";
return 1;
}
int smallSize=keypad(n/10, output), dig=n%10-2;
string s=keyPad[dig];
for(int i=1; i<s.length(); i++){
for(int j=0; j<smallSize; j++){
output[j+i*smallSize] = output[j];
}}
for(int j=0; j<s.length(); j++){
for(int i=0; i<smallSize; i++){
output[i+j*smallSize] += s[j];
}}
return smallSize*s.length();
}

int main(){
int n;
cin >> n;
string output[1000];
int size=keypad(n, output);
for(int i=0; i<size; i++)
cout << output[i] << endl;
return 0;
}