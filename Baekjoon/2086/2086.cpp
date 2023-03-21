#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2086
map<ll,ll> d;
#define MOD 1000000000
ll fibo(ll n) {
    if (n <= 0) {
        return 0;
    } 
	else if (n == 1) {
        return 1;
    } 
	else if (n == 2) {
        return 1;
    } 
	else if (d.count(n) > 0) {
        return d[n];
    } 
	else {
        if (n % 2 == 1) {
            ll m = (n+1) / 2;
            ll t1 = fibo(m);
            ll t2 = fibo(m-1);
            d[n] = t1*t1 + t2*t2;
            d[n] %= MOD;
            return d[n];
        } 
		else {
            ll m = n/2;
            ll t1 = fibo(m-1);
            ll t2 = fibo(m);
            d[n] = (2LL*t1 + t2)*t2;
            d[n] %= MOD;
            return d[n];
        }
    }
}
ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a,b;
	cin >> a >> b;
	// ¥Òf_i(1 ~ n) = f_n+2 - 1
	ll res = ((fibo(b+2) - fibo(a+1)) + MOD) % MOD;
	cout << res << "\n";

	return 0;
}