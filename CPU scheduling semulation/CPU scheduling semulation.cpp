#include <iostream>
#include <queue>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

void FCFS(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2],wait=totalTime;
    if (mode.compare("trace")==0)
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                currentProcess=q.front();
                leftwait=wait-1;
                q.pop();
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        int ii,jj,kk;
        cout<<"FCFS ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";
        
    }
    else
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                currentProcess=q.front();
                leftwait=wait-1;
                q.pop();
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        cout<<"FCFS\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
    
}


void RR(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2],int wait){
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                currentProcess=q.front();
                leftwait=wait-1;
                q.pop();
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        int ii,jj,kk;
        cout<<"RR-"<<wait<<" ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    else
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                currentProcess=q.front();
                leftwait=wait-1;
                q.pop();
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        cout<<"RR-"<<wait<<"\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void SPN(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    int wait=totalTime;
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                int min=q.front(),constant;
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(startDuration[constant][1]<startDuration[min][1])
                    {
                        min=constant;
                    }
                    q.pop();
                    q.push(constant);
                }
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(min==constant)
                    {
                        q.pop();
                    }else{
                        q.pop();
                        q.push(constant);
                    }
                }
                currentProcess=min;
                leftwait=wait-1;
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        int ii,jj,kk;
        cout<<"SPN  ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    else
    {
        
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                int min=q.front(),constant;
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(startDuration[constant][1]<startDuration[min][1])
                    {
                        min=constant;
                    }
                    q.pop();
                    q.push(constant);
                }
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(min==constant)
                    {
                        q.pop();
                    }else{
                        q.pop();
                        q.push(constant);
                    }
                }
                currentProcess=min;
                leftwait=wait-1;
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            } else{
                timeLine[currentProcess][currentTime]=0;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        cout<<"SPN\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void SRT(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,min=0,max=0;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for (int i=0;i<numberProcesses;i++)
            {
                if((workingStartDuration[i][1]>workingStartDuration[max][1])&&(startDuration[i][0]<=currentTime)&&(workingStartDuration[i][1]>0))
                {
                    max=i;
                }
            }
            min=max;
            for (int i=0;i<numberProcesses;i++)
            {
                if((workingStartDuration[i][1]<workingStartDuration[min][1])&&(startDuration[i][0]<=currentTime)&&(workingStartDuration[i][1]>0))
                {
                    min=i;
                }
            }
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            currentProcess=min;
            bool found = false;
            if (workingStartDuration[currentProcess][1]>0)
            {
                found=true;
            }
            
            
            if (found==true){
                timeLine[currentProcess][currentTime]=1;
            }
            workingStartDuration[currentProcess][1]--;
        }
        int ii,jj,kk;
        cout<<"SRT  ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";
    }
    else
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,min=0,max=0;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for (int i=0;i<numberProcesses;i++)
            {
                if((workingStartDuration[i][1]>workingStartDuration[max][1])&&(startDuration[i][0]<=currentTime)&&(workingStartDuration[i][1]>0))
                {
                    max=i;
                }
            }
            min=max;
            for (int i=0;i<numberProcesses;i++)
            {
                if((workingStartDuration[i][1]<workingStartDuration[min][1])&&(startDuration[i][0]<=currentTime)&&(workingStartDuration[i][1]>0))
                {
                    min=i;
                }
            }
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
                currentProcess=min;
            bool found = false;
            if (workingStartDuration[currentProcess][1]>0)
            {
                found=true;
            }
            
            
            if (found==true){
                timeLine[currentProcess][currentTime]=1;
            }
            workingStartDuration[currentProcess][1]--;
        }
        cout<<"SRT\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void HRRN(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    int wait=totalTime;
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                int min=q.front(),constant;
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(((currentTime-startDuration[min][0])+startDuration[min][1])/startDuration[min][1]<((currentTime-startDuration[constant][0])+startDuration[constant][1])/startDuration[constant][1])
                    {
                        min=constant;
                    }
                    q.pop();
                    q.push(constant);
                }
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(min==constant)
                    {
                        q.pop();
                    }else{
                        q.pop();
                        q.push(constant);
                    }
                }
                currentProcess=min;
                leftwait=wait-1;
            }
            if(currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        int ii,jj,kk;
        cout<<"HRRN ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    else
    {
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    q.push(currentProcess);
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            if(currentProcess==-1&&!q.empty())
            {
                int min=q.front(),constant;
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(((currentTime-startDuration[min][0])+startDuration[min][1])/startDuration[min][1]<((currentTime-startDuration[constant][0])+startDuration[constant][1])/startDuration[constant][1])
                    {
                        min=constant;
                    }
                    q.pop();
                    q.push(constant);
                }
                for(int c=0;c<q.size();c++)
                {
                    constant=q.front();
                    if(min==constant)
                    {
                        q.pop();
                    }else{
                        q.pop();
                        q.push(constant);
                    }
                }
                currentProcess=min;
                leftwait=wait-1;
            }
            if(currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
            }
            workingStartDuration[currentProcess][1]--;
            
        }
        cout<<"HRRN\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void FB(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    int wait=1;
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        int queueSize=5;
        queue<int> q[queueSize];
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime],usedQueue=0;
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q[0].push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            bool exist=false;
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    if(usedQueue<(queueSize-1))
                    {
                        
                        
                        for(int w=0;w<queueSize;w++)
                        {
                            if(!q[w].empty())
                            {
                                exist=true;
                            }
                        }
                        
                        if(exist)
                        {
                            q[usedQueue+1].push(currentProcess);
                        }else{
                            q[usedQueue].push(currentProcess);
                        }
                    }else{
                        q[usedQueue].push(currentProcess);
                    }
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            bool empty=true;
            for(int w=0;w<queueSize;w++)
            {
                if(!q[w].empty())
                {
                    empty=false;
                }
            }
            if(currentProcess==-1&&empty==false)
            {
                for(int w=0;w<queueSize;w++)
                {
                    if(!q[w].empty())
                    {
                        currentProcess=q[w].front();
                        leftwait=wait-1;
                        q[w].pop();
                        usedQueue=w;
                        break;
                    }
                }
            }
            if (empty==false)
            {
                timeLine[currentProcess][currentTime]=1;
                workingStartDuration[currentProcess][1]--;
            }else{
                timeLine[currentProcess][currentTime]=0;
            }
            
        }
        int ii,jj,kk;
        cout<<"FB-1 ";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    else
    {
        int queueSize=5;
        queue<int> q[queueSize];
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime],usedQueue=0;
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q[0].push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            bool exist=false;
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    if(usedQueue<(queueSize-1))
                    {
                        
                        
                        for(int w=0;w<queueSize;w++)
                        {
                            if(!q[w].empty())
                            {
                                exist=true;
                            }
                        }
                        
                        if(exist)
                        {
                            q[usedQueue+1].push(currentProcess);
                        }else{
                            q[usedQueue].push(currentProcess);
                        }
                    }else{
                        q[usedQueue].push(currentProcess);
                    }
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }
            bool empty=true;
            for(int w=0;w<queueSize;w++)
            {
                if(!q[w].empty())
                {
                    empty=false;
                }
            }
            if(currentProcess==-1&&empty==false)
            {
                for(int w=0;w<queueSize;w++)
                {
                    if(!q[w].empty())
                    {
                        currentProcess=q[w].front();
                        leftwait=wait-1;
                        q[w].pop();
                        usedQueue=w;
                        break;
                    }
                }
            }
            if (empty==false)
            {
                timeLine[currentProcess][currentTime]=1;
                workingStartDuration[currentProcess][1]--;
            }else{
                timeLine[currentProcess][currentTime]=0;
            }
            
        }
        cout<<"FB-1\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void FBE(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2]){
    int wait=1;
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    if (mode.compare("trace")==0)
    {
        int queueSize=5;
        queue<int> q[queueSize];
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime],usedQueue=0;
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q[0].push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            bool exist=false;
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    if(usedQueue<(queueSize-1))
                    {
                        
                        
                        for(int w=0;w<queueSize;w++)
                        {
                            if(!q[w].empty())
                            {
                                exist=true;
                            }
                        }
                        
                        if(exist)
                        {
                            q[usedQueue+1].push(currentProcess);
                        }else{
                            q[usedQueue].push(currentProcess);
                        }
                    }else{
                        if(currentProcess!=-1)
                        {
                            q[usedQueue].push(currentProcess);
                        }
                    }
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }

            
            bool empty=true;
            for(int w=0;w<queueSize;w++)
            {
                if(!q[w].empty())
                {
                    empty=false;
                }
            }
            if(currentProcess==-1)
            {
                for(int w=0;w<queueSize;w++)
                {
                    if(!q[w].empty())
                    {
                        currentProcess=q[w].front();
                        leftwait=wait-1;
                        q[w].pop();
                        usedQueue=w;
                        leftwait=pow(2.0,static_cast<float>(w))-1;
                        break;
                    }
                }
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
                workingStartDuration[currentProcess][1]--;
            }else{
                timeLine[currentProcess][currentTime]=0;
            }
            
        }
        int ii,jj,kk;
        cout<<"FB-2i";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    else
    {
        int queueSize=5;
        queue<int> q[queueSize];
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime],usedQueue=0;
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            workingStartDuration[k][1]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    q[0].push(k);
                }
                if(startDuration[k][0]<=currentTime&&workingStartDuration[k][1]>0){
                    timeLine[k][currentTime]=2;
                }
            }
            bool exist=false;
            if(leftwait==0||workingStartDuration[currentProcess][1]==0)
            {
                if(workingStartDuration[currentProcess][1]<=0)
                {
                    currentProcess=-1;
                }else{
                    if(usedQueue<(queueSize-1))
                    {
                        
                        
                        for(int w=0;w<queueSize;w++)
                        {
                            if(!q[w].empty())
                            {
                                exist=true;
                            }
                        }
                        
                        if(exist)
                        {
                            q[usedQueue+1].push(currentProcess);
                        }else{
                            q[usedQueue].push(currentProcess);
                        }
                    }else{
                        if(currentProcess!=-1)
                        {
                            q[usedQueue].push(currentProcess);
                        }
                    }
                    currentProcess=-1;
                }
            }else{
                leftwait--;
            }

            
            bool empty=true;
            for(int w=0;w<queueSize;w++)
            {
                if(!q[w].empty())
                {
                    empty=false;
                }
            }
            if(currentProcess==-1)
            {
                for(int w=0;w<queueSize;w++)
                {
                    if(!q[w].empty())
                    {
                        currentProcess=q[w].front();
                        leftwait=wait-1;
                        q[w].pop();
                        usedQueue=w;
                        leftwait=pow(2.0,static_cast<float>(w))-1;
                        break;
                    }
                }
            }
            if (currentProcess!=-1)
            {
                timeLine[currentProcess][currentTime]=1;
                workingStartDuration[currentProcess][1]--;
            }else{
                timeLine[currentProcess][currentTime]=0;
            }
            
        }
        cout<<"FB-2i\n";
        cout<<"Process    ";
        for (int i=0;i<numberProcesses;i++)
        {
            cout<<"|  "<<processesName[i]<<"  ";
        }
        cout<<"|\n";
        cout<<"Arrival    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][0]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][0];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|\n";
        cout<<"Service    ";
        for (int i=0;i<numberProcesses;i++)
        {
            int yy,n,z=(log10(startDuration[i][1]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<startDuration[i][1];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"| Mean|\n";
        cout<<"Finish     ";
        int finish[numberProcesses];
        for (int i=0;i<numberProcesses;i++)
        {
            for(int j=1;j<totalTime;j++)
            {
                if (timeLine[i][j]==0&&timeLine[i][j-1]!=0)
                {
                    finish[i]=j;
                }else if(timeLine[i][j-1]==1&&(timeLine[i][j]!=0||timeLine[i][j]!=1||timeLine[i][j]!=2)){
                    finish[i]=totalTime;
                }
            }
            int yy,n,z=(log10(finish[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<finish[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        cout<<"|-----|\n";
        int turnAround[numberProcesses];
        cout<<"Turnaround ";
        for (int i=0;i<numberProcesses;i++)
        {
            turnAround[i]=finish[i]-startDuration[i][0];
            
            int yy,n,z=(log10(turnAround[i]) + 1);
            if(z<0)
            {
                n=2;
            }
            else
            {
                n=3-z;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            
            cout<<turnAround[i];
            
            if(z<0)
            {
                n=3;
            }
            else
            {
                n=5-z-yy+1;
            }
            
            for(;n<5;n++)
            {
                cout<<" ";
            }
            
        }
        float total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=turnAround[i]+total;
        }
        float mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n";
        }
        double normturn[numberProcesses];
        cout<<"NormTurn   ";
        for (int i=0;i<numberProcesses;i++)
        {
            normturn[i]=static_cast<float>(turnAround[i])/static_cast<float>(startDuration[i][1]);
            int yy,n,z=(log10(normturn[i]) + 1);
            if(z<=1)
            {
                n=1;
            }
            else
            {
                n=0;
            }
            cout<<"|";
            for(yy=0;yy<n;yy++)
            {
                cout<<" ";
            }
            cout<<normturn[i];
        }
        total=0;
        for(int i=0;i<sizeof(turnAround)/sizeof(int);i++)
        {
            total=static_cast<float>(normturn[i])+static_cast<float>(total);
        }
        mean=static_cast<float>(total)/static_cast<float>(numberProcesses);
        if (mean>=10){
            cout<<"|"<<static_cast<float>(mean)<<"|\n\n";
        }else{
            cout<<"| "<<static_cast<float>(mean)<<"|\n\n";
        }
    }
}

void aging(string mode,int totalTime,int numberProcesses,string processesName[],int startDuration[][2],int wait){
    cout<<fixed;
    cout<<setprecision(2);
    int workingStartDuration[numberProcesses][2];
    int enteredReady[numberProcesses];
    for(int yyy=0;yyy<numberProcesses;yyy++)
    {
        enteredReady[yyy]=-1;
    }
    if (mode.compare("trace")==0)
    {
        int priority[numberProcesses];
        for (int e=0;e<numberProcesses;e++)
        {
            priority[e]=-1;
        }
        queue<int> q;
        int k,currentTime,currentProcess=-1,leftwait=wait;
        int timeLine[numberProcesses][totalTime];
        for(int i=0;i<numberProcesses;i++)
        {
            for(int j=0;j<totalTime;j++)
            {
                timeLine[i][j]=0;
            }
        }
        for(k=0;k<numberProcesses;k++)
        {
            workingStartDuration[k][0]=startDuration[k][0];
            priority[k]=startDuration[k][1];
        }
        for(currentTime=0;currentTime<totalTime;currentTime++)
        {
            for(k=0;k<numberProcesses;k++)
            {
                if(startDuration[k][0]==currentTime)
                {
                    priority[k]=startDuration[k][1]+1;
                    enteredReady[k]=currentTime;
                    q.push(k);
                }
                if(startDuration[k][0]<=currentTime){
                    timeLine[k][currentTime]=2;
                }
            }
            if(leftwait==0)
            {
                q.push(currentProcess);
                enteredReady[currentProcess]=currentTime;
                priority[currentProcess]=startDuration[currentProcess][1];
                currentProcess=-1;
            }else{
                leftwait--;
            }
            int max=q.front();
            if(currentProcess==-1)
            {
                for(int w=0;w<q.size();w++)
                {
                    if(priority[q.front()]>priority[max])
                    {
                        max=q.front();
                    }
//                    cout<<enteredReady[q.front()]<<"    aaaaaaaaa    "<<q.front()<<endl;
//                    cout<<enteredReady[max]<<"    bbbbbbbbb    "<<max<<endl;
//                    cout<<"  ccccccccc                   "<<(priority[q.front()]==priority[max]&&enteredReady[q.front()]<enteredReady[max])<<endl;
                    if(priority[q.front()]==priority[max]&&enteredReady[q.front()]<enteredReady[max])
                    {
                        max=q.front();
                    }
                    if(!q.empty())
                    {
                        q.push(q.front());
                        q.pop();
                    }
                }
                currentProcess=max;
                for (int o=0;o<q.size();o++)
                {
                    if (q.front()!=currentProcess)
                    {
                        priority[q.front()]++;
                    }
                        q.push(q.front());
                    q.pop();
                }
                leftwait=wait-1;
                for(int w=0;w<q.size();w++)
                {
                    if(q.front()==currentProcess)
                    {
                        q.pop();
                    }
                    else
                    {
                        q.push(q.front());
                        q.pop();
                    }
                }
            }
            timeLine[currentProcess][currentTime]=1;
        }
        int ii,jj,kk;
        cout<<"Aging";
        for(kk=0;kk<totalTime+1;kk++)
        {
            int numb=kk%10;
            cout<<" "<<numb;
        }
        cout<<" \n";
        
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n";        for(jj=0;jj<numberProcesses;jj++){
            cout<<processesName[jj]<<"     |";
            for(ii=0;ii<totalTime;ii++){
                if (timeLine[jj][ii]==1){
                    cout<<"*|";
                }else if (timeLine[jj][ii]==2){
                    cout<<".|";
                }
                else
                {
                    cout<<" |";
                }
            }
            cout<<" \n";
        }
        cout<<"-------";
        for(int l=0;l<totalTime;l++)
        {
            cout<<"--";
        }
        cout<<"-\n\n";    }
    
}


void  multiple(string mode,string line,int totalTime,int numberProcesses,string processesName[],int startDuration[][2])
{
    //    cout<<mode<<"        ewdfvgbfhndgfsdawsdfghngdfdefsgdbnhmgdfdwfg";
    string schedulingStr;
    string waitStr;
    string totalTimeStr;
    if (mode.compare("stats")==0||mode.compare("trace")==0)
    {
        string delimiter = "-";
        size_t pos = 0;
        string token;
        for(int j=0;j<2;j++){
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            switch (j) {
                case 0:
                    schedulingStr=token;
                    break;
                case 1:
                    waitStr=token;
                    break;
                default:
                    break;
            }
            
            line.erase(0, pos + delimiter.length());
        }
        int scheduling=stoi(schedulingStr);
        int wait=stoi(waitStr);
        switch (scheduling) {
            case 1:
                FCFS(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 2:
                RR(mode,totalTime,numberProcesses,processesName,startDuration,wait);
                break;
            case 3:
                SPN(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 4:
                SRT(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 5:
                HRRN(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 6:
                FB(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 7:
                FBE(mode,totalTime,numberProcesses,processesName,startDuration);
                break;
            case 8:
                aging(mode,totalTime,numberProcesses,processesName,startDuration,wait);
                break;
            default:
                cout << "Scheduling type not defined";
                break;
        }
    }else{
        cout << "undefined mode";
    }
}

int main(int argc, const char * argv[]) {
    //    string path="/Users/omarwalid/Documents/College/term 7/OS/Projects/Project 3/test/10b-input.txt";
    //    fstream inf;
    //    inf.open(path,ios::in);
    string trash;
    string mode,process,totalTimeStr,numberProcessesStr;
    getline(cin, mode,'\n');
    getline(cin, process,'\n');
    getline(cin, totalTimeStr,'\n');
    int totalTime=stoi(totalTimeStr);
    getline(cin, numberProcessesStr,'\n');
    int numberProcesses=stoi(numberProcessesStr);
    string total[numberProcesses];
    string processesName[numberProcesses];
    int startDuration[numberProcesses][2];
    string delimiter = ",";
    size_t pos = 0;
    string token,oldToken="old";
    queue<string> qq;
    int counter=0;
    while(process!=""){
        pos = process.find(delimiter);
        oldToken=token;
        token = process.substr(0, pos);
        if(oldToken==token)
        {
            break;
        }
        qq.push(token);
        counter++;
        process.erase(0, pos + delimiter.length());
    }
    int i=0;
    string process2;
    for(int kk=0;kk<numberProcesses;kk++)
    {
        getline(cin, process2,'\n');
        string delimiter = ",";
        size_t pos = 0;
        string token;
        for(int j=0;j<3;j++){
            pos = process2.find(delimiter);
            token = process2.substr(0, pos);
            switch (j) {
                case 0:
                    processesName[i]=token;
                    break;
                case 1:
                    startDuration[i][0]=stoi(token);
                    break;
                case 2:
                    startDuration[i][1]=stoi(token);
                    break;
                default:
                    break;
            }
            
            process2.erase(0, pos + delimiter.length());
        }
        i++;
    }
    for(int i=0;i<counter;i++)
    {
        multiple(mode, qq.front(),totalTime,numberProcesses,processesName,startDuration);
        qq.pop();
    }
    return 0;
}
