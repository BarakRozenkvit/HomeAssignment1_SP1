#include <stdio.h> 
#include "NumClass.h"

int main(){
    int x = 0;
    int y = 0;
    //printf("Enter Two Numbers: \n");
    scanf("%d%d",&x,&y);
    int min = 0;
    int max = 0;
    if(x>y){
        max = x;
        min = y;
    }
    else{
        max = y;
        min = x;
    }
    printf("The Armstrong numbers are:");
    for(int i=min;i<=max;i++){
        int result = isArmstrong(i);
        if(result){printf(" %d",i);}
    }
    printf("\nThe Palindromes are:");
    for(int i=min;i<=max;i++){
        int result = isPalindrome(i);
        if(result){printf(" %d",i);}
    }
    printf("\nThe Prime numbers are:");
    for(int i=min;i<=max;i++){
        int result = isPrime(i);
        if(result){printf(" %d",i);}
    }
    printf("\nThe Strong numbers are:");
    for(int i=min;i<=max;i++){
        int result = isStrong(i);
        if(result){printf(" %d",i);}
    }
    printf("\n");
    return 0;
}