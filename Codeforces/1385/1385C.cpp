#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/1385/C
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        ll ans = n-1;
        while(ans > 0 && v[ans-1] >= v[ans]){
            ans--;
        }
        while(ans > 0 && v[ans- 1] <= v[ans]){
            ans--;
        }
        cout << ans << "\n";
    }

    return 0; 
}
