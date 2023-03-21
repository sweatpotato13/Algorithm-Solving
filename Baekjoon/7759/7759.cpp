#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/7759
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for(int i = 0;i<n;i++)
            cin >> a[i];
        for(int i = 0;i<m;i++)
            cin >> b[i];
        sort(all(a));
        sort(all(b));
        b.push_back(INT_MAX);
        ll idx = 0;
        for(int i = 0;i<n;i++){
            ll e = a[i];
            while(b[idx] < e){
                idx++;
            }
            ans += idx;
        }
        cout << ans << "\n";
    }

    return 0;
}