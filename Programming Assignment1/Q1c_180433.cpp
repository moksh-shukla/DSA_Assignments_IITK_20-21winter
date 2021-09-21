#include <iostream>
#include <cstdio>
#include <time.h>

using namespace std;

#define ll long long int

int mod = 1000000007;
int main()
{
        ll n;
        cin>>n;
        if(n==0)
            cout<<1;
        else if(n==1)
            cout<<3;
        else{
        ll U1, D1, tempU, tempD, U, D;
        U1 = 3, D1 = 1;
        n=n-1;
        tempU = U1, tempD = D1;
        while(n--){
            U = ((3*tempU)%mod + tempD%mod)%mod;
            D = (tempU%mod + (3*tempD)%mod)%mod;
            tempU = U, tempD = D;
        }
            
        cout<<U;   
        return 0;   
    }

}