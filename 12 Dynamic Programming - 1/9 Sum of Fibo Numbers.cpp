#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int count = 0;

int fibo(int n)
{
    count++;
    if (dp[n] != 0)
        return dp[n];
    if (n == 0)
    {
        dp[n] = 1;
        return 1;
    }
    if (n == 1)
    {
        dp[n] = 1;
        return 1;
    }
    int temp = fibo(n - 1) + fibo(n - 2);
    dp[n] = temp;
    return temp;
}

int main()
{
    int n;
    cin >> n;
    dp = vector<int>(n + 1, 0);
    cout << fibo(n) << endl;
    cout << count << endl;
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    return 0;
}