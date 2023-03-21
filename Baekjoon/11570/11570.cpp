#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11570
ll dp[2002][2002] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = INT_MAX;
        }
    }
    dp[1][0] = 0;
    dp[0][1] = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            if(i == j) continue;
            ll nxt = max(i, j)+1;
            if(!i || !j) v[0] = v[nxt];
            dp[nxt][j] = min(dp[nxt][j], dp[i][j] + abs(v[nxt] - v[i]));
            dp[i][nxt] = min(dp[i][nxt], dp[i][j] + abs(v[nxt] - v[j]));
        }
    }
    ll ans = INT_MAX;
    for(int i = 0;i<=n;i++){
        ans = min(ans, dp[n][i]);
        ans = min(ans, dp[i][n]);
    }
    cout << ans;
    
    return 0;
}
