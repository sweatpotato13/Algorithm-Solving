#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
#define MAX 5000001
// https://www.acmicpc.net/problem/2517
vector<ll> tree;
vector<ll> v;
vector<pair<ll,ll>> arr;
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
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.second < b.second;
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
	for(int i = 0;i<n;i++){
		int e;
		cin >> e;
        arr.push_back({e,i});
	}
    sort(all(arr));
    for(int i = 0;i<n;i++){
        arr[i].first = i;
    }
    sort(all(arr),cmp);
    for(int i = 0;i<n;i++){
        update(1,0,MAX,arr[i].first,1);
		int s = query(1,0,MAX,arr[i].first,MAX);
		cout << s << "\n";
    }

	return 0;
}