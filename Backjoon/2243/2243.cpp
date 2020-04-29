#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
#define MAX 1000001
// https://www.acmicpc.net/problem/2243
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
int query(ll node, ll start, ll end, ll left, ll right){
    if (left > end || right < start)
        return 0;
    else if (left <= start && right >= end)
        return tree[node];
    else
    {
        return (query(node * 2, start, (start + end) / 2, left, right) + 
                   query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    }
}
void update(ll node, ll start, ll end, ll index, ll diff){
    if (index < start || index > end)
        return;
    if (start == end){
        tree[node] += diff;
        return;
    }
    update(node * 2, start, (start + end) / 2, index, diff);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
    ll n, m, t;
	cin >> n;
   	ll tree_size = (1 << (((ll)ceil(log2(MAX)) + 1)));
   	tree.resize(tree_size,0);
   	v.resize(MAX,0);
	while(n--){
		int a,b,c;
		cin >> a;
		if(a == 1){
			cin >> b;
			int e = kth(1,0,MAX,b);
			cout << e << "\n";
			update(1,0,MAX,e,-1);
		}
		else{
			cin >> b >> c;
			update(1,0,MAX,b,c);
		}
	}

	return 0;
}