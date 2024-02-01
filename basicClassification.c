#include "NumClass.h"

int isStrong(int n){
    int factorialArray[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    int num = n;
    int result = 0;
    
    while (n>0){
        int digit = n%10;
        result += factorialArray[digit];
        n-=digit;
        n=n/10;
    }
    
    return result==num;
}

int isPrime(int n){
    if(n==0 || n==1){return 0;}
    int i=2;
    float res = 0.0;
    while(i*i<=n){
        res = (float)n/i;
        int c =(int)res;
        if(res-c==0){
            return 0;
        }
        i++;
    }
    return 1;    
}
    
