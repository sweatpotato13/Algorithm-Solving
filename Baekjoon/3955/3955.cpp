#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/3955
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

    ll t;
    cin >> t;
    while(t--){
        ll k,c;
        cin >> k >> c;
        if(c == 1){
            if(k+1 > 1000000000) cout << "IMPOSSIBLE\n";
            else cout << k+1 << "\n";
            continue;
        }
        else if(k == 1){
            cout << 1 << "\n";
            continue;
        }
        auto t = extended_gcd(k,c);
        if(get<0>(t) != 1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << (get<2>(t)+k)%k << "\n";
        }
    }


	return 0;
}
