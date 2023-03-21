#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/14438
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
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	return;
}
ll query(ll node, ll start, ll end, ll left, ll right){
	if (left > end || right < start)
		return 2100000000;
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
		tree[node] = diff;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	ll n,m;
	cin >> n;
	ll tree_size = (1 << (((ll)ceil(log2(n+1)) + 1)));
	tree.resize(tree_size,0);
	v.resize(n + 1,0);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	init(1,0,n-1);
	cin >> m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		if(a == 1){
			update(1,0,n-1,b-1,c);
		}
		else{
			ll p = query(1,0,n-1,b-1,c-1);
			cout << p << "\n";
		}
	}
	return 0;
}
