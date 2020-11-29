#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc183/tasks/abc183_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;

    if(sx > gx){
        swap(sx,gx);
        swap(sy,gy);
    }
    ll b = sy + gy;
    cout << fixed;
    cout.precision(10);
    cout << (ld)(sy*gx+sx*gy)/(ld)b;

	return 0;
}
