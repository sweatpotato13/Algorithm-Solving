#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/7469
vector<pair<ll,ll>> v;
ll kth(ll n, ll a, ll b, ll k){
    ll cnt = 0;
    for(ll i = 0;i<n;i++){
        if(v[i].second >= a && v[i].second <= b){
            cnt++;
        }
        if(cnt == k)
            return v[i].first;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    for(ll i = 1;i<=n;i++){
        ll e;
        cin >> e;
        v.push_back({e,i});
    }
    sort(all(v));
    for(ll i = 1;i<=m;i++){
        ll a,b,k;
        cin >> a >> b >> k;
        ll ans = kth(n,a,b,k);
        cout << ans << "\n";
    }


    return 0;
}
