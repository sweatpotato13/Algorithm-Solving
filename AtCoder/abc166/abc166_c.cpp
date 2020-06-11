#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc166/tasks/abc166_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vector<ll> h(n+1);
    for(int i = 1;i<=n;i++){
        cin >> h[i];
    }
    vector<ll> a[100001];
    for(int i = 0;i<m;i++){
        ll e,s;
        cin >> e >> s;
        a[e].push_back(s);
        a[s].push_back(e);
    }
    ll ans = n;
    for(int i = 1;i<=n;i++){
        for(auto k : a[i]){
            if(h[k] >= h[i]){
                ans--;
                break;
            }
        }
    }

    cout << ans;
  
	return 0;
}