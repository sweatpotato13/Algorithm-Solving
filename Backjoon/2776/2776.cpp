#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2776
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,ll> m1;
        for(int i = 0;i<n;i++){
           ll e;
           cin >> e;
           m1[e]++; 
        }
        ll m;
        cin >> m;
        for(int i = 0;i<m;i++){
            ll e;
            cin >> e;
            if(m1[e] != 0) cout << 1;
            else cout << 0;
            cout << "\n";
        }
    }

	return 0;
}
