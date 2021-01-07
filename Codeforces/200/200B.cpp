#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/200/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ld> v(n);
    ld ans = 0;
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        v[i] = (ld)e / 100;
        ans += v[i];
    }
    ans /= n;
    ans *= 100;
    cout << fixed;
    cout.precision(12);
    cout << ans;

    return 0;
}
