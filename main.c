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
    node->i->start=end;
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
        head->right=addIntervals(head->right,start,end);
    }else{
        head->left=addIntervals(head->left,start,end);
    }
    
    if(head->max<end){
        head->max=end;
    }
    
    return head;

}

int main(){
    struct Node *head=NULL;
    
    
    head = addIntervals(head,1,3);
    
    return 0;
}