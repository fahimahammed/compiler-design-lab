#include<iostream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

bool checkIntVariable(string token){
    if( !(token[0] >= 'i' && token[0] <= 'n' || token[0] >= 'I' && token[0] <= 'N') ) return false;
    else{
        for(int i=1; i<token.size() ; i++){
            if(!((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9'))) return false;
        }
    }
    return true;
}

bool checkShortIntNum(string token){
    if(token.size() > 4 || token[0] == '0') return false;
    else{
        for(int i  = 1; i<token.size(); i++){
            if(!(token[i] >= '0' && token[i] <= '9')) return false;
        }
    }
    return true;
}

bool checkDouble(string token) {
    bool period = false, firstZero = false;
    int count =0;
    
    for(int i=0; i<token.size(); i++){
        if(!period){
            if(i==0 && token[0] == '0') firstZero = true;
            else if(token[i] != '.' && firstZero) return false;
            else if(i == 0){
                if(!(token[i] >= '1' && token[i] <= '9')) return false;
            }
            else if(token[i] == '.' && i>0) period = true;
        }
        else{
            if(!(token[i] >= '0' && token[i] <= '9')) return false;
            else count++;
        }
    }
    if(count < 3) return false;
    return period;
}

bool checkCharVariable(string token){
    if(token.size() < 4 || token[0] != 'c' || token[1] != 'h' || token[2] != '_') return false;
    for(int i=3; i<token.size() ; i++){
        if(!(token[i] >= '0' && token[i] <= '9') && !(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= 'A' && token[i] <= 'Z')) return false;
    }
    return true;
}

void lexicalAnalyzer(string exp){
    string token="";
    for(int i=0; i<exp.size(); i++){
        if(exp[i] == ' ' || i == exp.size()-1){
            if(i == exp.size()-1 && exp[i] != ' '){
                token += exp[i];
            }
            if(checkIntVariable(token)){
                cout << token << "\t- Integer Variable"<<endl;
            }
            else if(checkShortIntNum(token)){
                cout << token << "\t- Short Integer"<<endl;
            }
            else if(checkDouble(token)){
                cout << token << "\t- Double Number"<<endl;
            }
            else if(checkCharVariable(token)){
                cout << token << "\t- Character variable"<<endl;
            }
            else{
                cout << token << "\t- Undefined"<<endl;
            }
            
            token = "";
        }
        else{
            token += exp[i];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);

    lexicalAnalyzer(str);
    return 0;
}