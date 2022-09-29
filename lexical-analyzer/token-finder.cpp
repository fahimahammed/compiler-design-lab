#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool isKeyword(string token){
    string keyword[32] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    for(int i=0; i<32; i++){
        if(keyword[i] == token) return true;
    }
    return false;
}

bool isIdentifier(string token){
    if(!(token[0] >= 'a' && token[0] <= 'z') && !(token[0] >= 'a' && token[0] <= 'z')) return false;
    for(int i=1; i<token.size(); i++){
        if(!(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= '0' && token[i] <= '9') && token[i] != '_') return false;
    }
    return true;
}

bool isOperator(string token){
    string op = "+-*/";
    for(int i=0; i<op.size(); i++){
        if(op[i] == token[0]) return true;
    }
    return false;
}

string LaxicalAnalyzer(string word){
    if(isKeyword(word)) return "Keyword";
    else if(isIdentifier(word))  return "Identifier";
    else if(isOperator(word)) return "Arithmetic Operator";
    else return "Invalid";
}

int main(){
    string word = "-";
    //cout << "Enter a string: ";
    //cin >> word;
    cout << LaxicalAnalyzer(word) << endl;
    return 0;
}