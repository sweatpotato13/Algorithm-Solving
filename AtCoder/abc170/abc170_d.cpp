#pragma warning(disable : 4996)
#include <bits/stdc++.h>
extern "C" {
#include <quadmath.h>
}
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc170/tasks/abc170_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    ll m = 0;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        m = max(m, v[i]);
    }
    sort(all(v));
    vector<ll> dp(m+2);
    for (auto x : v){
        for (int i = x; i <= m; i += x){
            dp[i]++;
        }
    }
    for (auto x : v){
        if (dp[x] == 1)
            ans++;
    }
    cout << ans;

	return 0;
}