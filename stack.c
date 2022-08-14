

#include<stdio.h>

#define Max 10
int stack_arr[Max];
int top=-1;


void push(int data){
    if (top==Max-1){
        printf("stack overflow");
        return;
    }
    top+=1;
    stack_arr[top]=data;
}
int pop(){
    
}



int main()
{
 return 0;
}