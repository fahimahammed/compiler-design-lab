#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

bool isOperator(char ch){
    string operators = "+-*/%=";
    for(auto i : operators){
        if(ch == i) return true;
    }
    return false;
}

bool isKeyword(char word[]){
    char keyword[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    for(auto x: keyword){
        if(!strcmp(x, word)){
            return true;
            break;
        }
    }
    return false;
}

bool isConst(char word[]){
    int count=0;
    for(int i=0; i<strlen(word); i++){
        if(isdigit(word[i])) count++;
    }
    if(strlen(word) == count) return true;
    return false;
}

bool checkInt(string token){
    bool flag = true;
    for (int i = 0; i < token.size(); i++) {
        if (i == 0) {
            if (token[i] >= '1' && token[i] <= '9') {
            } else {
                flag = false;
            }
        } else {
            if (token[i] >= '0' && token[i] <= '9') {} 
            else {
                flag = false;
            }
        }
    }
    return flag;
}

bool isShortInt(string token) {
    bool flag = true;

    if (token.size() > 4) {
        flag = false;
    } else {
        flag = checkInt(token);
    }
    return flag;
}

bool isLongInt(string token) {
    bool flag = true;

    if(token.size() < 4){
        flag = false;
    }
    else{
        flag = checkInt(token);
    }
    return flag;
}

bool checkFloat(string token, int length){
    bool flag = true, firstZero=false, period = false;
    int count = 0;
    for (int i = 0; i < token.size(); i++) {

        if(!period){
            if (i == 0 && token[i] == '0')  firstZero = true;    
            else if(token[i] != '.' && firstZero) flag = false;

            else if(i == 0){
                if(token[i] >= '1' && token[i] <= '9'){}
                else flag = false;
            }
            else if(i > 0 && token[i] == '.') period = true;
        }
        else{
            if(token[i] >= '0' && token[i] <= '9' && (length ? count < 2 : count > -1)){
                count++;
            }
            else flag = false; 
        }
    }
    return flag;
}

bool isFloatNumber(string token){
    return checkFloat(token, true);
}

bool isDoubleNumber(string token){
    return checkFloat(token, false);
}

int main(){
    char c, word[100];
    int i=0, j=0;
    ifstream readFile("input.txt");
    while(!readFile.eof()){
        readFile.get(c);
        if(isOperator(c)){
            cout<< c << "\t-> operator"<< endl;
        }

        if(isalnum(c)){
            word[i++] = c;
        }
        else if((c == ' ' || c == '\n' || c == ',' || c == ';') && (i != 0)){
            word[i] = '\0';
            //cout<<word<<" ";
            i = 0;
            if(isKeyword(word)){
                cout<< word << "\t-> keyword."<<endl;
            }
            else if(isConst(word)){
                if(isShortInt(word)){
                    cout<< word << "\t-> Short Integer."<<endl;
                }
                else if(isLongInt(word)){
                    cout<< word << "\t-> Long Integer."<<endl;
                }else if(isFloatNumber(word)){
                    cout<< word << "\t-> Float Number."<<endl;
                }else if(isDoubleNumber(word)){
                    cout<< word << "\t-> Double Number."<<endl;
                }
            } 
            else{
                cout<< word << "\t-> identifier."<<endl;
            }
        }
    }

    readFile.close();
    return 0;
}