#include<stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int var_int;
    float var_float;
    double var_double;
   
    var_int =INT_MAX;
    var_float =FLT_MAX;
    var_double = DBL_MAX;  

    printf("Value of var_int is: %d\n", var_int);
    printf("Value of var_float is : %d\n", var_float);
    printf("Value of var_double is : %d\n", var_double);
    printf("Size of int: %ld bytes\n", sizeof(var_int));
    printf("Size of float: %ld bytes\n", sizeof(var_float));
    printf("Size of double: %ld bytes\n", sizeof(var_double));
    
    
    return 0;
}

