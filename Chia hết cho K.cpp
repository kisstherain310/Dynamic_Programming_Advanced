#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int main (){
    faster();
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int k, sz = s.size() - 1; cin >> k;
        if(k > 81) {
            cout << 0 << endl;
        }  
        else {
            int dp[12][85][85][85][3] = {}; 
            // dp[so.cs][so][tong][tich][state]
            int dem = 0;
            for(int i = 1; i <= 9; i++){
                int idx = i % k;
                if(i < s[0] - '0') dp[1][idx][idx][idx][0]++;
                else if(i == s[0] - '0') dp[1][idx][idx][idx][1]++;
                else dp[1][idx][idx][idx][2]++;
            }
            int newSo, newTong, newTich, newState;
            for(int i = 1; i <= sz; i++){
                for(int so = 0; so < k; so++){
                    for(int tong = 0; tong < k; tong++){
                        for(int tich = 0; tich < k; tich++){
                            for(int state = 0; state <= 2; state++){
                                if(dp[i][so][tong][tich][state] != 0)
                                for(int j = 0; j <= 9; j++){
                                    newSo = (so * 10 + j) % k;
                                    newTong = (tong + j) % k;
                                    newTich = (tich * j) % k;
                                    if(state == 1){
                                        int idx = s[i] - '0';
                                        if(j < idx) newState = 0;
                                        else if(j == idx) newState = 1;
                                        else newState = 2;
                                    } else newState = state;
                                    dp[i + 1][newSo][newTong][newTich][newState] += dp[i][so][tong][tich][state];
                                }
                            }
                        }
                    }
                }
            }
            int ans = 0;
            for(int i = 1; i <= sz; i++){
                for(int j = 0; j <= 2; j++){
                    ans += dp[i][0][0][0][j];
                }
            }
            ans += dp[sz + 1][0][0][0][0] + dp[sz + 1][0][0][0][1];
            cout << ans << endl;
        }
    }
}