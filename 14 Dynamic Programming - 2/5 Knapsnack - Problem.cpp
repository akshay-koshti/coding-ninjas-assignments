/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int *weight, int *value, int n, int w){
vector<int> uper(w+1), lower(w+1);
for(int i=0; i<=n; i++){
for(int j=0; j<=w; j++){
if(i == 0 || j == 0){
lower[j] = 0;
}else if(weight[i-1] <= j){
lower[j] = max(value[i-1]+uper[j-weight[i-1]], uper[j]);
}else{
lower[j] = uper[j];
}}
uper = lower;
}
return lower[w];
}

int main(){
int n, w;
cin >> n;
int *weight=new int[n], *value=new int[n];
for(int i=0; i<n; i++) cin >> weight[i];
for(int i=0; i<n; i++) cin >> value[i];
cin >> w;
cout << knapsack(weight, value, n, w);
delete[] weight;
delete[] value;
return 0;
}