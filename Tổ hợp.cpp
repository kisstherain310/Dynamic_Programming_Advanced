#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define endl '\n'

ll mod = 1e9 + 7;

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n;
        k = n;
        ll dp[n + 5][n + 5] = {};
        dp[1][1] = 1;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
                dp[i + 1][j] += (j * dp[i][j]) % mod;
                dp[i + 1][j] %= mod;
            }
        }
        ll RES = 0;
        for (ll i = 1; i <= n; i++)
        {
            RES += dp[n][i];
            RES %= mod;
        }
        cout << RES << endl;
    }
}