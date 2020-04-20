#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/9426
vector<ll> tree;
vector<ll> v;
#define MAX 65537
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
        return -1;
    else if (left <= start && right >= end)
        return tree[node];
    else
    {
        return max(query(node * 2, start, (start + end) / 2, left, right),
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
    ll n, k;
    cin >> n >> k;
    ll cnt = (k + 1) / 2;
    ll tree_size = (1 << (((ll)ceil(log2(MAX)) + 1)));
    tree.resize(tree_size,0);
    v.resize(n + 1,0);
    for (ll i = 1; i <= n; i++){
        cin >> v[i];
        update(1,0,MAX,v[i],1);
        if(i >= k){
            if(i != k){
                update(1,0,MAX,v[i-k],-1);
            }
            ll pos = kth(1,0,MAX,cnt);
            ans += pos;
        }
    }
    cout << ans << "\n";

    return 0;
}
