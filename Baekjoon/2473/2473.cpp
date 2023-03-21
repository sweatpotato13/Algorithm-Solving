#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2473
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> ans(3);
    ll mm = INT64_MAX;
    ll n;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    sort(all(v));
    for(int i = 0;i<n;i++){
        ll l = 0;
        ll r = n-1;
        while(l < r){
            if(l != i && i != r){
                if(mm > abs(v[i] + v[r] + v[l])){
                    mm = abs(v[i] + v[r] + v[l]);
                    ans[0] = v[i];
                    ans[1] = v[r];
                    ans[2] = v[l];
                }
            }
            if(abs(v[i] + v[r] + v[l+1]) > abs(v[i] + v[r-1] + v[l])) r--;
            else l++;
        }
    }
    sort(all(ans));
    for(auto k : ans) cout << k << " ";

    return 0;
}