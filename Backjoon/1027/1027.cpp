#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll; 
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define rep(i, n) FOR(i, 0, n) 
#define repn(i, n) FORN(i, 1, n) 
#define tc(t) while (t--) 
// https://www.acmicpc.net/problem/1027
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vll v(n);
    rep(i,n){
        cin >> v[i];
    }
    ll ans = 0;
    rep(i,n){
        ll cnt_l = 0;
        ll cnt_r = 0;
        ld temp = INT_MAX;
        for(int j = i-1;j>=0;j--){
            ld a = ((ld)(v[i]-v[j])) / ((ld)i-j);
            if(a < temp){
                temp = a;
                cnt_l++;
            }
        }
        temp = -INT_MAX;
        for(int j = i+1;j<n;j++){
            ld a = ((ld)(v[i]-v[j])) / ((ld)i-j);
            if(a > temp){
                temp = a;
                cnt_r++;
            }
        }
        ans = max(cnt_r + cnt_l, ans);
    }
    cout << ans;
    
    return 0;
}
