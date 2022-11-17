#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[20], i, n, TotalHeadMovement = 0, initial, count = 0;
    printf("Enter the total number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests \n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    /* execute until all requests consider 999 as infinity*/
    while (count != n)
    {
        int min = 999, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMovement = TotalHeadMovement + min;
        initial = RQ[index];
        RQ[index] = 999;
        count++;
    }
    printf("Total head movement is %d", TotalHeadMovement);
    return 0;
}