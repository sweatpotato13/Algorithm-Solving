#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc174/tasks/abc174_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,d;
    cin >> n >> d;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ll s,e;
        cin >> s >> e;
        ll dis = s*s+e*e;
        if(dis <= d*d) ans++;
    }
    cout << ans;

    return 0; 
}