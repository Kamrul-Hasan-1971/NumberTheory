#include<bits/stdc++.h>
using namespace std;

bool permutations1(vector<int>&digits,int index)
{
    if(index == digits.size()){
        for( int dig : digits) cout<<dig;
        cout<<endl;
    }
    for(int i = index ; i < digits.size() ; i++)
    {
        swap(digits[index], digits[i]);
        permutations1(digits, index+1);
        swap(digits[index], digits[i]);
    }
}

bool permutations2(vector<int>&digits, int bit, int currentNum, int index)
{
    if(index == digits.size()) cout<<currentNum<<endl;
    for(int i = 0 ; i < digits.size() ; i++)
    {
        if(index == 0 && digits[i] == 0) continue;
        if(bit & (1 << i)) continue;
        permutations2(digits, bit | (1 << i), ((currentNum * 10)+digits[i]), index+1);
    }
}

int main() {
    while(true){
        int n ;
        cin >> n ;
        vector<int>digits;
        while(n > 0) {digits.push_back(n%10); n/=10;}
        permutations1(digits, 0);
        cout<<"Approach 2"<<endl;
        permutations2(digits, 0 , 0, 0);
    }
}



