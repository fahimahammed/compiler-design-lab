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

void printArray(string msg, char arr[], int n){
    cout<<msg;
    for(int i=0; i<n; i++){
        cout<< arr[i] << ", ";
    }
    cout<<endl;
}

int main()
{
    char c, vowel[500], consonent[500];
    int vowelCount=0, consonentCount=0;
    ifstream readFile("input.txt");
    
    if(!readFile){
        cout<<"Cannot open file"<<endl;
    }
    while(!readFile.eof()){
        readFile.get(c);
        if(isVowel(c)) vowel[vowelCount++] = c;
        else if(isConsonent(c)) consonent[consonentCount++] = c;
    }
    cout<<"result: "<<endl;
    cout<<"Number of Vowel: "<< vowelCount<<endl;
    printArray("Vowels: ", vowel, vowelCount);
    cout<< "Number of Consonent: "<< consonentCount<<endl;
    printArray("Consonents: ", consonent, consonentCount);
    return 0;
}