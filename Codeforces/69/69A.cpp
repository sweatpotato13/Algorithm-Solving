#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/problemset/problem/69/A#
string ans[2] ={"NO","YES"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isAnswer = false;
    ll n;
    cin >> n;
    ll x = 0, y=0,z=0;
    for(int i = 0;i<n;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if(!x && !y && !z) isAnswer = true;
    cout << ans[isAnswer];

	return 0;
}