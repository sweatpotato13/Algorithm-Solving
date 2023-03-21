#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1275
vector<ll> tree;
vector<ll> v;
void init(ll node, ll start, ll end){
    if(start == end){
        tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
    return;
}
ll query(ll node, ll start, ll end, ll left, ll right){
	if(left > end || right < start) return 0;
	else if(left <= start && right >= end) return tree[node];
	else{
		return (query(node*2, start, (start+end)/2, left, right) +
				query(node * 2 + 1, (start+end)/2+1, end, left, right));
	}
}
void update(ll node, ll start, ll end, ll index, ll diff) {
    if (index < start || index > end) return;
	if (start == end) {
		tree[node] = diff;
		return;
	}
    if (start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
		tree[node] = (tree[node * 2] + tree[node * 2 + 1]);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,q;
	cin >> n >> q;
	ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
	tree.resize(tree_size);
	v.resize(n+1);
	for(ll i = 0;i<n;i++){
		cin >> v[i];
	}
    init(1, 0, n-1);
	for(ll i = 0;i<q;i++){
		ll x,y,a,b;
		cin >> x >> y >> a >> b;
		ll maxTmp = max(x,y);
		ll minTmp = min(x,y);
		x = minTmp;
		y = maxTmp;
		ll p = query(1,0,n-1,x-1,y-1);
		cout << p << "\n";
		update(1,0,n-1,a-1,b);
	}

	return 0;
}