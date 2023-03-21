#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/13548
const ll N = 100001;
pll query[N];
pair<pll,ll> order[N];
ll state[N];
ll state2[N];
ll v[N];
ll ans[N];
ll val = 0;
ll sqn;
void add(ll x){
    state2[state[v[x]]]--;
    state[v[x]]++;
    state2[state[v[x]]]++;
    val = max(val, state[v[x]]);
}
void erase(ll x){
    state2[state[v[x]]]--;
    state[v[x]]--;
    state2[state[v[x]]]++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    state2[0] = n+1;
    sqn = sqrt(n);
    cin >> q;
    for(int i = 1;i<=q;i++){
        cin >> query[i].first >> query[i].second;
        order[i].first = pll(query[i].first/sqn, query[i].second);
        order[i].second = i;
    }
    sort(order+1, order+q+1);
    for(int i = 1;i<=q;i++){
        auto prev = query[order[i-1].second];
        auto curr = query[order[i].second];
        ll s1 = prev.first;
        ll e1 = prev.second;
        ll s2 = curr.first;
        ll e2 = curr.second;
        for(int j = s1-1; j>=s2; j--) add(j);
        for(int j = e1+1; j<=e2; j++) add(j);
        for(int j = s1; j<s2; j++) erase(j);
        for(int j = e1; j>e2; j--) erase(j);
        while(state2[val] == 0)
            val--;
        ans[order[i].second] = val;
    }
    for(int i = 1;i<=q;i++){
        cout << ans[i] << "\n";
    }
    return 0; 
}