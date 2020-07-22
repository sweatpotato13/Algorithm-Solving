#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/9537
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v(n);
        map<ll,ll> m;
        ll ans = 0;
        for(int i = 0;i<n;i++){
            cin >> v[i];
            map<ll,ll> mm;
            ans = max(ans, v[i]);
            mm[v[i]] = i;
            ll g;
            for(auto k : m){
                g = gcd(k.first, v[i]);
                ans = max(ans, g * (i-k.second+1));
                auto it = mm.find(g);
                if(it != mm.end()){
                    it->second = min(it->second, k.second);
                }
                else{
                    mm[g] = k.second;
                }
            }
            m = mm;
        }   
        cout << ans << "\n";
    }

	return 0;
}
