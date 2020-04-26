#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/5676
vector<ll> tree;
vector<ll> v;
void init(ll node, ll start, ll end){
    if(start == end){
        tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
    return;
}
ll query(ll node, ll start, ll end, ll left, ll right){
    if(left > end || right < start) return 1;
    else if(left <= start && right >= end) return tree[node];
    else{
        return (query(node*2, start, (start+end)/2, left, right) *
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
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll n, k;
    while(cin >> n >> k){
        ll cnt = (k + 1) / 2;
        ll tree_size = (1 << (((ll)ceil(log2(n)) + 1)));
        tree.resize(tree_size,0);
        v.resize(n + 1,0);
        for(int i = 0;i<n;i++){
            int e;
            cin >> e;
            if(e > 0) v[i] = 1;
            else if(e == 0) v[i] = 0;
            else v[i] = -1;
        }
        init(1,0,n-1);
        for(int i = 0;i<k;i++){
            char a;
            int b,c;
            cin >> a >> b >> c;
            if(a == 'C'){
                if(c > 0) c = 1;
                else if(c == 0) c = 0;
                else c = -1;
                update(1,0,n-1,b-1,c);
            }
            else{
                int e = query(1,0,n-1,b-1,c-1);
                if(e > 0) cout << "+";
                else if(e == 0) cout << "0";
                else cout << "-";
            }
        }
        cout << "\n";
    }


    return 0;
}
