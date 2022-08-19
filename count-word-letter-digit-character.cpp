#include <iostream>
#include <fstream>
#include<string.h>
#include<cstdlib>
using namespace std;

void counter(){
    char c;
    int character=0, digit=0, word=0, lines=0, blank=0;
    ifstream readFile("input.txt");
    while(!readFile.eof()){
        readFile.get(c);

        if(c != ' ' && c != '\n'){
            ++character;
        }

        if(isdigit(c)){
            ++digit;
        }

        if(c==' '){
            ++blank;
        }

        if(c==' ' || c=='\n' || c=='\0'){
            ++word;
            //cout<<" 1 ";
        }

        if(c=='\n' || c=='\0'){
            ++lines;
        }
    }
    cout<<"character: "<<character<<endl;
    cout<<"digit: "<<digit<<endl;
    cout<<"word: "<<word<<endl;
    cout<<"line: "<<lines<<endl;
    cout<<"blanks: "<<blank<<endl;
}

int main()
{
    counter();
    return 0;
}
