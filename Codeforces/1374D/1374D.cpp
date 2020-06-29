#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1374/problem/D
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll,ll> m;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            m[k-(a[i]%k)]++;
        }
        ll rM = 0;
        ll rR = -1;
        for(auto K : m){
            if(K.first == k) break;
            if(rR <= K.second){
                rR = K.second;
                rM = K.first;
            }
        }
        ll ans = rR * k - (k-1-rM);
        if(rR == -1) ans = 0;
        cout << ans << "\n";
    }
    
	return 0;
}
