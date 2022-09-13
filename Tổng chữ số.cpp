#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
ll SUM(string s){
    ll dp[20][3] = {};
    for(ll i = 1; i <= 9; i++)
        if(i < s[0] - '0') dp[1][0] += i;
        else if(i == s[0] - '0') dp[1][1] += i;
        else dp[1][2] += i;
    ll cur = 0, end = 0, ans = 0;
    for(ll i = 1; i <= s.size() - 1; i++){
        cur = cur * 10 + s[i - 1] - '0';
        end = end * 10 + 9;
        for(ll state = 0; state <= 2; state++){
            for(ll j = 0; j <= 9; j++){
                if(state == 0){
                    dp[i + 1][0] += dp[i][0] + j * (cur - pow(10, i - 1)) * (cur - pow(10, i - 1) > 0);
                }
                if(state == 1){
                    if(j < s[i] - '0') dp[i + 1][0] += dp[i][1] + j;
                    else if(j == s[i] - '0') dp[i + 1][1] = dp[i][1] + s[i] - '0';
                    else dp[i + 1][2] += dp[i][1] + j;
                }
                if(state == 2) dp[i + 1][2] += dp[i][2] + j * (end - cur);
            }
        }
    }
    for(ll i = 1; i <= s.size() - 1; i++)
        for(ll j = 0; j <= 2; j++) ans += dp[i][j];
    ans += dp[s.size()][0] + dp[s.size()][1];
    return ans;
}
 
int main (){
    faster();
    ll t; cin >> t;
    while(t--){
        string L, R; cin >> L >> R;
        ll sum = 0;
        for(int i = 0; i <= L.size() - 1; i++) sum += L[i] - '0';
        cout << SUM(R) - SUM(L) + sum << endl;
    }
}