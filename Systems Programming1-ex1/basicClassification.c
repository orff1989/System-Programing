#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int num){
    if(num == 1 || num == 2){
        return 1;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
    
}

int factorial(int num){
    if(num == 0 || num == 1){
        return 1;
    }
    else{
        return num * factorial(num - 1);
    }
}

int isStrong(int num){
    int n = num;
    int digit;
    int sum = 0;
    
    if(num == 0){
        return 1;
    } 
    
    while (n!=0){
        digit = n%10;
        sum += factorial(digit);
        n = n/10;
    }
    
    if(sum == num){
        return 1;
    } 
    return 0;
}

