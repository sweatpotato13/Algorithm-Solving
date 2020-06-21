#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_f
ll mod = 1e9+7;
ll fac[2000001], inv[2000001];
ll power(ll x, ll y) {
    ll r = 1;
    while (y) {
        if (y & 1)
            r = (r * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return r;
}
ll C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return ((fac[n] * inv[k]) % mod * inv[n - k]) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll k;
    string s;
    cin >> k >> s;
    fac[0] = 1;
    for (int i = 1; i < 2000001; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[2000001 - 1] = power(fac[2000001 - 1], mod - 2);
    for (int i = 2000001 - 1; i > 0; i--) {
        inv[i - 1] = inv[i] * (i) % mod;
    }
    ll n = s.length();
    for (int i = n; i <= k + n; i++) {
        ans = (ans + C(k + n, i) * power(25, k + n - i)) % mod;
    }

    cout << ans;

	return 0;
}
