#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1359/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n, m, k;
        cin >> n >> m >> k;
        ll x = min(m,n/k);
        ll y = (m - x + k - 2) / (k-1);
        ans = x - y;
        cout << ans << "\n";
    }

	return 0;
}