#include <iostream>
using namespace std;
int main(){
    double sum=1;
    int k;
    cin>>k;
    int i=1;
    while(sum<=k){
        i++;
        sum+=1.0/i;
    }
    cout<<i;
    return 0;
}
