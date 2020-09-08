#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/19637
ll arr[1010101] = {0,};
bool cmp(pair<pll,string> a, pair<pll,string> b){
    if(a.first.second < b.first.second) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,m;
    cin >> n >> m;
    map<ll,string> ma;
    for(int i = 0;i<n;i++){
        string s;
        ll val;
        cin >> s >> val;
        arr[i] = val;
        if(ma[val] != "") continue;
        ma[val] = s;
    }
    vector<pair<pll,string>> v(m);
    for(int i = 0;i<m;i++){
        ll e;
        cin >> e;
        v[i] = {{e,i},""};
    }
    sort(all(v));
    ll idx = 0;
    for(int i = 0;i<m;i++){
        if(v[i].first.first <= arr[idx]){
            v[i].second = ma[arr[idx]];
        }
        else{
            idx++;
            i--;
        }
    }
    sort(all(v),cmp);
    for(auto k : v){
        cout << k.second << "\n";
    }

    return 0;
}
