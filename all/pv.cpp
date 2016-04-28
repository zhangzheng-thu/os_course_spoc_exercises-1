//
//  main.cpp
//  os_pv
//
//  Created by 张正 on 16/4/28.
//  Copyright (c) 2016年 张正. All rights reserved.
//

#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<cstdlib>

using namespace std;

sem_t mutex1,mutex2,empty,full,counts;
void init(){
    cout<<sem_init(&mutex1, 0, 1)<<endl;
    sem_init(&mutex2, 0, 1);
    sem_init(&empty, 0,10);
    sem_init(&full, 0, 1);
    sem_init(&counts, 0, 3);
}
int max_loop=5;
void* oldmonk(void* arg)
{
    int i=0;
    while (i<max_loop) {
        sem_wait(&full);
        sem_wait(&counts);
        sem_wait(&mutex2);
        printf("Old monk Get water and Drink water\n");
        //cout<<"Old monk Get water and Drink water"<<endl;
        sem_post(&mutex2);
        sem_post(&empty);
        sem_post(&counts);
        i++;
    }
    return NULL;
}
void* youngmonk(void* arg)
{
    int i=0;
    while (i<max_loop) {
        sem_wait(&empty);
        sem_wait(&counts);
        sem_wait(&mutex1);
        printf("Young monk Get Water\n");
        //cout<<"Young monk Get Water"<<endl;
        //sleep(2);
        sem_post(&mutex1);
        sem_wait(&mutex2);
        printf("Young monk pure water into the jar\n");
        //cout<<"Young monk pure water into the jar"<<endl;
        sem_post(&mutex2);
        sem_post(&counts);
        sem_post(&full);
        i++;
    }
    return NULL;
}
int main()
{
    init();
    pthread_t thread[2];
    pthread_create(&thread[0], 0, oldmonk, NULL);
    pthread_create(&thread[1], 0, youngmonk, NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(thread[i], 0);
    return 0;
}


