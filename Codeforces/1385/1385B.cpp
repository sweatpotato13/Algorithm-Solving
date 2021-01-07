#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/1385/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll> m;
        vector<ll> v(n+1);
        ll idx = 1;
        for(int i = 0;i<2*n;i++){
            ll e;
            cin >> e;
            if(m[e] == 0){
                m[e] = idx++;
            }
        }
        for(auto k : m){
            v[k.second] = k.first;
        }
        for(int i = 1;i<=n;i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0; 
}
