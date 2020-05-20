#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/1395
vector<ll> tree;
vector<ll> lazy;
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
void update_lazy(ll node, ll start, ll end){
    if(lazy[node] == 0)
        return;
    tree[node] = (end- start + 1) - tree[node];
    if(start != end){
        lazy[node * 2] ^= 1;
        lazy[node * 2 + 1] ^= 1;
    }
    lazy[node] = 0;
}
void update_range(ll node, ll start, ll end, ll left, ll right, ll val){
    update_lazy(node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right){
        tree[node] = (end - start + 1) - tree[node];
        if (start != end){
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right, val);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query_lazy(ll node, ll start, ll end, ll left, ll right){
    update_lazy(node, start, end);
 
    if (left > end || right < start)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node];
 
    return query_lazy(node * 2, start, (start + end) / 2, left, right) 
            + query_lazy(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
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
	cin >> n >> m;
	ll tree_size = (1 << (((ll)ceil(log2(n+1)) + 1)));
	tree.resize(tree_size,0);
    lazy.resize(tree_size,0);
	v.resize(n + 1,0);
    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 0){
            update_range(1,0,n-1,b-1,c-1,1);
        }
        else{
            cout << query_lazy(1,0,n-1,b-1,c-1) << "\n";
        }
    }
	return 0;
}