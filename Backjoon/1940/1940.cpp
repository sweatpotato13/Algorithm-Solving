#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://acmicpc.net/problem/1940
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i] + v[j] == m) ans++;
        }
    }
    cout << ans;

    return 0;
}