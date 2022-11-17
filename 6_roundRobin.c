#include <stdio.h>
int main()
{
    int count, j, n, exittime, remain, flag = 0, time_quantum;
    int AT[6], BT[6], RT[6];
    float WT = 0, TAT = 0;
    
    //taking input--------------------------
    printf("Enter Total Processes:  ");
    scanf("%d", &n);
    
    remain = n;
    printf("\nEnter arrival time and burst time for processes");
    for(count = 0; count < n; count++) {
        printf("\nProcess %d : ", count+1);
        printf("\n\tArrival time: ");
        scanf("%d", &AT[count]);
        
        printf("\n\tBurst Time: ");
        scanf("%d", &BT[count]);
        
        RT[count] = BT[count];
    }
    
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    
    //----------------------------------------
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    
    for (exittime = 0, count = 0; remain != 0;)
    {
        if (RT[count] <= time_quantum && RT[count] > 0)           //Busrt time <= TQ
        {
            exittime += RT[count];
            RT[count] = 0;
            flag = 1;
        }
        else if (RT[count] > 0)         //BT > TQ       
        {
            RT[count] -= time_quantum;
            exittime += time_quantum;
        }
        
        if (RT[count] == 0 && flag == 1)     //process[count] is finished   coz flag is 1
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, exittime - AT[count], exittime - AT[count] - BT[count]);
            
            WT += exittime - AT[count] - BT[count];   //calculating total WT and Total TAT    
            TAT += exittime - AT[count];
            // 1wait_time+= TAT-BT[count];
            flag = 0;
        }
        if (count == n - 1)            //last process executed but set count = 0 to check again and execute rem processes
            count = 0;
        else if (AT[count + 1] <= exittime)  // next process has arrived execute next process
            count++;
        else
            count = 0;      //next process has not arrived yet so start from beginning
    }
    printf("\nAverage Waiting Time= %f\n", WT * 1.0 / n);
    printf("Avg Turnaround Time = %f", TAT * 1.0 / n);
    return 0;
}
