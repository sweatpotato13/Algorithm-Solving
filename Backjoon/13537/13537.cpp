#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/13537
const int MAXN = 100001;
vector<ll> tree[MAXN * 4];
void update(ll index, ll target, ll value, ll start, ll end) {
	if (target < start || target > end)
		return;
	tree[index].push_back(value);
	if (start != end) {
		ll mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

ll query(ll index, ll value, ll left, ll right, ll start, ll end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index].end() - upper_bound(tree[index].begin(), tree[index].end(), value);
	else {
		ll mid = (start + end) / 2;
		return query(index * 2, value, left, right, start, mid) +
			query(index * 2 + 1, value, left, right, mid + 1, end);
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        ll e;
        cin >> e;
        update(1,i,e,1,n);
    }
	ll range = MAXN * 4;
	for (int i = 1; i < range; ++i)
		sort(tree[i].begin(), tree[i].end());
    ll m;
	cin >> m;
	while (m--) {
    	ll i, j, k;
		cin >> i >> j >> k;
		cout << query(1, k, i, j, 1, n) << '\n';
	}


	return 0;
}
