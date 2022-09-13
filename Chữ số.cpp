#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int main (){
    faster();
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll dp[20][4][7][3] = {};
        for(ll i = 1; i <= 9; i++)
            if(i < s[0] - '0') dp[1][i == 4][i == 7][0]++;
            else if(i == s[0] - '0') dp[1][i == 4][i == 7][1]++;
            else dp[1][i == 4][i == 7][2]++;
        ll newR4, newR7, newState;
        for(ll i = 1; i <= s.size() - 1; i++){
            for(ll r4 = 0; r4 <= 3; r4++){
                for(ll r7 = 0; r7 <= 6; r7++){
                    for(ll state = 0; state <= 2; state++){
                        for(ll j = 0; j <= 9; j++){
                            newR4 = (r4 + (j == 4)) % 4;
                            newR7 = (r7 + (j == 7)) % 7;
                            if(state == 1){
                                    if(j < s[i] - '0') newState = 0;
                                    else if(j == s[i] - '0') newState = 1;
                                    else newState = 2;
                            }
                            else newState = state;
                            dp[i + 1][newR4][newR7][newState] += dp[i][r4][r7][state];
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for(ll i = 1; i <= s.size() - 1; i++){
            for(ll j = 0; j <= 2; j++){
                ans += dp[i][0][0][j];
            }
        }
        ans += dp[s.size()][0][0][0] + dp[s.size()][0][0][1];
        cout << ans << endl;
    }
}