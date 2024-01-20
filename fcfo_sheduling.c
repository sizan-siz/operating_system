// This code is implement to first come first serve without arivaltime using c programming 
# include<stdio.h>
int main(){
    int i,j,n,bt[30],wt[30],tat[30];
    float avg_wt=0,avg_tat=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    printf("Enter the burst time of the process");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Process\tBust_time\tWating_time\tTurn_around_time\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avg_wt=avg_wt+wt[i];
        avg_tat=avg_tat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        printf("\n");
    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("\nAvarage waiting time: %f",avg_wt);
    printf("\nAvarage Turn around time: %f",avg_tat);
    
}