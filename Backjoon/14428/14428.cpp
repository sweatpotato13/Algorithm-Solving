#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/14428
vector<pair<ll,ll>> tree;
vector<pair<ll,ll>> v;
void init(ll node, ll start, ll end){
    if (start == end)
    {
        tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    int e = min(tree[node * 2].first,tree[node * 2 + 1].first);
	if(e == tree[node*2].first){
		tree[node].first = e;
		tree[node].second = tree[node*2].second;
	}
	else{
		tree[node].first = e;
		tree[node].second = tree[node*2+1].second;
	}
    return;
}
pll query(ll node, ll start, ll end, ll left, ll right){
    if (left > end || right < start)
        return make_pair(2100000001,100001);
    else if (left <= start && right >= end)
        return tree[node];
    else
    {
        return min(query(node * 2, start, (start + end) / 2, left, right),
                   query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }
}
void update(ll node, ll start, ll end, ll index, ll diff){
    if (index < start || index > end)
        return;
    if (start == end){
        tree[node].first = diff;
        return;
    }
    update(node * 2, start, (start + end) / 2, index, diff);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    ll e = min(tree[node * 2].first,tree[node * 2 + 1].first);
	if(e == tree[node*2].first){
		tree[node].first = e;
		tree[node].second = tree[node*2].second;
	}
	else{
		tree[node].first = e;
		tree[node].second = tree[node*2+1].second;
	}
}
/*
ll kth(ll node, ll start, ll end, ll k) {
    if (start == end) return start;
    else {
        if (k <= tree[node*2]) return kth(node * 2, start, (start + end) / 2, k);
        else return kth(node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
    }
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n;
    cin >> n;
    ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
    tree.resize(tree_size,{0,0});
	for(ll i =0;i<n;i++){
		ll e;
		cin >> e;
		v.push_back(make_pair(e,i));
	}
	init(1,0,n-1);
	ll m;
	cin >> m;
	while(m--){
		ll a,b,c;
		cin >> a >> b >> c;
		if(a == 1){
			update(1,0,n-1,b-1,c);
		}
		else{
			pll p = query(1,0,n-1,b-1,c-1);
			cout << p.second + 1 << "\n";
		}
	}

    return 0;
}
