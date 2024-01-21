#include<stdio.h>
int main(){
    int i,j,n,p[30],bt[30],wt[30],tat[30],t;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    printf("Enter process\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
     printf("Enter Bust time\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    // Applying buble sort to sort according there bust time
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
              if(bt[j]>bt[j+i]){
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
              }
        }
    }

    printf("Process\tBust time\t Waiting time\t Turn around time\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
        printf("%d\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
        printf("\n");

    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("Avarage waiting time %f",avg_wt);
    printf("\nAvarage Turn around time %f",avg_tat);
}