//arrayImplementation

#include<stdio.h>
#include<stdlib.h>
#define max 10
int isEmpty(int front) {
    if(front==-1)
        return 1;
    else
        return 0;
}
int isFull(int rear) {
    if(rear==max)
        return 1;
    else
        return 0;
}
void insert(int *ar,int *front,int *rear,int item) {
    if(isFull(*rear)){
        printf("Overflow\n");
        return;
    }
    if(*front==-1 && *rear==-1) {
        // printf("dd");
        *front=*front+1;
        *rear=*rear+1;
        ar[*front]=item;
    }
    else {
        *rear=*rear+1;
        ar[*rear]=item;
    }
}
void delete(int *front,int *rear) {
    if(isEmpty(*front)||(*rear<*front)){
        printf("Underflow\n");
        return;
    }
    *front=*front+1;
}
void print(int *arr,int front,int rear) {
    for(int i=front;i<=rear;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
void main() {
    int item=0,front=-1,rear=-1,ar[max];
    int ch=0;
    while(ch!=69) {
        scanf("%d",&ch);
        if(ch==1){
            scanf("%d",&item);
            insert(ar,&front,&rear,item);
        }
        if(ch==2)
            delete(&front,&rear);
    }
    print(ar,front,rear);
    printf("%d %d %d\n",front,rear,ar[front]);
}