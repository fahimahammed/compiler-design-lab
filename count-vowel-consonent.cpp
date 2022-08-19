#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

bool isVowel(char c){
    char ch = tolower(c);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}

bool isConsonent(char c){
    char ch = tolower(c);
    if((ch >= 'a' && ch <= 'z') && !isVowel(c)) return true;
    return false;
}

int main()
{
    char c;
    int vowel=0, consonent=0;
    ifstream readFile("input.txt");
    
    if(!readFile){
        cout<<"Cannot open file"<<endl;
    }
    while(!readFile.eof()){
        readFile.get(c);
        if(isVowel(c)) vowel++;
        else if(isConsonent(c)) consonent++;
    }
    cout<<"result: "<<endl;
    cout<<"Number of Vowel: "<< vowel<<endl;
    cout<< "Number of Consonent: "<< consonent<<endl;
    return 0;
}