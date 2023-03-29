//consumer
//  main.cpp
//  Project 4
//  Created by Omar Walid on 07/12/2022.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <random>
#include <cmath>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <ctime>
#include <queue>
#include <sys/sem.h>
#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
using namespace std;

struct material
{
    string name="";
    float price=0;
};
//void gotoxy( int column, int line )
//  {
//  COORD coord;
//  coord.X = column;
//  coord.Y = line;
//  SetConsoleCursorPosition(
//    GetStdHandle( STD_OUTPUT_HANDLE ),
//    coord
//    );
//  }

void display(float cprice[11][2],float avg[11][2])
{
        printf("\e[1;1H\e[2J");
    
    printf("+---------------------------------------+\n");
    printf("| Currency      |   Price   |  AvgPrice |\n");
    printf("+---------------------------------------+\n");
    
    printf("| GOLD          |");
    if(cprice[0][0]==cprice[0][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[0][0]);
    }else if(cprice[0][0]>cprice[0][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[0][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[0][0]);
    }
    if(avg[0][0]==avg[0][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[0][0]);
    }else if(avg[0][0]>avg[0][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[0][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[0][0]);
    }
    printf("\n");
    
    printf("| SILVER        |");
    if(cprice[1][0]==cprice[1][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[1][0]);
    }else if(cprice[1][0]>cprice[1][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[1][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[1][0]);
    }
    if(avg[1][0]==avg[1][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[1][0]);
    }else if(avg[1][0]>avg[1][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[1][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[1][0]);
    }
    printf("\n");
    
    printf("| CRUDEOIL      |");
    if(cprice[2][0]==cprice[2][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[2][0]);
    }else if(cprice[2][0]>cprice[2][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[2][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[2][0]);
    }
    if(avg[2][0]==avg[2][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[2][0]);
    }else if(avg[2][0]>avg[2][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[2][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[2][0]);
    }
    printf("\n");
    
    printf("| NATURALGAS    |");
    if(cprice[3][0]==cprice[3][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[3][0]);
    }else if(cprice[3][0]>cprice[3][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[3][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[3][0]);
    }
    if(avg[3][0]==avg[3][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[3][0]);
    }else if(avg[3][0]>avg[3][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[3][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[3][0]);
    }
    printf("\n");
    
    printf("| ALUMINIUM     |");
    if(cprice[4][0]==cprice[4][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[4][0]);
    }else if(cprice[4][0]>cprice[4][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[4][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[4][0]);
    }
    if(avg[4][0]==avg[4][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[4][0]);
    }else if(avg[4][0]>avg[4][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[4][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[4][0]);
    }
    printf("\n");
    
    
    
    
    printf("| COPPER        |");
    if(cprice[5][0]==cprice[5][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[5][0]);
    }else if(cprice[5][0]>cprice[5][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[5][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[5][0]);
    }
    if(avg[5][0]==avg[5][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[5][0]);
    }else if(avg[5][0]>avg[5][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[5][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[5][0]);
    }
    printf("\n");
    
    
    printf("| NICKEL        |");
    if(cprice[6][0]==cprice[6][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[6][0]);
    }else if(cprice[6][0]>cprice[6][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[6][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[6][0]);
    }
    if(avg[6][0]==avg[6][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[6][0]);
    }else if(avg[6][0]>avg[6][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[6][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[6][0]);
    }
    printf("\n");
    
    printf("| LEAD          |");
    if(cprice[7][0]==cprice[7][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[7][0]);
    }else if(cprice[7][0]>cprice[7][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[7][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[7][0]);
    }
    if(avg[7][0]==avg[7][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[7][0]);
    }else if(avg[7][0]>avg[7][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[7][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[7][0]);
    }
    printf("\n");
    
    printf("| ZINC          |");
    if(cprice[8][0]==cprice[8][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[8][0]);
    }else if(cprice[8][0]>cprice[8][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[8][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[8][0]);
    }
    if(avg[8][0]==avg[8][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[8][0]);
    }else if(avg[8][0]>avg[8][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[8][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[8][0]);
    }
    printf("\n");
    
    printf("| MENTHAOIL     |");
    if(cprice[9][0]==cprice[9][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[9][0]);
    }else if(cprice[9][0]>cprice[9][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[9][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[9][0]);
    }
    if(avg[9][0]==avg[9][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[9][0]);
    }else if(avg[9][0]>avg[9][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[9][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[9][0]);
    }
    printf("\n");
    
    printf("| COTTON        |");
    if(cprice[10][0]==cprice[10][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",cprice[10][0]);
    }else if(cprice[10][0]>cprice[10][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",cprice[10][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",cprice[10][0]);
    }
    if(avg[10][0]==avg[10][1])
    {
        printf("\033[;34m%7.2lf\033[0m    |",avg[10][0]);
    }else if(avg[10][0]>avg[10][1])
    {
        printf("\033[;32m%7.2lf↑\033[0m   |",avg[10][0]);
    }
    else
    {
        printf("\033[;31m%7.2lf↓\033[0m   |",avg[10][0]);
    }
    printf("\n");

    printf("+---------------------------------------+\n");
}
int main(int argc, const char * argv[]) {
    int shmid;
    material *array;
    int count = atoi(argv[1]);
    int SizeMem;
    key_t key = 65;
    SizeMem = sizeof(*array)*count;
    shmid = shmget(key, count*sizeof(material), IPC_CREAT);
    array = (material *)shmat(shmid, 0, 0);
    shmdt((void *) array);
    shmctl(shmid,IPC_RMID,NULL);
    
    
    float avg[11][2];
    float cprice[11][2];
    for(int hh=0;hh<11;hh++)
    {
        for(int vv=0;vv<2;vv++)
        {
            avg[hh][vv]=0;
            cprice[hh][vv]=0;
        }
    }
    display(cprice, avg);
    int n=0,s=1,e=2;
    int semid;
    union semun arg;
    int i = 0;
    key_t semKey =66;
    struct sembuf wait = {0, -1, 0};
    struct sembuf signal = {0, 1, 0};
    if ((semid = semget(semKey, 3, 0666 | IPC_CREAT)) == -1)
    {
        perror("semget");
        exit(1);
    }
    arg.val = 1;
    if (semctl(semid, s, SETVAL, arg) == -1)
    {
        perror("semctl");
        exit(1); }
    arg.val = 0;
    if (semctl(semid, n, SETVAL, arg) == -1)
    {
        perror("semctl");
        exit(1); }
    arg.val = count;
    if (semctl(semid, e, SETVAL, arg) == -1)
    {
        perror("semctl");
        exit(1); }
    queue<float> q[11];

    while(true)
    {
        wait.sem_num=n;
        if (semop(semid, &wait, 1) == -1)
        {
            perror("semop");
            exit(1); }
        wait.sem_num=s;
        if (semop(semid, &wait, 1) == -1)
        {
            perror("semop");
            exit(1); }
        
        if((shmid = shmget(key, count*sizeof(material), IPC_CREAT  | 0666))==-1)
        {
            exit(1);
        }
        material m;
        array = (material *)shmat(shmid, 0, 0);
        if (array==(material *)(-1))
        {
            exit(1);
        }
        m=array[0];
        
        for(int z=0;z<count;z++)
        {
            array[z]=array[z+1];
        }
        array[count-1].name="";
        array[count-1].price=0;
        
        

        shmdt((void *) array);
        
        
        signal.sem_num=s;
        if (semop(semid, &signal, 1) == -1)
        {
            perror("semop");
            exit(1); }
        signal.sem_num=e;
        if (semop(semid, &signal, 1) == -1)
        {
            perror("semop");
            exit(1); }
        
        transform(m.name.begin(), m.name.end(), m.name.begin(), ::tolower);
        
        
        string names[11]={"gold","silver","crudeoil","naturalgas","aluminium","copper","nickel","lead","zinc","menthaoil","cotton"};
        
        int currentMaterial=-1;
                
        if(m.name.compare("gold")==0)
        {
            currentMaterial=0;
        } else if(m.name.compare("silver")==0)
        {
            currentMaterial=1;
        }else if(m.name.compare("crudeoil")==0)
        {
            currentMaterial=2;
        }else if(m.name.compare("naturalgas")==0)
        {
            currentMaterial=3;
        }else if(m.name.compare("aluminium")==0)
        {
            currentMaterial=4;
        }else if(m.name.compare("copper")==0)
        {
            currentMaterial=5;
        }else if(m.name.compare("nickel")==0)
        {
            currentMaterial=6;
        }else if(m.name.compare("lead")==0)
        {
            currentMaterial=7;
        }else if(m.name.compare("zinc")==0)
        {
            currentMaterial=8;
        }else if(m.name.compare("menthaoil")==0)
        {
            currentMaterial=9;
        }else if(m.name.compare("cotton")==0)
        {
            currentMaterial=10;
        } else
        {
            cout<<"unknown material"<<m.name<<endl;
            exit(1);
        }
        if(q[currentMaterial].size()>=5)
        {
            q[currentMaterial].pop();
        }
        q[currentMaterial].push(m.price);
        cprice[currentMaterial][1]=cprice[currentMaterial][0];
        cprice[currentMaterial][0]=m.price;
        float total=0;
        for(int y=0;y<q[currentMaterial].size();y++)
        {
            total=total+q[currentMaterial].front();
            q[currentMaterial].push(q[currentMaterial].front());
            q[currentMaterial].pop();
        }
        avg[currentMaterial][1]=avg[currentMaterial][0];
        avg[currentMaterial][0]=total/(q[currentMaterial].size());
        
        display(cprice, avg);
    }
    return 0;
}
