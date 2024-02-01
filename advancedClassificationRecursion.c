#include "NumClass.h"

//Implement
int reverseNumberRec(int n,int result){
    int digit = n%10;
    result = result*10;
    result+=digit;
    n-=digit;
    if(n!=0){
        return reverseNumberRec(n/10,result);;
    }
    return result;
}

int isPalindrome(int n){ 
   if(n%10 == 0){return 0;}
    int result = reverseNumberRec(n,0);
    return n == result;
}

//    **************************************** Not My Code!!!!!! ****************************************
int int_pow(int base, int exp) {
    int result = 1;
    while (exp != 0) {
        result *= base;
        --exp;
    }
    return result;
}

/**
 * helper function for calculates the number of digits in a given integer n.
 * If n is negative, it returns -1.
 */
int numLen(int n) {
    if (n < 0) return -1;

    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}
int isArmstrongHelper(int n, int count) {                                                               //
    if (n == 0) return 0;                                                                           //
    return int_pow(n % 10, count) + isArmstrongHelper(n / 10, count);                                //
}

/**                         
 * check if n is an Armstrong number in recursive way
 */
int isArmstrong(int n) {
    if (n <= 0) return 0;

    int len = numLen(n);
    return isArmstrongHelper(n, len) == n ? 1 : 0;
}
// **************************************** **********************************************************