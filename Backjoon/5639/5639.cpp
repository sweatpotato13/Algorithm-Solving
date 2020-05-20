#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/5639
vector<ll> v;
void solve(ll s, ll f){
    if(s > f) return;
    ll root = v[s];
    ll temp = f;
    while(v[temp] > root) temp--;
    solve(s+1,temp);
    solve(temp+1,f);
    cout << root << "\n";    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        ll e;
        cin >> e;
        if(cin.eof()) break;
        v.push_back(e);
    }
    solve(0, v.size()-1);

    return 0;
}