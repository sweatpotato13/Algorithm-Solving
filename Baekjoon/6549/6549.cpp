#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/6549
vector<ll> tree;
vector<ll> v;
ll n;
void init(ll node, ll start, ll end){
	if (start == end)
	{
		tree[node] = start;
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
    if (v[tree[node * 2]] <= v[tree[node * 2 + 1]])
        tree[node] = tree[node * 2];
    else
        tree[node] = tree[node * 2 + 1];
    return;
}
ll query(ll node, ll start, ll end, ll left, ll right){
	if (left > end || right < start)
		return 1e9+7;
	else if (left <= start && right >= end)
		return tree[node];
	else
	{
	    ll k1 = query(node * 2, start, (start + end) / 2, left, right);
		ll k2 = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        if(k1 == 1e9+7) return k2;
        else if(k2 == 1e9+7) return k1;
        else{
            if(v[k1] <= v[k2]) return k1;
            else return k2;
        }
	}
}
void update(ll node, ll start, ll end, ll index, ll diff){
	if (index < start || index > end)
		return;
	if (start == end){
		tree[node] += diff;
		return;
	}
	else{
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}
ll kth(ll node, ll start, ll end, ll k) {
    if (start == end) return start;
    else {
        if (k <= tree[node*2]) return kth(node * 2, start, (start + end) / 2, k);
        else return kth(node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
    }
}
ll solve(ll s, ll e){
    ll idx = query(1,0,n-1,s,e);
    ll sqr = (e - s + 1) * v[idx];
    if(s <= idx-1){
        ll k = solve(s,idx-1);
        if(sqr < k)
            sqr = k;
    }
    if(idx+1 <= e){
        ll k = solve(idx+1, e);
        if(sqr < k)
            sqr = k;
    }

    return sqr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    while(true){
        tree.clear();
        v.clear();
	    cin >> n;
        if(n == 0){
            break;
        }
	    ll tree_size = 4*n;
	    tree.resize(tree_size,0);
	    v.resize(n + 1,0);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        init(1,0,n-1);

        ans = solve(0,n-1);
        cout << ans << "\n";
    }

	return 0;
}