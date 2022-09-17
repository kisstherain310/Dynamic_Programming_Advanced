#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("O2")
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
ll mod = 1e9 + 7;
 
int main (){
    faster();
    int t; cin >> t;
    int idx = 1;
    while(t--){
        int n;
        cin >> n;
        int arr[n + 5][n + 5] = {};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) 
                cin >> arr[i][j];
        int dp[66000] = {};
        for(int mask = 0; mask < (1 << n); mask++){
            int dem = 0;
            for(int i = 0; i < n; i++) if((mask & (1 << i)) == 0) dem++;
 
                if(dp[mask] >= 0)
                    for(int j = 0; j < n; j++){
                        if((mask & (1 << j)) == 0)
                            dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] + arr[n - dem][j]);
                    }
        }
        cout << "Case " << idx << ": " << dp[(1 << n) - 1] << endl;
        idx++;
        //cout << dp[i][(1 << n) - 1] << " ";
    }
 
}