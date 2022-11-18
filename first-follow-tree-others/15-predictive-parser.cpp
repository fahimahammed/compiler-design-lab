#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<iterator>
#include<stack>
using namespace std;

map <pair <char, char>, string> productionRules;

void predictiveParser(string str){
    str = str + '$';
    stack<pair<char, int>>stk;

    stk.push({'$', 0});
    stk.push({'E', 0});

    int i = 0;
    while(true){
        char top = stk.top().first;
        int level = stk.top().second;

        if(top == '$' && str[i] == '$'){
            cout << "Success" << endl;
            break;
        }

        if(top == str[i] && top != '$'){
            stk.pop();
            i = i + 1;
        }

        else{
            if(productionRules[{top, str[i]}] != ""){
                string temp = productionRules[{top, str[i]}];
                stk.pop();

                int tempLevel = level;
                cout<<"Temp level : "<<tempLevel<<endl;
                while(tempLevel--){
                    cout << "   " ;
                }
                

                cout << top << "->" << temp << endl;

                if(temp != "#"){
                    for ( int j = temp.length()-1; j>=0; j--){
                        stk.push({ temp[j], level+1});
                    }
                }
            }
        }
    }
}

int main(){
    string str = "(x*x)*(x*(x))";

    productionRules [{'E', 'x'}] = "TQ";
    productionRules [{'E', '('}] = "TQ";
    productionRules [{'Q', '+'}] = "+TQ";
    productionRules [{'Q', ')'}] = "#";
    productionRules [{'Q', '$'}] = "#";
    productionRules [{'T', 'x'}] = "FR";
    productionRules [{'T', '('}] = "FR";
    productionRules [{'R', '+'}] = "#";
    productionRules [{'R', '*'}] = "*FR";
    productionRules [{'R', ')'}] = "#";
    productionRules [{'R', '$'}] = "#";
    productionRules [{'F', 'x'}] = "x";
    productionRules [{'F', '('}] = "(E)";

    predictiveParser(str);

    return 0;
}