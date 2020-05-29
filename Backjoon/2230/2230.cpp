#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2230
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = INT_MAX;
    ll n, m;
    cin >> n >> m;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    sort(all(v));
    ll l = 0;
    ll r = 0;
    while(r < n && l < n){
        ll e = v[r] - v[l];
        if(m <= e){
            l++;
            ans = min(ans, e);
        }
        else{
            r++;
        }
    }
    cout << ans << "\n";

    return 0;
}