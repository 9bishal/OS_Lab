#include<stdio.h>
int main(){
    int n;
    int at[n], bt[n], ct[n], tat[n], wt[n];
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        printf("Enter the arrival time and burts time of process p%d",i+1);
        scanf("%d %d",&at[i], &bt[i]);
    }

    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];


    for(int i=0; i<n; i++){
        ct[i]=at[i-1]+bt[0];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    int total_wt=0;
    int total_tat=0;
    for(int i=0; i<n; i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    float average_tat = (float)total_tat / n;
    float average_wt = (float)total_wt / n;

    printf("\nProcess\tArrival\tBurs\tCompletion\tTurnAround\tWaiting");
    for(int i=0; i<n; i++){
        printf("P%d\t%dt%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", average_tat);
    printf("\nAverage Waiting Time: %.2f\n", average_wt);
    return 0;
}
