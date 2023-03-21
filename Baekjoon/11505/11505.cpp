#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/11505
vector<ll> tree;
vector<ll> v;
#define MOD 1000000007
void init(ll node, ll start, ll end){
    if(start == end){
        tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
    return;
}
ll mul(ll node, ll start, ll end, ll left, ll right){
    if(left > end || right < start) return 1;
    else if(left <= start && right >= end) return tree[node];
    else{
        return (mul(node*2, start, (start+end)/2, left, right) *
                mul(node * 2 + 1, (start+end)/2+1, end, left, right)) % MOD;
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
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin >> n >> m >> k;
    ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
    tree.resize(tree_size);
    v.resize(n+1);
    for(ll i = 0;i<n;i++){
        cin >> v[i];
    }
    init(1, 0, n-1);
    for(ll i = 0;i<m+k;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1,0,n-1,b-1,c);
        }
        else{
            ll p = mul(1,0,n-1,b-1,c-1);
            cout << p << "\n";
        }
    }

    return 0;
}
