#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/14003
vector<ll> v;
vector<ll> dp;
vector<pair<ll,ll>> ans;
int lower(int start, int end, int target)
{
    int mid;
    while (end - start > 0){
        mid = (start + end) / 2; 
        if (dp[mid] < target)
            start = mid + 1;
        else
            end = mid;
   }
    return end + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        if(dp.empty()) {
            dp.push_back(v[i]);
            ans.push_back({1,v[i]});
        }
        else{
            if(dp.back() < v[i]){
                dp.push_back(v[i]);
                ans.push_back({dp.size(),v[i]});
            }
            else{
                auto it = lower(0,dp.size()-1,v[i]);
                ans.push_back({it,v[i]});
                dp[it-1] = v[i];
            }
        }
    }
    stack<ll> s;
    ll len = dp.size();
    cout << dp.size() << "\n";
    for(int i = ans.size()-1;i>=0;i--){
        if(ans[i].first == len){
            s.push(ans[i].second);
            len--;
        }
        if(len == -1) break;
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
	return 0;
}
