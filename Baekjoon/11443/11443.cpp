#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/11443
map<ll,ll> d;
#define MOD 1000000007
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

	ll n;
	cin >> n;
	//sigma(f_2i) = f_2n+1 - 1
	ll res;
	if(n % 2 == 1){
		res = fibo(n) - 1;
	}
	else{
		res = fibo(n+1) - 1;
	}
	cout << res << "\n";

	return 0;
}