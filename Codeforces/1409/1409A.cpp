#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// http://codeforces.com/problemset/problem/1409/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll ans = 0;
        ll temp = max(a,b) - min(a,b);
        ans = temp%10 ? temp/10+1 : temp/10;
        cout << ans << "\n";
    }


    return 0;
}