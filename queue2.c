#include<stdio.h>
#include<stdlib.h>

struct qnode {
    int val;
    struct qnode *next;
};
int isEmpty(struct qnode * front,struct qnode* rear) {
    if(front==NULL && rear==NULL)
        return 1;
    else
        return 0;
}
void insert(struct qnode **front,struct qnode **rear,int x) {
    struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
    temp->val=x;
    temp->next=NULL;
    if(*front==NULL) {
        *front=temp;
        *rear=temp;
    }
    else {
        (*rear)->next=temp;
        *rear=temp;
    }
}
void delete(struct qnode **front) {
    if((*front==NULL)) {
        printf("Underflow\n");
        return;
    }
    *front=(*front)->next;
}
void print(struct qnode *front) {
    for(struct qnode *i=front;i!=NULL;i=i->next)
        printf("%d  ",i->val);
    printf("\n");
}
void main() {
    int item,ch;
    struct qnode *front=NULL,*rear=NULL;
        while(ch!=69) {
        scanf("%d",&ch);
        if(ch==1){
            scanf("%d",&item);
            insert(&front,&rear,item);
        }
        if(ch==2)
            delete(&front);
    }
    // for(int i=1;i<=10;i++) {
    //     insert(&front,&rear,i);
    // }
    print(front);
}