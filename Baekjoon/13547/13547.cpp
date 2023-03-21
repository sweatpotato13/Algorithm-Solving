#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/13547
ll ans[1000001];
tl3 query[1000001];
ll n,q;
ll a[1000001];
ll sz;
bool cmp(tl3 a, tl3 b) {
	if (get<0>(a) / sz != get<0>(b) / sz)
		return get<0>(a) / sz < get<0>(b) / sz;
	return get<1>(a) < get<1>(b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sz = sqrt(n);
    cin >> q;
    for(int i = 0;i<q;i++){
        cin >> get<0>(query[i]) >> get<1>(query[i]);
        get<2>(query[i]) = i;
    }
    sort(query, query+q ,cmp);
    vector<ll> state(1000001);
    ll val = 0;
    ll s = get<0>(query[0]);
    ll e = get<1>(query[0]);
    for(int i = s;i<=e;i++){
        if(state[a[i]] == 0) val++;
        state[a[i]]++;
    }
    ans[get<2>(query[0])] = val;
    for(int i = 1;i<q;i++){
        ll next_s = get<0>(query[i]);
        ll next_e = get<1>(query[i]);
        if(s > next_s){
            for(;s != next_s;s--){
                if(state[a[s-1]] == 0) val++;
                state[a[s-1]]++;
            }
        }
        else if(s < next_s){
            for(;s != next_s;s++){
                if(state[a[s]] == 1) val--;
                state[a[s]]--;
            }
        }
        if(e > next_e){
            for(;e != next_e;e--){
                if(state[a[e]] == 1) val--;
                state[a[e]]--;
            }
        }
        else if(e < next_e){
            for(;e != next_e;e++){
                if(state[a[e+1]] == 0) val++;
                state[a[e+1]]++;
            }
        }
        ans[get<2>(query[i])] = val;
    }
    for(int i = 0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0; 
}