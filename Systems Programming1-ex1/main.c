#include <stdio.h>
#include <string.h>
#include"basicClassification.c"
#include"advancedClassificationLoop.c"
#include <math.h>
#include "NumClass.h"

int main()
{
    int num1, num2;
        scanf("%i", &num1);
        scanf("%i", &num2);

    if(num1>num2){
        int t=num1;
        num1=num2;
        num2=t;
    }

    char primes[num2-num1+5];
    char armstrongs[num2-num1+5];
    char strongs[num2-num1+5];
    char pali[num2-num1+5];

    for (int i = 0; i < num2-num1+5; i++)
    {
        primes[i]=0;
        armstrongs[i]=0;
        strongs[i]=0;
        pali[i]=0;
    }
    
    char space[2]=" "; 

    for (int i = num1; i <= num2; i++){
        char str[20];
        sprintf(str, "%d", i);

    if (isPrime(i)==1){
        strcat(primes, space);
        strcat(primes, str);
        
    }
    if (isArmstrong(i)==1){
        strcat(armstrongs, space);
        strcat(armstrongs, str);
    }
    if (isStrong(i)==1){
        strcat(strongs, space);
        strcat(strongs, str);
    }
    if (isPalindrome(i)==1){
        strcat(pali, space);
        strcat(pali, str);
    }
    }
    
    printf("The Armstrong numbers are:%s\n",armstrongs);
    printf("The Palindromes are:%s\n",pali);
    printf("The Prime numbers are:%s\n",primes);
    printf("The Strong numbers are:%s\n",strongs);
    
    return 0;
}
