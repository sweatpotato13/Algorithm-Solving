#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// http://codeforces.com/problemset/problem/1358/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2-x1) * (y2-y1) + 1 << "\n";
    }

    return 0;
}