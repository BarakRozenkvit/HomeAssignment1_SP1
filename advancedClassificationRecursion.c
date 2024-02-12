#include "NumClass.h"

int reverseNumberRec(int n,int result){
    int digit = n%10;
    result = result*10;
    result+=digit;
    n-=digit;
    if(n!=0){
        // Recursively do function in subtracted number
        return reverseNumberRec(n/10,result);;
    }
    return result;
}

int isPalindrome(int n){ 
   // if number started with 0 return false
    if(n%10 == 0){return 0;}
    // get the reversed number
    int result = reverseNumberRec(n,0);
    // compare the number with the reversed
    return n == result;
}

int factor(int n){
    // 0! = 1
    if(n==0) {
        return 1;
    }
    // multiply number by the n-1 recursively
    return n*factor(n-1);
}

int power(int n,int p){
    // n^0 = 1
    if(p==0){
        return 1;
    }
    // multiply n p times recursively
    return n*power(n,p-1);
}
int numberLen (int n){
    // if number is smaller than 10 num.len = 1
    if(n<10){
        return 1;
    }
    // get to the next digit by divide number by 10
    return 1+numberLen(n/10);
}

int isArmstrongRec(int n,int numberLen)
{
    if(n==0) {
        return 0;
    }
    // get the digit and get n^power
    int digit = n%10;
    int digitResult = power(digit,numberLen);
    // result of digit^n + the next digit
    return digitResult+isArmstrongRec(n/10,numberLen);
}

int isArmstrong(int n){
    // copy number
    int num=n;
    // get length of number
    int len=numberLen(n);
    // get result
    int result = isArmstrongRec(n,len);
    // compare to original number
    if(num==result) {
        return 1;
    }
    return 0;

}