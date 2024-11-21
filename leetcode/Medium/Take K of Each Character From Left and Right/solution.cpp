#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        map<char, int> m;

        for(int i = 0;i<n;i++) { m[s[i]]++; }

        if (m['a'] < k || m['b'] < k || m['c'] < k) {
            return -1;
        }

        int ans = n;
        int l = 0, r = 0;
        map<char, int> cnt;
        while(r < n){
            cnt[s[r]]++;
            r++;
            while(cnt['a'] > m['a']-k || cnt['b'] > m['b']-k || cnt['c'] > m['c']-k){
                cnt[s[l]]--;
                l++;
            }
            ans = min(ans, n-r+l);
        }

        return ans;
    }
};