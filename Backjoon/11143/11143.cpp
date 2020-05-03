#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/11143
vector<ll> tree;
vector<ll> v;
void init(ll node, ll start, ll end){
	if (start == end)
	{
		tree[node] = v[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}
ll query(ll node, ll start, ll end, ll left, ll right){
	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return tree[node];
	else
	{
		return query(node * 2, start, (start + end) / 2, left, right) + 
				   query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
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
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}
ll kth(ll node, ll start, ll end, ll k) {
    if (start == end) return start;
    else {
        if (k <= tree[node*2]) return kth(node * 2, start, (start + end) / 2, k);
        else return kth(node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	ll t;
	cin >> t;
	ll tree_size = (1 << (((ll)ceil(log2(100001)) + 1)));
	tree.resize(tree_size,0);
	while(t--){
		fill(all(tree),0);
		ll b,p,q;
		cin >> b >> p >> q;
		for(int i = 0;i<p+q;i++){
			char x;
			ll y,z;
			cin >> x >> y >> z;
			if(x == 'P'){
				update(1,1,b,y,z);
			}
			else{
				cout << query(1,1,b,y,z)<< "\n";
			}
		}
	}

	return 0;
}
