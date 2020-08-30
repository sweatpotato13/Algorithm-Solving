#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc177/tasks/abc177_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll mod = 1e9+7;
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    ll ssum = 0;
    for(int i = 0;i<n;i++){
        cin >> v[i];
        sum += v[i];
        ssum += v[i]*v[i];
        sum %= mod;
        ssum %= mod;
    }
    ll ans = 0;
    ans = ((sum*sum-ssum)%mod*500000004)%mod;
    cout << ans;

    return 0;
}