#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/10868
vector<int> min_tree;
vector<ll> v;
void init(int node, int start, int end){
    if(start == end){
        min_tree[node] = v[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    return;
}
 
int find(int node, int a, int b, int left, int right){
    if(left > b || right < a) return 2100000000;
    if(a <= left && right <= b){
        return min_tree[node];
    }
    int l, r;
    l = find(node * 2, a, b, left, (left + right) / 2);
    r = find(node * 2 + 1, a, b, (left + right) / 2 + 1, right);
    return min(l, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    int tree_size = (1 << (((int)ceil(log2(n)) + 1)));
    min_tree.resize(tree_size);
    v.resize(n+1);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    init(1, 0, n-1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int p = find(1, a-1, b-1, 0, n-1);
        cout << p << "\n";
    }


    return 0;
}
