#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc175/tasks/abc175_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x,k,d;
    cin >> x >> k >> d;
    x = abs(x);
    ll temp = x / d;
    ll ans = 0;
    if(temp >= k){
        ans = x - k * d;    
    }
    else{
        ll m = x - temp * d;
        ll t = k - temp;
        if(t%2==0) ans = abs(m);
        else{
            ans = min(abs(m-d), abs(m+d));
        }
    }
    cout << ans;
    return 0;
}

