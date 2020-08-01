#include <string>
#include <vector>

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

string solution(string s) {
    string answer = "";
    sort(all(s),greater<int>());
    answer = s;
    return answer;
}
