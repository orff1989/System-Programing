#include<stdio.h>
#include<math.h>
#include "NumClass.h"

int isPalindrome(int num){
    int rem, copyNum=num, sum=0;
    while (copyNum > 0){
        rem = copyNum%10;
        sum = (sum*10) + rem;
        copyNum = copyNum/10;
        }
        
        if (sum == num){
            return 1;
        } 
    return 0;
}

int numLength(int num){
    int counter = 0;
    int n=num;
    while(n > 0){
        n = n /10;
        counter++;
    }
    return counter;
}

int isArmstrong(int num){
    int length = numLength(num);
    int sum=0;
    int temp = num;
    while (temp > 0){
       int digit = temp % 10;
       sum =sum + pow(digit, length);
       temp = temp/10;
   }

   if(sum == num) {
       return 1;
   }
   return 0;
}

