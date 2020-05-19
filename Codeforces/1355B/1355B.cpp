#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1355/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 0;
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0;i<n;i++)
            cin >> v[i];
        sort(all(v));
        ll idx = 0;
        for(int i = 0;i<n;i++){
            if(++idx == v[i]){
                ans++;
                idx = 0;
            }
        }
        cout << ans << "\n";
    }

	return 0;
}
