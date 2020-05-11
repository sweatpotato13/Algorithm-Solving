#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end());
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/1038
vector<ll> dp;
map<ll,ll> m;
void DFS(ll start, ll idx){
    for(int i = idx-1;i>=0;i--){
        if(m[start*10+i] == 0){
            dp.push_back(start*10+i);
            DFS(start*10+i,i);
            m[start*10+i] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(ll i = 9;i>=0;i--){
        m[i] = 1;
        dp.push_back(i);
        DFS(i,i);
    }
    sort(all(dp));
    dup(dp);
    if(n > 1022) cout << -1 << "\n";
    else cout << dp[n] << "\n";

    return 0;
}
