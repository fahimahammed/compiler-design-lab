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

bool isFloatVariable(string token){
    for (int i = 0; i < token.size(); i++) {
        if (i == 0) {
            if (!(token[i] >= 'a' && token[i] <= 'h') && !(token[i] >= 'A' && token[i] <= 'H') && !(token[i] >= 'o' && token[i] <= 'z') && !(token[i] >= 'O' && token[i] <= 'Z')) return false;
        } else {
            if (!(token[i] >= '0' && token[i] <= '9') && !(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= 'A' && token[i] <= 'Z'))  return false;
        }
    }
    return true;
}

bool checkFloat(string token, int length){
    bool firstZero=false, period = false;
    int count = 0;
    for (int i = 0; i < token.size(); i++) {

        if(!period){
            if (i == 0 && token[i] == '0')  firstZero = true;    
            else if(token[i] != '.' && firstZero) return false;

            else if(i == 0){
                if(!(token[i] >= '1' && token[i] <= '9')) return false;
            }
            else if(i > 0 && token[i] == '.')  period = true;
        }
        else{
            if(token[i] >= '0' && token[i] <= '9' && (length ? count < 2 : count > -1)){
                count++;
            }
            else return false; 
        }
    }
    return period;
}

bool isFloatNumber(string token){
    return checkFloat(token, true);
}

bool isDoubleNumber(string token){
    return checkFloat(token, false);
}

bool isChar(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

bool checkTypeVariable(string token, char a, char b){
    if(token.size() < 4 || token[0] != a || token[1] != b || token [2] != '_') return false;

    for(int i=3; i < token.size(); i++){
        if(!isChar(token[i]) && !isDigit(token[i])) return false;
    }
    return true;
}

bool isCharVariable(string token){
    return checkTypeVariable(token, 'c', 'h');
}

bool isBinaryVariable(string token){
    return checkTypeVariable(token, 'b', 'n');
}

bool isBinaryNumber(string token){
    if(token.size() < 2 || token[0] != '0' || token[1] != '0' && token[1] != '1') return false;
    for(int i=2; i < token.size(); i++){
        if(token[i] != '0' && token[i] != '1') return false;
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
            } else if (isShortInt(token)) {
                cout<< token << "\t- ShortInt Number" <<endl;
            } else if (isLongInt(token)) {
                cout<< token << "\t- LongInt Number" <<endl;
            }
            else if(isFloatVariable(token)){
                cout<< token << "\t- Float Variable" <<endl;
            }else if(isFloatNumber(token)){
                cout<< token << "\t- Float Number" <<endl;
            }else if(isDoubleNumber(token)){
                cout<< token << "\t- Double Number" <<endl;
            }else if(isCharVariable(token)){
                cout<< token << "\t- Character Variable" <<endl;
            }else if(isBinaryVariable(token)){
                cout<< token << "\t- Binary Variable" <<endl;
            }else if(isBinaryNumber(token)){
                cout<< token << "\t- Binary Number" <<endl;
            } else {
                cout<< token << "\t- Invalid Input" <<endl;
            }
            token = "";
        } else {
            token += expression[i];
        }
    }
}

int main() {
    string exp = "Iiaz3 *3ij 123 12345 12s345 hx34Z Zci4V C34z0 0.1 0.12 121.12 12.1212 ch_12a bn_3s 012 011 11100";
    cout << "String: " << exp << endl;
    LexicalAnalyzer(exp);
}