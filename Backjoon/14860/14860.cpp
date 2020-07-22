#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/14860
ll che[15000001] ={0,};
vector<ll> prime;
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
void getPrime(ll num){
    for(int i = 2;i<=num;i++){
        if(che[i])
            prime.push_back(i);
    }
}
ll mod_pow(ll x, ll y, ll m){
    if(y == 0) return 0;
    ll res = 1;
    x = x % m;
    while(y > 0){
        if(y & 1){
            res = (res * x) % m;
        }
        y = y >> 1;
        x = (x*x) % m;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    ll ans = 1;
    ll mod = 1e9+7;
    getChe(min(n,m));
    getPrime(min(n,m));
    for(auto k : prime){
        ll cnt, i;
        for(cnt = 0, i = k;i<=n;i*=k){
            cnt += ((n/i) * (m/i));
        }
        ans *= mod_pow(k,cnt,mod);
        ans %= mod;
    }
    cout << ans%mod;



	return 0;
}
