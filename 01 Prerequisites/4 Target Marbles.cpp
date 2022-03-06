#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
int n, target;
cin >> n >> target;
vector<int> a(n);
for(int i=0; i<n; i++)
cin >> a[i];

int max=0;
list<int> ans;
for(int i=0; i<n; i++){
if(max+a[i] <= target) max += a[i], ans.push_back(a[i]);
else if(max+a[i] > target){
if(a[i] <= target){
while(max+a[i] > target){
max -= ans.front();
ans.pop_front();
}
max += a[i];
ans.push_back(a[i]);
}
else max = 0, ans.clear();
}
if(max == target){
cout << "true\n";
for(int j:ans)
cout << j << " ";
return 0;
}}
cout << "false";
return 0;
}