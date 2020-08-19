#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://codeforces.com/problemset/problem/1399/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n+1);
        for(int i = 0;i<n;i++){
            ll e;
            cin >> e;
            v[e]++;
        }
        ll ans = -1;
        for(int s = 2;s<=2*n;s++){
            ll temp = 0;
            for(int i = 1;i<(s+1)/2;i++){
                if(s-i > n) continue;
                temp += min(v[s-i], v[i]);
            }
            if(s % 2 == 0)
                temp += v[s/2]/2;
            ans = max(ans,temp);
        }
        cout << ans << "\n";
    }

    return 0;
}
