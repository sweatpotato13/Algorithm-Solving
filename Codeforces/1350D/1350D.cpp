#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// http://codeforces.com/contest/1350/problem/D
ll check(ll n, vector<ll> &k){
    ll res = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n && j-i<=2;j++){
            if(k[i] && k[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> v(n+1);
        bool hasK = false;
        for(int i = 1;i<=n;i++){
            ll e;
            cin >> e;
            if(e < k) v[i] = 0;
            else if(e == k) {hasK = true; v[i] = 1;}
            else v[i] = 2;
        }
        if(!hasK){
            cout << "no\n";
            continue;
        }
        if(n == 1){
            cout << "yes\n";
            continue;
        } 
        ll ans = check(n,v);
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }

	return 0;
}