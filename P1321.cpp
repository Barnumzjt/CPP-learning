#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int boy=0,girl=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.')continue;
        else if(s[i]=='b')boy++;
        else if(s[i]=='o'&&s[i-1]!='b')boy++;
        else if(s[i]=='y'&&s[i-1]!='o')boy++;
        else if(s[i]=='g')girl++;
        else if(s[i]=='i'&&s[i-1]!='g')girl++;
        else if(s[i]=='r'&&s[i-1]!='i')girl++;
        else if(s[i]=='l'&&s[i-1]!='r')girl++;
    }
    cout<<boy<<endl<<girl;
    return 0;
}
