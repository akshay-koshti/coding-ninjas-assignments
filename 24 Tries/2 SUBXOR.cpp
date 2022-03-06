/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3
*/

#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
struct node {
   long long count=0;
    node *left=0, *right=0;
};
void insert(long long pre, node *tree, long long nb){
    tree->count++;
    for(int i=nb-1;i>=0;i--){
        
        if(pre&(1<<i))
        {
            if(!tree->right){
                node *temp=new node;
              tree->right=temp;
            }
            tree=tree->right;
        }
        else{
            if(!tree->left){
                node *temp=new node;
                tree->left=temp;
            }
            tree=tree->left;
        }
        tree->count++;
    }
 
}
long long query(long long pre, node *tree, long long nb, long long k){
    long long count1=0;
    for(int i=nb-1;i>=0;i--)
    {
        if(pre&(1<<i)){
            if(k&(1<<i)){
                if(tree->right)
                    count1+=tree->right->count;
                    if(tree->left)
                tree=tree->left;
                else{return count1;}
            }
            else{
                    if(tree->right)
                  tree=tree->right;
                   else{
                    return count1;
                   }
                }
            }
            else{
                if(k&(1<<i)){
                        if(tree->left)
                    count1+=tree->left->count;
                    if(tree->right)
                        tree=tree->right;
                    else{return count1;}
                }
                else{
                    if(tree->left)
                    tree=tree->left;
                    else{
                        return count1;
                    }
                }
            }
    }
    return count1;
}
int main() {
long long n, k, t;
    cin>>t;
    while(t){
    int maxn=INT_MIN;
cin>>n>>k;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
   if(arr[i]>maxn)
       maxn=arr[i];
}
        
     if(k>maxn) 
     maxn=k;
    float n1=log(maxn)/log(2);
    int nb=floor(n1)+1;
 
long long pre=0;long long ans=0;
    node tree;
    for(int i=0;i<n;i++){
        pre=pre^arr[i];
        //cout<<pre;
    ans+= query(pre, &tree, nb, k);
        if(pre<k)
            ans++;
        insert(pre, &tree, nb);
 
    }
 
cout<<ans<<endl;
t--;
        tree.left=tree.right=0;tree.count=0;
    }
}