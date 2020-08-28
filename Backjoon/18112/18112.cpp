#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/18112
ll isVisited[10101] = {0,};
ll bits[1001] ={0,};
ll lls,lle;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	for (int i = 0; i < 12; i++) bits[i+1] = (1 << i);
    string s,e;
    cin >> s >> e;
    ll temp = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '1')
            temp |= (1LL << (s.length()-1-i));
    }
    lls = temp;
    temp = 0;
    for(int i = 0;i<e.length();i++){
        if(e[i] == '1')
            temp |= (1LL << (e.length()-1-i));
    }
    ll ans = 0;
    lle = temp;
    queue<pll> q;
    q.push({lls,0});
    isVisited[lls] = true;
    while(!q.empty()){
        pll cur = q.front();
        q.pop();
        if(cur.first == lle){
            ans = cur.second;
            break;
        }
        if(cur.first > 1 && !isVisited[cur.first-1]){
            isVisited[cur.first-1] = true;
            q.push({cur.first-1,cur.second+1});
        }
        if(cur.first + 1 < 1024 && !isVisited[cur.first+1]){
            isVisited[cur.first+1] = true;
            q.push({cur.first+1,cur.second+1});
        }
		int i;
		for (i = 10; i >= 0 && bits[i]>cur.first; i--){} 
		for (i = i - 1; i >= 0; i--) {
			int tmp = (cur.first ^ bits[i]);
			if (!isVisited[tmp]){
				isVisited[tmp] = true;
				q.push({ tmp,cur.second + 1 });
			}
		}
    }
    cout << ans;

    return 0;
}


