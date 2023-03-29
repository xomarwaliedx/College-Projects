//producer
//  main.cpp
//  Project 4
//  Created by Omar Walid on 07/12/2022.
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <ctime>
#include <sys/sem.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

struct material
{
    string name="";
    float price=0;
};

int main(int argc, const char * argv[]) {
    char buffer[21];
    long millisec;
    struct tm* tm_info;
    struct timeval tv;
    
    
    
    int n=0,s=1,e=2;
    string name=argv[1];
    float mean=atof(argv[2]);
    float variance=atof(argv[3]);
    int shmid;
    int semid;
    material *array;
    //    int count = stoi(argv[1])+1;
    int i = 0;
    int delay=atoi(argv[4]);
    int count = atoi(argv[5]);
    //int SizeMem;
    key_t key =65;
    key_t semKey =66;
    struct sembuf wait = {0, -1, 0};
    struct sembuf signal = {0, 1, 0};
    
    if ((semid = semget(semKey, 3, 0666 | IPC_CREAT)) == -1)
    {
        perror("semget");
        exit(1);
        
    }
    //SizeMem = sizeof(*array)*count;
    random_device r;{} ;
    mt19937 make(r());
    normal_distribution<> norm(mean,variance) ;
    
    while (true)
    {
        float currentPrice=norm(make);

        
        gettimeofday(&tv, NULL);
        millisec = lrint(tv.tv_usec/1000.0);
        if (millisec>=1000) {
          millisec -=1000;
          tv.tv_sec++;
        }
        tm_info = localtime(&tv.tv_sec);
        strftime(buffer, 26, "[%m/%d/%Y %H:%M:%S", tm_info);
        printf("%s.%03ld] ", buffer, millisec);
        printf("%s: generating a new value %f\n",&name,currentPrice);

        
        gettimeofday(&tv, NULL);
        millisec = lrint(tv.tv_usec/1000.0);
        if (millisec>=1000) {
          millisec -=1000;
          tv.tv_sec++;
        }
        tm_info = localtime(&tv.tv_sec);
        strftime(buffer, 26, "[%m/%d/%Y %H:%M:%S", tm_info);
        printf("%s.%03ld] ", buffer, millisec);
        printf("%s: trying to get mutex on shared buffer\n",&name);
        wait.sem_num=e;
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
        m.name=name;
        m.price=currentPrice;
        array = (material *)shmat(shmid, 0, 0);
        if (array==(material *)(-1))
        {
            exit(1);
        }
        int emptyCell=-1;
        bool em=true;
        for(i=0; i<count; i++)
        {
            if(array[i].name!="")
            {
                em=false;
            }
        }
        
        if ((array[0].name==""&&array[count-1].name!="")||em==true)
        {
            emptyCell=0;
        }
        if(array[0].name=="")
        {
            emptyCell=0;
        }else{
            for(i=1; i<count; i++)
            {
                if(array[i].name==""&&array[i-1].name!="")
                {
                    emptyCell=i;
                    break;
                }
            }
        }
        gettimeofday(&tv, NULL);
        millisec = lrint(tv.tv_usec/1000.0);
        if (millisec>=1000) {
          millisec -=1000;
          tv.tv_sec++;
        }
        tm_info = localtime(&tv.tv_sec);
        strftime(buffer, 26, "[%m/%d/%Y %H:%M:%S", tm_info);
        printf("%s.%03ld] ", buffer, millisec);
        printf("%s: placing %f on shared buffer\n",&name,currentPrice);
        if (emptyCell!=-1)
        {
            array[emptyCell]=m;
        }
        
//        for(i=0; i<count; i++)
//        {
//            cout<<array[i].name<<"\t"<<array[i].price<<endl;
//        }
        
        shmdt((void *) array);
        
        signal.sem_num=s;
        if (semop(semid, &signal, 1) == -1)
        {
            perror("semop");
            exit(1); }
        signal.sem_num=n;
        if (semop(semid, &signal, 1) == -1)
        {
            perror("semop");
            exit(1); }
        gettimeofday(&tv, NULL);
        millisec = lrint(tv.tv_usec/1000.0);
        if (millisec>=1000) {
          millisec -=1000;
          tv.tv_sec++;
        }
        tm_info = localtime(&tv.tv_sec);
        strftime(buffer, 26, "[%m/%d/%Y %H:%M:%S", tm_info);
        printf("%s.%03ld] ", buffer, millisec);
        printf("%s: sleeping for %d ms\n",&name,delay);
        usleep(delay);
    }
    return 0;
}
