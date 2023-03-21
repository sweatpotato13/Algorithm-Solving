#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/3653
vector<ll> tree;
vector<ll> v;
#define MAX 100001
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
        tree[node] = diff;
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
    cin >> t;
   	ll tree_size = (1 << (((ll)ceil(log2(MAX+MAX)) + 1)));
   	tree.resize(tree_size,0);
   	v.resize(MAX,0);
	while(t--){
		cin >> n >> m;
		fill(all(tree),0);
		fill(all(v),0);
		for(int i = m+1;i<=n+m;i++){
			update(1,1,n+m,i,1);
			v[i-m] = i;
		}
		int temp = m;
		for(int i = 0;i<m;i++){
			int s;
			cin >> s;
			int e = query(1,1,n+m,1,v[s]-1);
			cout << e << " ";
			update(1,1,n+m,v[s],0);
			v[s] = temp--;
			update(1,1,n+m,v[s],1);
		}
		cout << "\n";
	}



	return 0;
}