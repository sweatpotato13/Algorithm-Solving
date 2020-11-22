#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc182/tasks/abc182_b
ll che[1001] ={0,};
vll prime;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll max = 0;
    ll ans = 0;
    ll n;
    cin >> n;
    vll v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    getChe(v[v.size()-1]);
    getPrime(v[v.size()-1]);
    for(auto k : prime){
        ll cnt = 0;
        for(int i =0;i<n;i++){
            if(v[i] % k == 0) cnt++;
        }
        if(cnt > max) {
            max = cnt;
            ans = k;
        }
    }
    cout << ans;
    

    return 0;
}