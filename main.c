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

void tabspace(int level){
    for(int i=0;i<level;i++)
        printf("\t");
}



void printtree(struct Node *head,int level){

    
    if(head==NULL){
        tabspace(level);
        printf("---<empty>---\n");
        return;
    }
    tabspace(level);
    printf("[%d ",(head->i->start));
    printf(", %d]\n",(head->i->end));
    
    tabspace(level);
    printf("--left--\n");
    printtree(head->left,level+1);
    
    tabspace(level);
    printf("--right--\n");
    printtree(head->right,level+1);
    
    
    
}


int main(){
    struct Node *head=NULL;
    
    
    head = addIntervals(head,1,3);
    head = addIntervals(head,2,6);
    head = addIntervals(head,4,5);
    head = addIntervals(head,3,10);
    
    printtree(head,0);
    
    return 0;
}