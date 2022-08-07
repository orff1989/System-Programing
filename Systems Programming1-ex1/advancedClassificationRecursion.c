#include<stdio.h>
#include<math.h>
#include "NumClass.h"

static int sum = 0;
int isPalindrome(int num){
    if(num != 0){
        sum = (sum * 10) + (num % 10); 
        isPalindrome(num / 10); 
    }
    
    else if(sum == num){
        return 1;
    }
    return 0;
}

 int numLength(int num){
    if(num < 10){
        return 1;
    }
        return 1 + numLength(num/10); 
}

int checkArmstrong(int num, int length){
    int sum;
    int temp = num;
    
    if(num != 0){
       temp = temp % 10;
       sum += (int) pow(temp, length);
       checkArmstrong(num / 10, length);
   }   

   if(sum == num){
       return 1;
   } 
   return 0;
}

int isArmsrong(int num){
    int length = numLength(num);
    return checkArmstrong(num,length);
}
