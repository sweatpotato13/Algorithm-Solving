#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/18436
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
		tree[node] = diff;
		return;
	}
	else{
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin >> n;
    ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
    tree.resize(tree_size);
    v.resize(n+1);
    for(ll i = 0;i<n;i++){
        ll x;
        cin >> x;
        if(x%2==0) v[i] = 0;
        else v[i] = 1;
    }
    init(1, 0, n-1);
    cin >> q;
    for(ll i = 0;i<q;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            if(c % 2 == 0) c = 0;
            else c = 1;
            update(1,0,n-1,b-1,c);
        }
        else if(a == 2){
            cout << (c-b+1) - query(1,0,n-1,b-1,c-1) << "\n";
        }
        else{
            cout << query(1,0,n-1,b-1,c-1) << "\n";
        }
    }

    return 0;
}
