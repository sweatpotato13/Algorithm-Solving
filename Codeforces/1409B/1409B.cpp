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
// http://codeforces.com/problemset/problem/1409/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        ll ans = 1e18;
        for(int i = 0;i<2;i++){
			ll da = min(n, a - x);
			ll db = min(n - da, b - y);
			ans = min(ans, (a - da) * 1ll * (b - db));
			swap(a, b);
			swap(x, y);
        }
        cout << ans << "\n";
    }


    return 0;
}