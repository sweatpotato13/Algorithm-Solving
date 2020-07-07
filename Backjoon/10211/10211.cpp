#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/10211
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n+1);
        vector<ll> dp(n+1);
        for(int i = 1;i<=n;i++){
            cin >> v[i];
            dp[i] = dp[i-1] + v[i];
        }
        ll ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            for(int j = i;j<=n;j++){
                ans = max(ans, dp[j]-dp[i-1]);
            }
        }
        cout << ans << "\n";
    }

	return 0;
}
