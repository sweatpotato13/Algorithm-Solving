#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/14505
ll dp[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll len = s.length();
    for (ll i = 0; i < len; i++){
        dp[i][i] = 1;
         if (s[i] == s[i + 1])
            dp[i][i + 1] = 3;
         else
            dp[i][i + 1] = 2;
    }
    for (ll i = 2; i < len; i++){
        for (ll l = 0; l < len; l++){
            ll r = l + i;
            if (r > len) break;
            dp[l][r] = (dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1]);
            if (s[l] == s[r]) dp[l][r] += dp[l + 1][r - 1] + 1;
        }
    }
    cout << dp[0][s.length()-1];

    return 0;
}
