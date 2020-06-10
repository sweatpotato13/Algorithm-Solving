#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/18122
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll mod = 1e9+7;
    ll ans = 1;
    ll n;
    cin >> n;
    for(int i = 0;i<n+2;i++){
        ans = (ans * 2) % mod;
    }
    ans -= 5;
    cout << ans;

	return 0;
}