#include <time.h>
#include <cstdio>
#include <iostream>

using namespace std;

#define ll long long int

int mod = 1000000007;

ll D(ll n);
ll U(ll n){
    if(n == 1)
        return 3;
    return ((3*U(n-1))%mod+D(n-1)%mod)%mod;
}

ll D(ll n){
    if(n == 1)
        return 1;
    return (U(n-1)%mod+ (3*D(n-1))%mod);
}

int main() {
    ll n;
    cin>>n;
    if(n==0) 
        cout<<1;
    else
        cout<<U(n);
    
}