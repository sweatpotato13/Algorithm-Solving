#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/3079
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll l = 0;
    ll h = m * v[n-1];
    ll ans = h;
    while(l <= h){
        ll mid = (l+h)/2;
        ll s = 0;
        for(int i = 0;i<n;i++){
            s += (mid / v[i]);
        }
        if(s >= m){
            ans = min(ans, mid);
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans;

	return 0;
}
