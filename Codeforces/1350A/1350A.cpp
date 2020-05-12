#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// http://codeforces.com/contest/1350/problem/A
vector<ll> arr(1000001,0);
void getChe(int num) {

    int i = 2;
    // 입력받은 수 만큼 배열에모두 초기화 해둔다
    for (i = 2; i <= num; i++) {
        arr[i] = i;
    }
    
    for (i = 2; i <= num; i++) { 
        if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        for (int j = i + i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            arr[j] = 0;
        }
    }
}
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll mod_mul(ll x, ll y, ll m){
	return (ll)(x * y % m);
}
ll mod_pod(ll x, ll y, ll m){
	ll r = 1;
	x %= m;
	while (y){
		if (y & 1)
			r = mod_mul(r, x, m);
		x = mod_mul(x, x, m);
		y >>= 1;
	}
	return r;
}
bool miller_rabin(ll n, ll a){
	// https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
	if (n % a == 0)
		return false;
	ll r = -1;
	ll d = n - 1;
	while (d % 2 == 0){
		d >>= 1;
		r++;
	}
	ll p = mod_pod(a, d, n);
	if (p == 1 or p == n - 1)
		return true;
	while (r--){
		p = mod_mul(p, p, n);
		if (p == n - 1)
			return true;
	}
	return false;
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
	// https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
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
	while (n % 2 == 0){
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
 
	ll t;
	cin >> t;
	getChe(1000000);
	while(t--){
		vector<ll> ans;
		ll n,k;
		cin >> n >> k;
		ll temp = n;
		getFactor(n,ans);
		sort(all(ans));
		while(k--){
			if(!(n % 2)){
				n = n + (2 * (k+1));
				break;
			}
			if(!arr[n]){
				temp = ans[0];
			}
			n = temp + n;
		}
		cout << n << "\n";
	}
 
	return 0;
}