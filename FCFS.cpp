#include<iostream>
using namespace std;
int main(){
    int process,at,bt,wt,ct=0,tt;
    float sum_wt=0,sum_tt=0;
    cout<<"How many process ? ";
    cin>>process;
    int ata[process],bta[process],wta[process],cta[process];
    
    // Input of arrival time and burst time
    for(int i=0;i<process;i++){
        cout<<"Enter arrival time of process "<<i<<": ";
        cin>>at;
        ata[i]=at;
        cout<<"Enter burst time of process "<<i<<": ";
        cin>>bt;
        bta[i]=bt;
    }
    // calculating completion time of each process
    for(int i=0;i<process;i++){
        ct = ct + bta[i];
        cta[i] = ct ;
    }

    // calculating wt time of each process
    for(int i=0;i<process;i++){
        wt = cta[i] - ( ata[i] + bta[i] );
        wta[i] = wt;
    }

    // Summation of waiting time
    for(int i=0;i<process;i++){
        sum_wt = sum_wt + wta[i]; 
    }

    // Summation of turn around time
    for(int i=0;i<process;i++){
        tt = wta[i]+bta[i];
        sum_tt = sum_tt + tt; 
    }

    cout<<"Average waiting time: "<<sum_wt/process<<endl;
    cout<<"Average turn around time: "<<sum_tt/process<<endl;
}