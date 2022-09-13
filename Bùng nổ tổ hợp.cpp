#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
ll mod = 1e9 + 7;
 
ll divide(ll x, ll k){
    if(x == 0) return 0;
    if(k == 0) return 1;
    ll res = x, K = k;
    vector<ll> m; m.push_back(K);
    while(k > 1){
        m.push_back(k / 2);
        k /= 2;
    }
    for(int i = m.size() - 1; i >= 1; i--){
        res = (res * res) % mod;
		if (m[i] * 2 != m[i - 1]) 
		    res = (res * x) % mod;
    }
    return res;
}
 
int main (){
    faster();
    ll t; cin >> t;
    while(t--){
        ll n, k, child = 0;
        cin >> n >> k;
        ll arr[n + 5] = {};
        for(ll i = 1; i <= n; i++) {
            cin >> arr[i]; child += arr[i];
        }
        ll dp[n + 5][k + 5] = {};
        dp[0][0] = 1;
        for(ll i = 0; i <= n; i++){
            for(ll j = 0; j <= k; j++){
                dp[i + 1][j + 1] += dp[i][j] * (k - j) % mod;
                dp[i + 1][j + 1] %= mod;
                dp[i + 1][j] += (j * dp[i][j]) % mod;
                dp[i + 1][j] %= mod;
            }
        }
        ll RES = 0;
        for(ll i = 1; i <= k; i++){
            RES += dp[n][i] * (divide(k - i + 1, child));
            RES %= mod;
        }
        cout << RES << endl;
    }
}