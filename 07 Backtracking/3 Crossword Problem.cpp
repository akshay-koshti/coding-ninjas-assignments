/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

//this code is perfect and error free
//but requires code cleaning
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> a(10, vector<char>(10));
vector<string> words;

bool check_vertical(string word, int i, int j){
if(10-i < word.length()) return false;
for(int x=i, k=0; k<word.length(); x++, k++)
if(a[x][j] != '-' && a[x][j] != word[k]) return false;
return true;
}

bool check_horizontal(string word, int i, int j){
if(10-j < word.length()) return false;
for(int x=j, k=0; k<word.length(); x++, k++)
if(a[i][x] != '-' && a[i][x] != word[k]) return false;
return true;
}

void set_vertical(string word, int i, int j, bool* helper){
for(int x=i, k=0; k<word.length(); x++, k++){
if(a[x][j] == '-') {helper[x] = true;
a[x][j] = word[k];}
    else
        helper[x]=false;
}}

void set_horizontal(string word, int i, int j, bool* helper){
for(int x=j, k=0; k<word.length(); x++, k++){
if(a[i][x] == '-') {helper[x] = true;
a[i][x] = word[k];}
    else
        helper[x]=false;
}}

void reset_vertical(string word, int i, int j, bool* helper){
for(int x=i, k=0; k<word.length(); x++, k++){
if(helper[k]){
a[x][j] = '-';
//helper[k] = false;
}}}

void reset_horizontal(string word, int i, int j, bool* helper){
for(int x=j, k=0; k<word.length(); x++, k++){
if(helper[k]){
a[i][x] = '-';
//helper[k] = false;
}}}

bool solve(int index){
if(index == words.size()){
return true;
//cout << endl;
}
//return true;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        if(a[i][j] == '-' || a[i][j] == words[index][0]){
            if(check_vertical(words[index], i, j)){
                bool helper[words[index].size()];
                set_vertical(words[index], i, j, helper);
                bool ans=solve(index+1);
if(ans) return true;
reset_vertical(words[index], i, j, helper);
}
if(check_horizontal(words[index], i, j)){
bool helper[words[index].size()];
set_horizontal(words[index], i, j, helper);
bool ans=solve(index+1);
if(ans) return true;
reset_horizontal(words[index], i, j, helper);
}}}}
//return false;
}

int main(){
for(int i=0; i<10; i++)
{for(int j=0; j<10; j++)
{cin >> a[i][j];}}
string s, word="";
cin >> s;
for(int i=0; i<s.length(); i++)
{if(s[i] == ';'){
words.push_back(word);
word = "";
}
else word += s[i];}
words.push_back(word);

solve(0);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
cout << a[i][j];}
        //cout<<endl;
    cout<<"\n";}
return 0;
}