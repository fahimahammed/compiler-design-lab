#include<iostream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

bool isKeyword(string token){
    string keyword[50] = {"int","namespace","struct","new","switch","and","delete","do","not","this",
                     "double","auto","nullptr","throw","else","true","enum","or","try","bool","typedef",
                     "break","private","case","typename","catch","false","public","union","char","float",
                     "register","unsigned","for","return","class","goto","short","void","if","signed","const",
                     "sizeof","int","static","while","long","xor","continue", "main"
                    };
    for(int i=0; i<50; i++){
        if(token == keyword[i]) return true;
    }
    return false;
}

void tokenFinder(string exp){
    string token="";
    int size = exp.size();
    for(int i=0; i<size;  i++){
        if(exp[i] == ' ' || i == size-1){
            if(i==size-1 && exp[size-1] != ' ') token += exp[i];
            if(isKeyword(token)){
                cout << token << "\t- Keyword" << endl;
            }
            //cout << token<< endl;
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
    tokenFinder(str);
    return 0;
}