#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

bool isLetter(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
    return false;
}

bool isDigit(char c){
    if(c >= '0' && c <= '9') return true;
    return false;
}

void printArray(string msg, char arr[], int n){
    cout<<msg;
    for(int i=0; i<n; i++){
        cout<< arr[i] << ", ";
    }
    cout<<endl;
}


int main()
{
    string str;
    char c, letter[500], digit[500], other[500];
    int i=0, j=0, k=0;
    ifstream readFile("input.txt");

    if(!readFile){
        cout<<"Cannot open file"<<endl;
    }
    while(!readFile.eof()){
        readFile.get(c);
        if(isLetter(c)){
            letter[i++] = c;
        }
        else if(isDigit(c)){
            digit[j++]=c;
        }
        else if(!isLetter(c) && !isDigit(c) && c != ' ' && c != '\n' && c != '\0'){
            other[k++]=c;
        }
    }
    printArray("Letters: ",letter, i);
    printArray("Digits: ", digit, j);
    printArray("Other Character: ",other, k);
    
    return 0;
}