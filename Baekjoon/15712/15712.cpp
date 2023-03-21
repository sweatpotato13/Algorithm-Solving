#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15712
ll a,r,n,mod;
ll modulo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2 == 1){
            res = (res * a) % mod;
        }
        a = (a*a) % mod;
        b/=2;
    }
    return res;
}
ll solve(ll x){
    if(x == 0) 
        return 1;
    if(x == 1)
        return (r+1) % mod;
    if(x % 2 == 1)
        return solve(x/2) * (1 + modulo(r, x/2+1)) % mod;
    return (solve(x/2-1) * (1 +modulo(r, x/2)) % mod + modulo(r,x) % mod) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans;
    cin >> a >> r >> n >> mod;
    ans = a * solve(n-1) % mod;
    cout << ans;    

	return 0;
}