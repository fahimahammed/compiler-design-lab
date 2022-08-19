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
                cout<< word << "\t-> constent."<<endl;
            }
            else{
                cout<< word << "\t-> identifier."<<endl;
            }
        }
    }

    // readFile.close();
    return 0;
}