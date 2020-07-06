#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc173/tasks/abc173_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++)
        cin >> v[i];
    sort(all(v));
    ll ans = 0;
    for(int i = 1;i<=n-1;i++){
        ans += v[n-i/2];
    }
    cout << ans;

	return 0;
}
