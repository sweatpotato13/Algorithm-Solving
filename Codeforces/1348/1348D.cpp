#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// http://codeforces.com/contest/1348/problem/D
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        for(int i = 1;i<n;i*=2){
            ans.push_back(i);
            n -= i;
        }
        if(n > 0){
            ans.push_back(n);
        }
        cout << ans.size()-1 << "\n";
        sort(all(ans));
        for(int i = 1;i<ans.size();i++){
            cout << ans[i] - ans[i-1] << " ";
        }
        cout << "\n";
    }
	return 0;
}