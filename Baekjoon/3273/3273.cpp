#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://acmicpc.net/problem/3273
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n,m;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    cin >> m;
    for(int i = 0;i<n;i++){
        ll e = m - v[i];
        if(v[lower_bound(all(v) ,e) - v.begin()] == e)
            ans++;
    }

    cout << ans/2;

    return 0;
}