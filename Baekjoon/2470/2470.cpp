#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://acmicpc.net/problem/2470
vector<ll> v;
bool cmp(ll a, ll b){
    return abs(a) < abs(b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pll ans = {INT_MAX,INT_MAX};
    ll mm = INT_MAX;
    ll n;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    sort(all(v), cmp);
    for(int i = 0;i<n-1;i++){
        if(abs(v[i] + v[i+1]) < mm){
            ans = {v[i],v[i+1]};
            mm = abs(v[i] + v[i+1]);
        }
    }
    if(ans.first > ans.second)
        swap(ans.first, ans.second);
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}