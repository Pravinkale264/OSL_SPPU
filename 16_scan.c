#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[20], i, j, n, TotalHeadMovement = 0, initial, size, move;
    printf("Enter the total number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests \n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for right 1 and for left 0\n");
    scanf("%d", &move);
    // Sort the Requests
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    // movement towards right
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }

        TotalHeadMovement = TotalHeadMovement + abs(size - RQ[i - 1] - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // movement towards left value
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMovement = TotalHeadMovement + abs(RQ[i + 1] - 0);
        initial = 0;
        for (i = index; i < n; i++)
        {
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is %d", TotalHeadMovement);
    return 0;
}