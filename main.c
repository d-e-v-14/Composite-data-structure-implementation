#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 100

typedef struct{
    int start;
    int end;
    
}interval;

struct Node{
    interval *i;
    int max;
    struct Node *left;
    struct Node *right;
  
};


struct Node *createNode(int start, int end){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->i=(interval *)malloc(sizeof(interval));
    node->i->start=start;
    node->i->end=end;
    node->max=end;
    node->left=NULL;
    node->right=NULL;
    
    return node;
}

struct Node *addIntervals(struct Node *head,int start,int end){
    
    if(head==NULL){
        return createNode(start,end);
    }

    if(head->i->start>start){
        head->left=addIntervals(head->left,start,end);
    }else{
        head->right=addIntervals(head->right,start,end);
    }
    
    if(head->max<end){
        head->max=end;
    }
    
    return head;

}

void printtree(struct Node *head){
    if(head==NULL){
        printf("---<empty>---\n");
        return;
    }
    
    printf("start: %d\n",(head->i->start));
    printf("end: %d\n",(head->i->end));
    
    printf("--left--\n");
    printtree(head->left);
    
    printf("--right--\n");
    printtree(head->right);
    
    
}


int main(){
    struct Node *head=NULL;
    
    
    head = addIntervals(head,1,3);
    head = addIntervals(head,2,6);
    head = addIntervals(head,4,5);
    head = addIntervals(head,3,10);
    
    printtree(head);
    
    return 0;
}