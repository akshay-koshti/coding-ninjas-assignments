#include <iostream>
using namespace std;

int lis(long long int *input, int n)
{
    int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        dp[i] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i])
                dp[i] = max(dp[i], 1 + dp[j]);
            else
                dp[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    delete[] dp;
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    int *output = new int[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        long long int *input = new long long int[n];
        for (int i = 0; i < n; i++)
            cin >> input[i];
        output[i] = lis(input, n);
        delete[] input;
    }
    for (int i = 0; i < t; i++)
        cout << output[i] << endl;
    delete[] output;
    return 0;
}