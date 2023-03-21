#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2548
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    ll ans = -1;
    ll minimum = INT_MAX;
    for(int i = 0;i<n;i++){
        ll temp = 0;
        for(int j = 0;j<n;j++){
            temp += abs(v[i] - v[j]);
        }
        if(temp < minimum){
            ans = v[i];
            minimum = temp;
        }
    }
    cout << ans;

    return 0;
}
