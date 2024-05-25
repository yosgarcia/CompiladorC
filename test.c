#include <stdio.h>
#include "test2.c"
#define ll long long

ll function(ll x, ll y){
    if (-x){
        int w = 5;
    }
    return (x%y)+x;
}
int main(){
    ll x = 5.0;
    ll y = function(x,2);
    return 0;
}