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
// https://atcoder.jp/contests/abc176/tasks/abc176_a
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    ll n,x,t;
    cin >> n >> x >> t;
    ll a = ceil((ld)n/x);
    printf("%lld",a*t);

    return 0;
}

