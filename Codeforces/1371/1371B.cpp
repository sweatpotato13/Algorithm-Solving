#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/1371/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n, r;
        cin >> n >> r;
        ll ans = 0;
        if(n <= 1) ans = 1;
        else{
            if(n <= r){
                r = n-1;
                ans++;
            }
            ans += ((1+r)*(r))/2;
        }
        cout << ans << "\n";
    }

	return 0;
}
