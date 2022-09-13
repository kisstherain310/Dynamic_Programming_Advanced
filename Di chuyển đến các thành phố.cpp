#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
ll mod = 1e9 + 7;
 
int main (){
    faster();
    ll n;
    cin >> n;
    ll arr[n + 5][n + 5] = {};
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) 
            cin >> arr[i][j];
    ll dp[20][33000] = {};
    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= (1 << n); j++) 
            dp[i][j] = 1e9;
    for(ll i = 0; i < n; i++)
        dp[i][1 << i] = 0;
    for(ll mask = 0; mask < (1 << n); mask++){
        for(ll i = 0; i < n; i++){
            if(dp[i][mask] < 1e9)
                for(ll j = 0; j < n; j++){
                    if((mask & (1 << j)) == 0)
                        dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + arr[i][j]);
                }
        }
    }
    ll kq = 1e9;
    for(ll i = 0; i < n; i++) 
        kq = min(kq, dp[i][(1 << n) - 1]);
    cout << kq;
}