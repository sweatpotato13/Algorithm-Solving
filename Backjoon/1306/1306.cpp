#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/1306
vector<int> tree;
vector<ll> v;
void init(ll node, ll start, ll end){
    if(start == end){
        tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    return;
}
int query(ll node, ll start, ll end, ll left, ll right){
	if(left > end || right < start) return -1;
	else if(left <= start && right >= end) return tree[node];
	else{
		return max(query(node*2, start, (start+end)/2, left, right),
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
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n,m;
	cin >> n >> m;
	ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
	tree.resize(tree_size);
	v.resize(n+1);
	for(ll i = 0;i<n;i++){
		cin >> v[i];
	}
   init(1, 0, n-1);
   int interval = (2*m-1)/2;
	for (ll i = m-1; i <= n-m; i++){
		int p = query(1, 0, n - 1, i-interval, i+interval);
		cout << p << " ";
	}
	cout << "\n";
	return 0;
}