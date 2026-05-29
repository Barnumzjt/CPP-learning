#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n*n;++i){
        cout<<setw(2)<<setfill('0')<<i;
        if(i%n==0)cout<<endl;
    }
    cout<<endl;
    int k=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            cout<<"  ";
        }
        for(int j=0;j<i+1;++j){
            cout<<setw(2)<<setfill('0')<<k;
            ++k;
        }
        if(i!=n-1)cout<<endl;
    }
    return 0;
}

