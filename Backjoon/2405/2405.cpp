#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2405
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = -1;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    for(int i = 1;i<n-1;i++){
        ans = max(ans, abs(v[0] + v[i] + v[i+1] - 3 * v[i]));
        ans = max(ans, abs(v[i-1] + v[i] + v[n-1] - 3 * v[i]));
    }
    cout << ans;
    

	return 0;
}