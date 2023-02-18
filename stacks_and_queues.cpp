#include <stack>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;


bool isValid(string s) {
    stack<char> stack;
    unordered_map<char, char> matching {{'(',')'}, {'{','}'}, {'[',']'}};
    
    for (char c: s) {
        if (matching.find(c) != matching.end()) {
            stack.push(c);
        } 
        else {
            if (stack.empty()) {
                return false;
            }
            
            char previousOpening = stack.top();
            if (matching[previousOpening] != c) {
                return false;
            }
            
            stack.pop();
        }
    }
    
    return stack.empty();
}

string removeDuplicates(string s) {
    // Strings in C++ are mutable
    string ans = "";
    for (char c: s) {
        if (!ans.empty() && ans.back() == c) {
            ans.pop_back();
        } 
        else {
            ans.push_back(c);
        }
    }
    
    return ans;
}

int main() {
    assert(isValid("[({({[]})})]"));
    assert(!isValid("[{(])}]"));

    assert(removeDuplicates("aabccbab") == "ab");
}