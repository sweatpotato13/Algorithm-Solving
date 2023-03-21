#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/16565
ll MOD = 10007;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
const int N = 60;
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

    pre();
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i<=n/4;i++){
        ll first = nCr(13,i);
        ll second = nCr(52-4*i,n-4*i);
        if(i%2)
            ans += first * second;
        else 
            ans -= first * second;
    }
    cout << ((ans % MOD) + MOD) % MOD;


	return 0;
}
