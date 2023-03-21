#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1007
ld ans = 1e9+7;
void solve(vector<pld> v, ll n){
    vector<ll> idx;
    for(int i = 0;i<2;i++){
        for(int j=0;j<n/2;j++){
            idx.push_back(i);
        }
    }
    do{
        ld x = 0;
        ld y = 0;
        for (int i = 0; i < n; i++) {
            if (idx[i]) {
                x += v[i].first;
                y += v[i].second;
            }
            else {
                x -= v[i].first;
                y -= v[i].second;
            }
        }
        ans = min(ans, sqrt(x*x + y*y));
    }while(next_permutation(all(idx)));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ans = 1e9+7;
        ll n;
        cin >> n;
        vector<pld> v(n);
        for(int i = 0;i<n;i++){
            ld x,y;
            cin >> x >> y;
            v[i] = {x,y};
        }
        solve(v, n);
        cout << fixed;
        cout.precision(12);
        cout << ans << "\n";
    }
	return 0;
}