#include <string>
#include <vector>

using namespace std;

string ans[2] = {"Odd","Even"};
string solution(int num) {
    string answer = "";
    if(num&1) answer = ans[0];
    else answer = ans[1];
    return answer;
}
