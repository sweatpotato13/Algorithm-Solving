#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc169/tasks/abc169_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a;
    long double b;
    cin >> a >> b;
    ll ans = floor(a * b);
    cout << ans << "\n";

    return 0;
}