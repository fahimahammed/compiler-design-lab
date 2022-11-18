#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

string grammar[] = { "E+E","E-E","E*E","E/E","(E)","a","b","c" };


int checkOperator(char ch) {
    switch (ch) {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    default:
        return -1;
    }
}

void syntaxTree(string exp){
    int len, index, i;
    bool startBracket=false;
    string ans;
    len = exp.size();
    ans = "E";
    cout << ans << endl;

    for (i = 0; i < len; i++) {

        index = checkOperator(exp[i]);

        if (index != -1 ) {
            ans.pop_back();
            if(startBracket){
                ans.pop_back();
                ans = ans + grammar[index] + ')';
                startBracket = false;
            }
            else{
                ans += grammar[index];
                if(index == 4) startBracket = true;
                cout << ans << endl;
            }
            
            //cout << ans << endl;
        }
    }

    for (i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] == 'E') {
            ans[i] = exp[i];
            cout << ans << endl;
        }
    }

}

int main() {
    string str;
    cin >> str;

    syntaxTree(str);
    
    return 0;
}