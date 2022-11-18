#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


string grammar[] = { "E->TR","R->+TR","T->FY","Y->*FY","F->(E)","R->#","Y->#","F->i" };
// epsilon = #
// E' = R
// T' = Y
// id = i
string FIRST[] = { "i(","+","i(","*","(","#","#","i" };

int numOfGrammer = 8;

string FOLLOW[20];
bool mark[500], visited[50];
char str[50];

string calcFirst(char ch, int c1, int c2) {
    int i, j;
    string ans = "";
    for (i = 0; i < numOfGrammer; i++) {
        if (ch == grammar[i][0]) {

            for (j = 0; j < FIRST[i].size(); j++) {

                if (FIRST[i][j] != '#'){
                    ans += FIRST[i][j];
                }                   
                else {
                    if (grammar[c1][c2 + 1] == '\0'){
                        //cout<<"Follow c1; "<<FOLLOW[c1]<<endl;
                        ans += FOLLOW[c1];
                    }                     
                    else if (!(grammar[c1][c2 + 1] >= 'A' && grammar[c1][c2 + 1] <= 'Z')){
                        ans += grammar[c1][c2 + 1];
                    }                       
                    else{
                        ans += calcFirst(grammar[c1][c2 + 2], c1, c2 + 1);
                    }     
                }
            }
        }
    }
    return ans;
}

void calcFollow() {
    int i, j, k;

    for (i = 0; i < numOfGrammer; i++) {

        if (FOLLOW[0].size() == 0){
            FOLLOW[i] += '$';
        }
        for (j = 0; j < numOfGrammer; j++) {
            for (k = 3; k < grammar[j].size(); k++) {
                cout<< "g-jk "<<grammar[j][k] <<" == g-i0 "<< grammar[i][0]<<endl;
                if (grammar[j][k] == grammar[i][0]) {
                    if (grammar[j][k + 1] == '\0'){
                        FOLLOW[i] += FOLLOW[j];
                    }
                    else if (grammar[j][k + 1] >= 'A' && grammar[j][k + 1] <= 'Z'){
                        //cout<<"f- "<<grammar[j][k+1]<<" j= "<<j<<" k+1= "<<k+1<<endl;
                        FOLLOW[i] += calcFirst(grammar[j][k + 1], j, k + 1);
                    }
                    else{
                        FOLLOW[i] += grammar[j][k + 1];
                    }
                }
            }
        }
    }
    cout << "********* FOLLOW **********" << endl;
    
    // for(i=0; i<5;i++){
    //     cout<<grammar[i][0] << " = { ";
    //     for(j=0; j<FOLLOW[i].size(); j++){
    //         cout<<" "<<FOLLOW[i][j];
    //         if(j != FOLLOW[i].size()-1){
    //             cout<<", ";
    //         }
    //     }
    //     cout<<" }"<<endl;
    // }
    for (i = 0; i < numOfGrammer; i++) {
        string tmp = "";
        for (j = 0; j < FOLLOW[i].size(); j++) {
            if (!mark[FOLLOW[i][j]]){
                tmp += FOLLOW[i][j];
            }  
            mark[FOLLOW[i][j]] = 1;
        }
        FOLLOW[i] = tmp;

        //cout<<"Follow : "<<grammar[i][0]<<" --> "<<FOLLOW[i]<<endl;

        memset(mark, 0, sizeof(mark));
        if (!visited[grammar[i][0] - 'A']) {
            if(grammar[i][0] == 'R'){
                cout <<"E'\t= " << "{ ";
            }
            else if(grammar[i][0] == 'Y'){
                cout <<"T'\t= " << "{ ";
            }
            else{
                cout << grammar[i][0] << "\t= " << "{ ";
            }
            
            for (j = 0; j < FOLLOW[i].size(); j++) {
                cout << FOLLOW[i][j];
                if (j != FOLLOW[i].size() - 1){
                    cout << ", ";
                }
                    
            }
            cout << " }" << endl;
        }
        visited[grammar[i][0] - 'A'] = 1;
    }

    

}

int main() {
    calcFollow();
    return 0;
}