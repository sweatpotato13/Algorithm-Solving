#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/aising2020/tasks/aising2020_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l,r,d;
    cin >> l >> r >> d;
    ll ans = 0;
    for(int i = l;i<=r;i++){
        if(i%d==0) ans++;
    }
    cout << ans;

	return 0;
}
