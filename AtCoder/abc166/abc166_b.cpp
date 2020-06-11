#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc166/tasks/abc166_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n,k;
    cin >> n >> k;
    vector<ll> v[101];
    for(int i = 1;i<=k;i++){
        ll d;
        cin >> d;
        for(int j = 0;j<d;j++){
            ll e;
            cin >> e;
            v[e].push_back(i);
        }
    }
    for(int i = 1;i<=n;i++){
        if(v[i].size() == 0)
            ans++;
    }
    cout << ans;
	return 0;
}