#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://codeforces.com/contest/1374/problem/E1
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n,k;
    cin >> n >> k;
    vector<ll> times[4];
    vector<ll> sums[4];
    for(int i = 0;i<n;i++){
        ll t,a,b;
        cin >> t >> a >> b;
        times[a*2+b].push_back(t);
    }
    for(int i = 0;i<4;i++){
        sort(all(times[i]));
        sums[i].push_back(0);
        for(auto k : times[i]){
            sums[i].push_back(sums[i].back()+k);
        }
    }
    ll ans = INT_MAX;
    for(int cnt = 0;cnt<min(k+1, (ll)sums[3].size());cnt++){
		if (k - cnt < int(sums[1].size()) && k - cnt < int(sums[2].size())) {
			ans = min(ans, sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt]);
		}
	}
	
	if (ans == INT_MAX) ans = -1;
	cout << ans << endl;

    
	return 0;
}
