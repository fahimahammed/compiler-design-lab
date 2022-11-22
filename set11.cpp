#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isIntVariable(string token) {
    if (!(token[0] >= 'i' && token[0] <= 'n') && !((token[0] >= 'I' && token[0] <= 'N'))) return false;

    for (int i = 1; i < token.size(); i++) {
        if (!(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= 'A' && token[i] <= 'Z') && !(token[i] >= '0' && token[i] <= '9')) return false;
    }
    return true;
}

bool checkInt(string token){
    for (int i = 0; i < token.size(); i++) {
        if (i == 0) {
            if (!(token[i] >= '1' && token[i] <= '9')) return false;
        } else {
            if (!(token[i] >= '0' && token[i] <= '9')) return false;
        }
    }
    return true;
}

bool isShortInt(string token) {
    if (token.size() > 4) return false;
    else return checkInt(token);
}

bool isLongInt(string token) {
    if(token.size() < 4) return false;
    else return checkInt(token);
}

bool checkConstrant(string token){
    for(int i=0; i<token.size(); i++){
        if(token[0] != token[i]) {
            return false;
        }
    }
    return true;
}

bool checkKeyword(string token){
    if(token[0] != '1') {
        return false;
    }
    for(int i=0; i<token.size()-1; i++){ 
        // cout << token[i] + 1 << " - " << token[i+1] + 0<<endl;;
        if((token[i]+1) != token[i+1]+0) {
            return false;
        }
    }
    return true;
}


void LexicalAnalyzer(string expression) {
    string token = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1){
                token += expression[i];
            }   
            if (isIntVariable(token)) {
                cout<< token << "\t- Int variable" <<endl;
            }
            else if(checkKeyword(token)){
                cout<< token << "\t- Keyword" <<endl;
            }
            else if(checkConstrant(token)){
                cout<< token << "\t- Constant Integer" <<endl;
            } else if (isShortInt(token)) {
                cout<< token << "\t- ShortInt Number" <<endl;
            } else if (isLongInt(token)) {
                cout<< token << "\t- LongInt Number" <<endl;
            }
            else {
                cout<< token << "\t- Invalid Input" <<endl;
            }
            token = "";
        } else {
            token += expression[i];
        }
    }
}

int main() {
    string exp = "j45 143 123422 1111 2222 3333 11112 12345 13456";
    cout << "String: " << exp << endl;
    LexicalAnalyzer(exp);
}