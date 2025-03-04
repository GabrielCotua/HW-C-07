// HW 07

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
int nPositive;

int printfArr(char message[charSize], enum OPTIONS opt)
{
    j = 0; // Track printed items
    printf("%s\n", message); // Ensure the title appears correctly

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
                nPositive++;
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


int main(void) 
{
    srand(time(NULL));
    for ( i = 0; i < ARY_SIZE; ++i) 
    {
        arr[i] = ( (int) rand() % HIGH_LIMIT - LOW_LIMIT) + LOW_LIMIT;
        if (arr[i] % NEGMULT1 == 0 || arr[i] % NEGMULT2 == 0 ) {
            arr[i] *= -1;
        }
    }
    printfArr("\nPrinting the whole array:", ALL);
    printfArr("\nPrinting odd values:", OPT_ODD_VALUES );
    printfArr("\nPrinting odd indexes:", OPT_ODD_INDEX );

    printf("\n%d   ", nPositive);

    printfArr("\nPrinting positive values:", OPT_POSITIVE_VALUES);
    printfArr("\nPrinting negative values", OPT_NEGATIVE_VALUES);

}
/*
Printing the whole array:
 -867   844  -996   -15   386  -435   286  -875  -279   160 
  821   773   152   992  -915    80   977  -360   848  -861 
 -417   484  -351   547   937   713   -99   535   668    86 
  740  -203    92  -519  -204   907   323    92   577   629 
  890   604  -906   -75  -339  -468    43  -448   979   536 
 -639  -750  -532   704   248  -195  -552   715  -822   988 
 -594   967   970  -696   625   985  -255   611   409  -154 
 -699   955   800   337   200  -543   460  -441  -973   722 
  127  -102   179  -630  -957  -948   820   974  -875  -867 
 -665   577   844   881   302  -497  -994  -672  -267  -168 

Printing odd values:
  821   773   977   547   937   713   535   907   323   577 
  629    43   979   715   967   625   985   611   409   955 
  337   127   179   577   881 

Printing odd index:
  844   -15  -435  -875   160   773   992    80  -360  -861 
  484   547   713   535    86  -203  -519   907    92   629 
  604   -75  -468  -448   536  -750   704  -195   715   988 
  967  -696   985   611  -154   955   337  -543  -441   722 
 -102  -630  -948   974  -867   577   881  -497  -672  -168 

Printing positive values:
  844   386   286   160   821   773   152   992    80   977 
  848   484   547   937   713   535   668    86   740    92 
  907   323    92   577   629   890   604    43   979   536 
  704   248   715   988   967   970   625   985   611   409 
  955   800   337   200   460   722   127   179   820   974 
  577   844   881   302 

Printing negative values
 -867  -996   -15  -435  -875  -279  -915  -360  -861  -417 
 -351   -99  -203  -519  -204  -906   -75  -339  -468  -448 
 -639  -750  -532  -195  -552  -822  -594  -696  -255  -154 
 -699  -543  -441  -973  -102  -630  -957  -948  -875  -867 
 -665  -497  -994  -672  -267  -168 

*/