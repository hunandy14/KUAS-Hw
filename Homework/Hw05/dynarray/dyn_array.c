// ====================================
// FileName: Ptr1Dim_C.cpp
// Author  : Edison.Shih.
// Complier: VC 2008

#include <stdio.h>
#include <stdlib.h>

// ==================================== 
// main function
int main(int argc, char**argv)
{
        double *ptr = NULL;
        int Dim = 0, i=0;

        printf("please input Dim:");
        scanf("%d", &Dim);
        
        // malloc the memory address
        ptr = (double*)malloc(sizeof(double)*Dim);
        // set the value - method 1
        for(i=0; i<Dim; i++) *(ptr+i) = (double)(i*i);
        // show the value - method 2
        for(i=0; i<Dim; i++) printf("ptr[%d] = %lf\n", i, ptr[i]);
       

        printf("please input Dim again:");
        scanf("%d", &Dim);
        // before you malloc the new memory addree.
        // free the old memory address first.
        free(ptr);
        ptr = (double*)malloc(sizeof(double)*Dim);
        // set the value - method 1
        for(i=0; i<Dim; i++) *(ptr+i) = (double)(i*i);
        // show the value - method 2
        for(i=0; i<Dim; i++) printf("ptr[%d] = %lf\n", i, ptr[i]);

        free(ptr); // last, free the memory.

        return 0;
}