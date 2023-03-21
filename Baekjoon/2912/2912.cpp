#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2912
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,c;
    cin >> n >> c;
    vector<ll> v(n+1);
    vector<ll> ms[10001];
    for(int i = 1;i<=n;i++){
        cin >> v[i];
		if(ms[v[i]].empty()) 
            ms[v[i]].push_back(-1);
		ms[v[i]].push_back(i);
    }
    ll m;
    cin >> m;
    srand((unsigned)time(NULL));
    for(int i = 0;i<m;i++){
        ll s,e;
        cin >> s >> e;
        ll ans = 0;
        for(int j = 0;j<100;j++){
            ll idx = rand()%(e-s+1) +s;
            ll temp = v[idx];
            ll cnt = upper_bound(all(ms[temp]),e) - lower_bound(all(ms[temp]),s);
            if(cnt > (e-s+1)/2){
                ans = temp;
                break;
            }
        }
        if(!ans){
            cout << "no\n";
        }
        else cout << "yes " << ans << "\n";
    }

    return 0; 
}