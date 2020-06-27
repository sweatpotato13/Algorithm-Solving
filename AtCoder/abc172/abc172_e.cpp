#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_e
ll MOD = 1e9+7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
const int N = 5e5 + 5;
ll inv[N], fact[N], ifact[N];
void pre()
{
    inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = mul(MOD - MOD / i, inv[MOD % i], MOD);
        fact[i] = mul(i * 1ll, fact[i - 1], MOD);
        ifact[i] = mul(inv[i], ifact[i - 1], MOD);
    }
    return;
}
ll nCr(ll n, ll r)
{
    if (n >= 0 && r >= 0 && n >= r)
        return mul(fact[n], mul(ifact[r], ifact[n - r], MOD), MOD);
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    pre();
    ll ans = mul(nCr(m, n), fact[n], MOD);
    ans = mul(ans, ans, MOD);
    ll ex = 0;
    for(int i = 1;i<=n;i++){
        ll a = nCr(n, i);
        a = mul(a, mul(nCr(m, i), fact[i], MOD), MOD);
        ll b = mul(nCr(m - i, n - i), fact[n - i], MOD);
        b = mul(b, b, MOD);
        a = mul(a, b, MOD);
        if (i & 1)
            ex = add(ex, a, MOD);
        else
            ex = add(ex, MOD - a, MOD);

    }
    ans = add(ans, MOD - ex, MOD);
    cout << ans;

	return 0;
}