#include<iostream>
using namespace std;

int main(){
    int process,at,bt,total=0,small,k;
    float tavg=0,wavg=0;
    cout<<"Enter number of processes: ";
    cin>>process;
    int ata[process],bta[process],wt[process],pa[process],finish[process];
    for(int i=0; i<process; i++){
        cout<<"Enter arrival time of process "<<i<<": ";
        cin>>at;
        ata[i]= at;

        cout<<"Enter burst time of process "<<i<<": ";
        cin>>bt;
        bta[i]= bt;

        wt[i]=0;
        total = total + bta[i];

    }
    
    for(int i=0; i<process; i++){
        for(int j=i+1; j<process; j++){
            if(ata[i]> ata[j]){
                int temp = ata[i];
                ata[i]= ata[j];
                ata[j]= temp;

                temp   = bta[i];
                bta[i] = bta[j];
                bta[j] = temp;

            }

        }
    }

    // decreasing burst time
    for(int i=0; i<total; i++){
         small = 3200;
         for(int j=0; j<process; j++){
             if((bta[j] != 0) && (ata[j] <= i) && (bta[j]<small) ){
                 small = bta[j];
                 k = j ;
             }
         }
         bta[k]--;
         pa[i]= k;
    }

    // finding finishig time & waiting time

    for(int i=0; i<total; i++){
        for(int j=0; j<process; j++){
            if(pa[i] == j){
                finish[j] = i;
                wt[j]++;
            }
        }

    }

    for(int i=0; i<process; i++) {
        cout<<endl<<"Waiting time => "<<(((finish[i] +1) - wt[i]) - ata[i])<<"   Turnaround time =>"<<((finish[i]- ata[i]) + 1);
        wavg = wavg + (((finish[i] +1) - wt[i]) - ata[i]);
        tavg = tavg + ((finish[i]- ata[i]) + 1);    
    }
    cout<<"Average waiting time: "<<(wavg/process)<<endl;
    cout<<"Average turn around time: "<<(tavg/process)<<endl;
    return 0;
}