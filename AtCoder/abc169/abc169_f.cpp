#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc169/tasks/abc169_f
ll dp[3010][3010] ={0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll mod = 998244353;
    ll inv = 499122177;
    ll n,s;
    cin >> n >> s;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    dp[0][0] = 1;
    for(int i = 0;i<n;i++){
        dp[0][0] = (dp[0][0] * 2) % mod;
    }
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<=s;j++){
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
            if (j + v[i] <= s) {
                dp[i+1][j+v[i]] = (dp[i+1][j+v[i]] + (dp[i][j] * inv)% mod) % mod;
            }
        }
    }
    cout << dp[n][s];


    return 0;
}