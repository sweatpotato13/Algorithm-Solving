#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/13926
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ull mod_mul(ull x, ull y, ull m){
	return (ull)((__int128)x * y % m);
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
ll PollardRho(ll n){
	ll x = rand() % (n - 2) + 2;
	ll y = x;
	ll c = rand() % (n - 1) + 1;
	while (true){
		x = (mod_mul(x, x, n) + c) % n;
		y = (mod_mul(y, y, n) + c) % n;
		y = (mod_mul(y, y, n) + c) % n;
		ll d = gcd(abs(x - y), n);
		if (d == 1)
			continue;
		if (!isPrime(d))
			return PollardRho(d);
		else
			return d;
	}
}
void getFactor(ll n, vector<ll>& f){
	while (!(n & 1)){
		n >>= 1;
		f.push_back(2);
	}
	if (n == 1)
		return;
	while (!isPrime(n)){
		ll d = PollardRho(n);
		while (n % d == 0)
		{
			f.push_back(d);
			n /= d;
		}
		if (n == 1)
			break;
	}
	if (n != 1)
		f.push_back(n);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	vector<ll> v;
	ll n;
	cin >> n;
	ll ans = n;
	getFactor(n,v);
	v.erase(unique(all(v)),v.end());
	for(int i = 0;i<v.size();i++){
		ans = ans - ans/v[i];
	}
	cout << ans << "\n";
    return 0;
}
