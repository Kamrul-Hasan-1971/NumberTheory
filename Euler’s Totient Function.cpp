#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define           ll               long long int



ll phi(ll a)
{
    ll res=a;
    for(ll i=2; i*i<=a;i++){
        if(a%i==0){
            while(a%i==0){
                a=a/i;
            }
            res=res-(res/i);
        }
    }
    if(a>1){
        res=res-(res/a);
    }
    return res;
}


int main()
{
    ll a;
    while(1)
    {
        cin>>a;
        if(a==0){
            break;
        }
        cout<<phi(a)<<endl;
    }
}
