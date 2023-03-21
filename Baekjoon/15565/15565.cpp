#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/15565
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 1e9+9;
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> lion;
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(v[i] == 1)
            lion.push_back(i);
    }
    if(lion.size() < k)
        ans = -1;
    else{
        ll l = 0;
        ll r = k-1;
        while(r < lion.size()){
            ans = min(ans, (lion[r] - lion[l]+1));
            l++;
            r++;
        }
    }
    cout << ans;

    return 0;
}