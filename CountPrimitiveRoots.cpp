//                             Sara_Hasan <3                 //
//                          Thnx For Everything              //

#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define           ll               long long int

ll countPrimitiveRoots(ll p)
{
    int result = 1;
    for (ll i = 2; i < p; i++)
        if (__gcd(i, p) == 1)
            result++;

    return result;
}

int main()
{
    ll a;
    cin>> a ;
    cout<<countPrimitiveRoots( a - 1 );
    return 0 ;
}
