#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

#define ll long long int

const int a = 2;
ll mod = 1000000007;
ll tria[2][2] = {{3,1},
                 {1,3}};

void matrixmultsq(ll arr1[a][a], ll arr2[a][a]){
    ll temp[a][a];
    for(ll i=0; i<a; i++){
        for(ll j=0; j<a; j++){
            temp[i][j] =0;
            for(ll k=0; k<a; k++)
                temp[i][j] = (temp[i][j]+((arr1[i][k]%mod)*(arr2[k][j]%mod))%mod)%mod;
        }
    }
    for (ll i=0; i<2; i++) 
        for (ll j=0; j<2; j++) 
            arr1[i][j] = temp[i][j]; 
}

void power(ll arr[a][a], ll n){
    if(n==1)
        return;
    power(arr,n/2);
    matrixmultsq(arr,arr);
    
    if(n%2!=0)
        matrixmultsq(arr,tria);
}

int main(){
    ll n;
    cin>>n;
    if(n==0)
        cout<<1<<","<<" "<<0;
    else{    
        ll A[2][2] = {{3,1},
                      {1,3}};
        power(A,n);
        cout<<A[0][0]<<","<<" "<<A[1][0];
    }
    
}