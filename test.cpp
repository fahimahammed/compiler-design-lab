#include<bits/stdc++.h>
using namespace std;

bool isFloatVariable(string str)
{
    bool flag = false;
    if(str.size()==0) return flag;
    if((str[0]>='a' && str[0]<='h') || (str[0]>='A' && str[0]<='H') || (str[0]>='o' && str[0]<='z') || (str[0]>='O' && str[0]<='Z')) flag = true;
    else return flag;
    for(int i=1; i<str.size(); i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')) flag = true;
        else return false;
    }
    return flag;
}

bool isFloatNumber(string str)
{
    bool flag = false;
    int str_length = str.size();
    if(str_length<4) return flag;
    if(str[str_length-3]=='.' && (str[str_length-1]>='0' && str[str_length-1]<='9') && (str[str_length-2]>='0' && str[str_length-2]<='9')) flag = true;
    else return flag;
    int i=0;
    while(str[i]!='.')
    {
        if(i==0 && (str[i]>='1' && str[i]<='9')) flag = true;
        else if(i>0 && (str[i]>='0' && str[i]<='9')) flag = true;
        else {flag = false; break;}
        i++;
    }
    return flag;
}

bool isDoubleNumber(string str)
{
    bool flag = false;
    int i=0;
    while(str[i]!='.')
    {
        if(i==0 && (str[i]>='1' && str[i]<='9')) flag = true;
        else if(i>0 && (str[i]>='0' && str[i]<='9')) flag = true;
        else {flag = false; break;}
        i++;
    }
    if(flag == false) return flag;
    i++;
    int cnt = 0;
    while(i<str.size())
    {
        cnt++;
        if(str[i]>='0' && str[i]<='9') flag = true;
        else {flag = false; break;}
        i++;
    }
    if(cnt<3) flag = false;
    return flag;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    cout << str << endl;
    if(isFloatVariable(str)) cout << "Float Variable" << endl;
    else if(isFloatNumber(str)) cout << "Float Number" << endl;
    else if(isDoubleNumber(str)) cout << "Double Number" << endl;
    else cout << "Invalid Input or Undefined" << endl;
}