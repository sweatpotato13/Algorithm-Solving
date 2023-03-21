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
// https://www.acmicpc.net/problem/4134
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ull mod_mul(ull x, ull y, ull m){
	return (ull)(x * y % m);
}
ull mod_pod(ull x, ull y, ull m){
	ull r = 1;
	x %= m;
	while (y){
		if (y & 1)
			r = mod_mul(r, x, m);
		x = mod_mul(x, x, m);
		y >>= 1;
	}
	return r;
}
bool miller_rabin(ull n, ull a){
	if (n % a == 0)
		return 0;
	int cnt = -1;
	ull d = n - 1;
	while (!(d & 1)){
		d >>= 1;
		cnt++;
	}
	ull p = mod_pod(a, d, n);
	if (p == 1 or p == n - 1)
		return 1;
	while (cnt--){
		p = mod_mul(p, p, n);
		if (p == n - 1)
			return 1;
	}
	return 0;
}
bool isPrime(ll n){
	vector<ll> list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (auto p : list){
		if (n == p)
			return 1;
		if (n > 40 && !miller_rabin(n, p))
			return 0;
	}
	if (n <= 40)
		return 0;
	return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        while(1){
            if(isPrime(n)){
                cout << n << "\n";
                break;
            }
            n++;
        }
    }

    return 0;
}

