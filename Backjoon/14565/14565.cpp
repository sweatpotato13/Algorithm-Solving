#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/14565
tuple<ll, ll, ll> extended_gcd(ll a, ll b)
{
	if (a == 0)
		return make_tuple(b, 0, 1);
	ll gcd, x, y;
	tie(gcd, x, y) = extended_gcd(b % a, a);
	return make_tuple(gcd, (y - (b/a) * x), x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    ll n,a;
    cin >> n >> a;
    cout << n - a << " ";
    auto t = extended_gcd(a,n);
    ll ans = get<1>(t);
    if(get<0>(t) != 1) cout << -1;
    else cout << (ans + n)%n;

	return 0;
}
