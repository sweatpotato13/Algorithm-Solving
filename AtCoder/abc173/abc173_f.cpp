#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc173/tasks/abc173_f
ll mod = 1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<pll> v(n);
    for(int i = 0;i<n-1;i++){
        cin >> v[i].first >> v[i].second;
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans += i * (n-i+1);
    }
    for(int i = 0;i<n-1;i++){
        ll a = v[i].first;
        ll b = v[i].second;
        if(a > b) swap(a,b);
        ans -= (a * (n-b+1));
    }
    cout << ans;

	return 0;
}
