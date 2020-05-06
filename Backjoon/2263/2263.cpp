#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/2263
ll inorder[100001] ={0,};
ll postorder[100001] ={0,};
void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end){
        return;
    }
    int root = postorder[post_end];
    cout << root << ' ';
    int idx = inorder[root] - in_start;
    solve(in_start,inorder[root]-1,post_start,post_start+idx-1); //left
    solve(inorder[root]+1,in_end,post_start+idx, post_end-1); //right
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int j = 0;j<n;j++){
        ll e;
        cin >> e;
        inorder[e] = j;
    }
    for(int j = 0;j<n;j++){
        cin >> postorder[j];
    }
    solve(0,n-1,0,n-1);
	return 0;
}