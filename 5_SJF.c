#include <stdio.h>
int main()
{
    int AT[10], BT[10], temp[10];
    int i, smallest, count = 0, time, n, exitime;
    double WT = 0, TAT = 0;
    float average_waiting_time, average_TAT;
    
    // taking input
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes", n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &AT[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &BT[i]);
        temp[i] = BT[i];
    }
    BT[9] = 9999; // infinity value

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (AT[i] <= time && BT[i] < BT[smallest] && BT[i] > 0)
            {
                smallest = i;
            }
        }
        BT[smallest]--;
        if (BT[smallest] == 0)
        {   
            count++;
            exitime = time + 1;
            printf("P[%d]\t|\t%d\t|\t%d\n", smallest, exitime - AT[smallest], exitime - AT[smallest] - temp[smallest]);
            WT = WT + exitime - AT[smallest] - temp[smallest];
            TAT = TAT + exitime - AT[smallest];
        }
    }

    average_waiting_time = WT / n;
    average_TAT = TAT / n;
    printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:\t%lf\n", average_TAT);
    return 0;
}






/*
Input
3
0 5
1 3
2 2

Output

Process	|Turnaround Time|Waiting Time

P[1]	|	3	|	0
P[2]	|	4	|	2
P[0]	|	10	|	5


Average Waiting Time:	2.333333
Average Turnaround Time:	5.666667
*/