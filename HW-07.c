// HW 07 Gabriel Cotua

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARY_SIZE 100
#define LOW_LIMIT 1
#define HIGH_LIMIT 999 // 999 is the maximum balue for this constant
#define NPERLINE 10 //The maximum number of numbers to be printed on a line of output
#define charSize 50
//The nultiples that specify which numers will be stored as a negative number: 
#define NEGMULT1 3
#define NEGMULT2 7

enum OPTIONS {OPT_ODD_VALUES, OPT_ODD_INDEX, OPT_POSITIVE_VALUES, OPT_NEGATIVE_VALUES, ALL};
int arr[ARY_SIZE];
int i, j; // i for index; j for printed items
int nEven = 0;
int sumAll = 0;
int min, max; // min max values
int minLoc, maxLoc; // location in the array

int printfArr(char message[charSize], enum OPTIONS opt)
{
    j = 0; // Track printed items
    printf("\n%s\n", message); // Ensure the title appears correctly

    for (i = 0; i < ARY_SIZE; ++i) 
    {
        int shouldPrint = 0; // Flag to track whether the number should be printed

        switch (opt)
        {
            case OPT_ODD_VALUES:
                shouldPrint = (arr[i] % 2 == 1);
                break;

            case OPT_ODD_INDEX:
                shouldPrint = (i % 2 == 1);
                break;

            case OPT_POSITIVE_VALUES:
                shouldPrint = (arr[i] >= 0);
                break;

            case OPT_NEGATIVE_VALUES:
                shouldPrint = (arr[i] < 0);
                break;

            default:
                shouldPrint = 1;
                break;
        }

        if (shouldPrint)
        {
            printf("%5d ", arr[i]);
            j++;

            // Ensure exactly `NPERLINE` numbers per line
            if (j % NPERLINE == 0)
                printf("\n");
        }
    }

    // Final line break if the last row is incomplete
    if (j % NPERLINE != 0)
        printf("\n");

    return 1;
}

int getStats() {
    max = arr[0];
    maxLoc = 0;
    min = arr[0];
    minLoc = 0;
    sumAll = 0;

    for ( i = 0; i < ARY_SIZE; ++i) {
        sumAll += arr[i];
        if (arr[i] % 2 == 0) {
            nEven++;
        }
        if (arr[i] > max ){ // max
            max = arr[i];
            maxLoc = i + 1;
        }
        if(arr[i] < min) { // min
            min = arr[i];
            minLoc = i + 1;
        }
    }
    printf("\nNumber of even numbers: %d", nEven);
    printf("\nSum of Numbers: %d", sumAll);
    printf("\nBiggest value in array: %d at: %d", max, maxLoc);
    printf("\nSmallest Value in array: %d at: %d\n", min, minLoc);
    return 1;

}


int main(void) 
{
    printf("\n\n|#####################|\n|HW #07, Gabriel Cotua|\n|#####################|\n\n");

    srand(time(NULL));
    for ( i = 0; i < ARY_SIZE; ++i) 
    {
        arr[i] = ( (int) rand() % HIGH_LIMIT - LOW_LIMIT) + LOW_LIMIT;
        if (arr[i] % NEGMULT1 == 0 || arr[i] % NEGMULT2 == 0 ) {
            arr[i] *= -1;
        }
    }
    printfArr("Printing the whole array:", ALL);
    printfArr("Printing odd values:", OPT_ODD_VALUES );
    printfArr("Printing odd indexes:", OPT_ODD_INDEX );

    getStats();

    printfArr("Printing positive values:", OPT_POSITIVE_VALUES);
    printfArr("Printing negative values", OPT_NEGATIVE_VALUES);

}
/*
[Expected output]

|#####################|
|HW #07, Gabriel Cotua|
|#####################|


Printing the whole array:
 -135  -201   374   202  -896   218    -3  -308   302   325 
  425   -66  -171   -14  -112   625  -591   599   580   -63 
  832   187   365   586   818   352  -518   548  -201  -612 
 -651   781   253   655  -789   578   409   818   802   466 
  -69  -366  -291   263   908   275  -123   377   697  -864 
  845   841   475   584   220  -645  -882  -497  -477    44 
 -309  -174  -132   416  -434   320   989  -957    40   283 
  949   361   676  -931  -849  -791   428  -658  -756    95 
 -606   419   356   146  -570   139   641   289  -144   401 
 -129   970   200   953  -642  -294   487  -960  -875   439 

Printing odd values:
  325   425   625   599   187   365   781   253   655   409 
  263   275   377   697   845   841   475   989   283   949 
  361    95   419   139   641   289   401   953   487   439 

Printing odd indexes:
 -201   202   218  -308   325   -66   -14   625   599   -63 
  187   586   352   548  -612   781   655   578   818   466 
 -366   263   275   377  -864   841   584  -645  -497    44 
 -174   416   320  -957   283   361  -931  -791  -658    95 
  419   146   139   289   401   970   953  -294  -960   439 

Number of even numbers: 48
Sum of Numbers: 7870
Biggest value in array: 989 at: 67
Smallest Value in array: -960 at: 98

Printing positive values:
  374   202   218   302   325   425   625   599   580   832 
  187   365   586   818   352   548   781   253   655   578 
  409   818   802   466   263   908   275   377   697   845 
  841   475   584   220    44   416   320   989    40   283 
  949   361   676   428    95   419   356   146   139   641 
  289   401   970   200   953   487   439 

Printing negative values
 -135  -201  -896    -3  -308   -66  -171   -14  -112  -591 
  -63  -518  -201  -612  -651  -789   -69  -366  -291  -123 
 -864  -645  -882  -497  -477  -309  -174  -132  -434  -957 
 -931  -849  -791  -658  -756  -606  -570  -144  -129  -642 
 -294  -960  -875 

*/