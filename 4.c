#include<stdio.h>
int main()
{
    int i=0;
    int h[9]={0}, x[3]={0}, y[3]={0};
    FILE *input = fopen("../input/4.txt","r");
    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    asm volatile(
        "mul %[H1], %[H1] ,%[X1]\n\t" 
        "mul %[H2], %[H2] ,%[X2]\n\t" 
        "mul %[H3], %[H3] ,%[X3]\n\t" 
        "mul %[H4], %[H4] ,%[X1]\n\t" 
        "mul %[H5], %[H5] ,%[X2]\n\t" 
        "mul %[H6], %[H6] ,%[X3]\n\t" 
        "mul %[H7], %[H7] ,%[X1]\n\t"
        "mul %[H8], %[H8] ,%[X2]\n\t"
        "mul %[H9], %[H9] ,%[X3]\n\t" 
        "add %[Y1], %[Y1] ,%[H1]\n\t"
        "add %[Y1], %[Y1] ,%[H2]\n\t"
        "add %[Y1], %[Y1] ,%[H3]\n\t"
        "add %[Y2], %[Y2] ,%[H4]\n\t"
        "add %[Y2], %[Y2] ,%[H5]\n\t"
        "add %[Y2], %[Y2] ,%[H6]\n\t"
        "add %[Y3], %[Y3] ,%[H7]\n\t"
        "add %[Y3], %[Y3] ,%[H8]\n\t"
        "add %[Y3], %[Y3] ,%[H9]\n\t"
        : [Y1] "+r"(y[0])
        , [Y2] "+r"(y[1])
        , [Y3] "+r"(y[2])
        : [H1] "r" (h[0])
        , [H2] "r" (h[1])
        , [H3] "r" (h[2])
        , [H4] "r" (h[3])
        , [H5] "r" (h[4])
        , [H6] "r" (h[5])
        , [H7] "r" (h[6])
        , [H8] "r" (h[7])
        , [H9] "r" (h[8])
        , [X1] "r" (x[0])
        , [X2] "r" (x[1])
        , [X3] "r" (x[2]));
    p_y = &y[0];
    for(i = 0; i<3; i++)
        printf("%d \n", *p_y++);
    return(0) ;

}
