#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/11439
ll che[4000001] ={0,};
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(4000000);
    getPrime(4000000);
    ll n,k,m;
    cin >> n >> k >> m;
    vector<ll> cnt(prime.size());
    for (ll i = 0; i < prime.size(); i++){
        for (ll j = prime[i]; j <= n; j *= prime[i]){
            cnt[i] += ((n / j) - (k / j) - ((n - k) / j));
        }
    }
    ll ans = 1;
    for(ll i = 0;i<cnt.size();i++){
        for(ll j = 0;j<cnt[i];j++){
            ans *= prime[i];
            ans %= m;
            if(!ans){
                cout << 0;
                return 0;
            }
        }
    }
    cout << ans;
	return 0;
}
