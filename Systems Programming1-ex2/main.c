# include <stdio.h>
#include "my_mat.c"
#include "my_mat.h"

int main(){
char ch='x';
    
while (ch != 'D')
{
   scanf("%c",&ch);
   if (ch=='A') function1();
   if (ch=='B') function2(); 
   if (ch=='C') function3();
   if (ch=='M') printMat(); 
   if (ch=='S') printAns(); 
}

    return 0;
}

