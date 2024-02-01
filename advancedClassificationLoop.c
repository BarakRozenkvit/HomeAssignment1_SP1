#include "NumClass.h"

int reverseNumber(int n){
    int result = 0;
    while (n>0){
        int digit = n%10;
        result = result*10;
        result+=digit;
        n-=digit;
        n=n/10;
    }
    return result;
}

int isPalindrome(int n){
    if(n%10 == 0){return 0;}
    return n == reverseNumber(n);
}


int isArmstrong(int n){
    int s = n;
    int p = n;
    int result = 0;
    int size=0;
    //Calculate size fo number
    while(s>0.1){
        s = s/10;
        size++;
    }
    
    while (p>0){
        int digit = p%10;
        int t = digit;
        //Calculate digit.powerOf(size)
        for(int i=0;i<size-1;i++){
            t=t*digit;
        }
        //Add to result
        result += t;
        p-=digit;
        p=p/10;
    }
    return result==n;
}
