#include<bits/stdc++.h>
using namespace std;

int isPowerOfX(long int n, long int X) {
    if(n <= 0) return -1;
    double power = log10(n)/log10(X);
    if(power - int(power) == 0) return int(power);
    return -1;
}

int main()
{
    long int n, X;
    while(true)
    {
        cin >> n >> X;
        cout<<isPowerOfX(n, X)<<endl;
    }
}
