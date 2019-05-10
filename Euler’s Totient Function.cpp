#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#define           ll               long long int

int phi(int n)
{
	int result = n;
	for (int p = 2; p * p <= n; ++p) {
		if (n % p == 0) {
			while (n % p == 0){
				n = n/ p;
			}
			result =result- result / p;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}


int main()
{
	int n;
	while(1)
    {
	cin>>n;
	if(n==0){
        break;
	}
	cout<<phi(n)<<endl;
    }
	return 0;
}
