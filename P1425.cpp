#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int m,n;
    if(b>d){
        m=c-a-1;
        n=60-b+d;
    }
    else if(b<=d){
        m=c-a;
        n=d-b;
    }
    cout<<m<<" "<<n;
    return 0;
}
