/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include <bits/stdc++.h>
using namespace std;

int left_length(int **a, int i, int j){
int ans=0;
for(int x=j-1; x>=0; x--){
if(a[i][x] == 1) return ans;
else if(a[i][x] == 0) ++ans;
}
return ans;
}

int upper_length(int **a, int i, int j){
int ans=0;
for(int x=i-1; x>=0; x--){
if(a[x][j] == 1) return ans;
else if(a[x][j] == 0) ++ans;
}
return ans;
}

int findMaxSquareWithAllZeros(int** a, int row, int col){
vector<vector<int>> helper(row, vector<int>(col));
for(int j=0; j<col; j++)
if(a[0][j] == 1) helper[0][j] = 0;
else helper[0][j] = 1;
for(int i=0; i<row; i++)
if(a[i][0] == 1) helper[i][0] = 0;
else helper[i][0] = 1;
for(int i=1; i<row; i++){
for(int j=1; j<col; j++){
if(a[i][j] == 1){
helper[i][j] = 0;
}
else{
int left=left_length(a, i, j);
int upper=upper_length(a, i, j);
helper[i][j] = min(helper[i-1][j-1], min(left, upper))+1;
}}}
int ans=-1;
for(int i=0; i<row; i++){
for(int j=0; j<col; j++){
ans = max(ans, helper[i][j]);
}}
return ans;
}

int main(){

return 0;
}