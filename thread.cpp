#include<windows.h>  //Thread for Win32
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#define MAX_THREADS 2
#define BUFFER_SIZE 10
using namespace std;

DWORD WINAPI Producer(LPVOID);
DWORD WINAPI Consumer(LPVOID);
HANDLE hThreads[MAX_THREADS];
DWORD id[MAX_THREADS];
DWORD waiter;

int buffer[BUFFER_SIZE];
int count;

void IncreaseCount(int data){
    buffer[count++]=data;
}
int ReduceConsumed(){
    return(buffer[--count]);
}
DWORD WINAPI Producer(LPVOID n){
    count<<"Thread started (Producer) ....\n";
    int data;
    srand(time(NULL));
    
    for(int i=0, i<(int)n; i++){
        data = rand()%100;
        cout<<"Producer put the number: "<<data<<endl;
        IncreaseCount(data);
    }
    cout<<"...(Producer) Thread therminating. \n";
    return(DWORD)n;
}
int main(int argc, const char * argv[]) {
    int num1, num2;
    cout<<"Type number(1): "<<endl;
    cin>>num1;
    cout<<"Type number(2): "<<endl;
    cin>>num2;
    
    hThreads[0] = CreateThread(NULL, 0, Producer, (LPVOID)num1, NULL, &id[0]);
    hThreads[1] = CreateThread(NULL, 0, Producer, (LPVOID)num2, NULL, &id[0]);
    waiter = WaitForMultipleObjects(MAX_THREADS, hThreads, TRUE, INFINITE);
    for(int i=0, i < MAX_THREADS; i++){
        for(int i=0; i < MAX_THREADS; i++){
            CloseHandle(hThreads[1]);  //API functjion
        }
    }
    return 0;
}

