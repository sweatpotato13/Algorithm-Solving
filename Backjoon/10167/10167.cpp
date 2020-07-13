#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/10167
ll max(ll a, ll b, ll c, ll d,ll e) {
    return max(max(a, b), max(c, max(d, e)));
}
struct mseg {
    ll lsum, rsum, tsum, msum;
};
struct element {
    ll x, y, w;
    bool operator<(const element &A)const {
        return x < A.x;
    }
};
vector<ll> ypos;
ll get_ypos(ll pos) {
    return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}
mseg tree[4 * 3000];
vector<ll> v;
ll query(ll node, ll start, ll end, ll left, ll right){
	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return tree[node].msum;
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
		tree[node].tsum += diff;
        tree[node].lsum += diff;
		tree[node].rsum += diff;
		tree[node].msum += diff;

		return;
	}
	else{
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
        tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].tsum + tree[node * 2 + 1].lsum);
        tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].tsum + tree[node * 2].rsum);
        tree[node].tsum = tree[node * 2].tsum + tree[node * 2 + 1].tsum;
        tree[node].msum = max(tree[node * 2].rsum + tree[node * 2 + 1].lsum, tree[node * 2].msum, tree[node * 2 + 1].msum, tree[node].lsum, tree[node].rsum);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    element ele[n+1];
    for(int i = 0;i<n;i++){
        ll x,y,w;
        cin >> x >> y >> w;
        ele[i] = {x,y,w};
        ypos.push_back(y);
    }
    ll res = 0;
    sort(ele, ele + n);
    sort(all(ypos));
    ypos.erase(unique(all(ypos)), ypos.end());
    const ll MAX_Y = ypos.size();
    for (int i = 0; i < n; i++) {
        memset(tree, 0, sizeof(tree));
        if (i&&ele[i].x == ele[i - 1].x)
            continue;
        for (int j = i; j < n; j++) {
            ll pos = get_ypos(ele[j].y);
            update(1,0,MAX_Y-1,pos,ele[j].w);
            if (j != n - 1 && ele[j].x == ele[j + 1].x)
                continue;
            ll q = query(1,0,MAX_Y-1, 0, MAX_Y - 1);
            res = max(q, res);
        }
    }
    cout << res;
	return 0;
}
