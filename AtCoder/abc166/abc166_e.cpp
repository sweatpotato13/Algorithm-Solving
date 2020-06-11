#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc166/tasks/abc166_e
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++)
        cin >> v[i];

    map<ll,ll> m;
    for(int i = 1;i<=n;i++){
        if(m[i-v[i]] != 0)
            ans += m[i-v[i]];
        if(m[i+v[i]] != 0)
            m[i+v[i]] += 1;
        else{
            m[i+v[i]] = 1;
        }
    }

    cout << ans;
	return 0;
}