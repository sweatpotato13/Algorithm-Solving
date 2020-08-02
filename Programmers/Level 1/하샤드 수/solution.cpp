#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int digits = 0;
    int temp = x;
    while(temp){
        digits += temp % 10;
        temp /= 10;
    }
    if(x%digits) answer = false;
    return answer;
}
