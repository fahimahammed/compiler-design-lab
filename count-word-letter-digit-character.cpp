#include <iostream>
#include <fstream>
#include<string.h>
#include<cstdlib>
using namespace std;

int main()
{
    char c, line[1000];

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
            cout<<" 1 ";
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
    return 0;
}
