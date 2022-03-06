/*
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.
A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.
Constraints:
1 ≤ N ≤ 20
SAMPLE INPUT
4
SAMPLE OUTPUT
8
Explanation
All the special permutations of length 4 are: 1 2 3 4
1 2 4 3
1 4 2 3
2 1 3 4
2 1 4 3
2 4 1 3
4 1 2 3
4 2 1 3
*/

/*
//in python
l=[1, 2, 2, 8, 16, 48, 48, 384, 1552, 8864, 17728, 140032, 420096, 1680384, 1680384, 26886144, 218259456, 2434287104, 9947008512, 143242828416]
a=int(input())
print(l[a-1])
*/

//int c++
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<ll> submask[22];
bool visited[1<<22];
ll dp[1<<22];
ll n;
ll ans(ll mask) {
    if(mask==(1<<(n+1))-2)
        return 1;
    if(dp[mask]!=-1)
        return dp[mask];
    ll res = 0;
    for(ll i = 1; i<=n; i++) {
        if(!(mask&(1<<i))) {
            bool ok = true;
            for(ll j: submask[i])
                if(!(mask&(1<<j)))
                    ok = false;
            if(ok)
                res+=ans(mask|(1<<i));
        }
    }
    return dp[mask] = res;
}
int main() {
    cin>>n;
    for(ll i = 1; i<=20; i++) {
        for(ll j = i-1; j>=1; j--)
            if((i&j)==j) submask[i].pb(j);
    }
    memset(dp, -1, sizeof(dp));
    cout<<ans(0);
    // cout<<dp;
    return 0;
}