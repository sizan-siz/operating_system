#include<stdio.h>
int main(){
     int i,j,n,p[30],bt[30],wt[30],tat[30],pr[30],pos,t;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    
     printf("Enter Bust time\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }

     printf("Enter Priority\n");
    for(i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+i;j<n;j++){
            if(pr[j]<pr[pos])
            {
                pos=j;
            }
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
    }
    wt[0]=0;
    printf("Process\t Bust time\t Priority\tWT\t\tTAT\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avg_tat=avg_tat+tat[i];
        avg_wt=avg_tat+wt[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],pr[i],wt[i],tat[i]);
        printf("\n");
    }
    avg_wt=avg_tat/n;
    avg_tat=avg_tat/n;
    printf("Avarage Waiting time is %f ",avg_wt);
    printf("\nAvarage Turn around time is %f",avg_tat);
}