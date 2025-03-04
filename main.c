#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int start;
    int end;
    
}interval;

struct Node{
    interval *i;

    struct Node *left;
    struct Node *right;
  
};

struct Node *createNode(int start, int end){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->i=(interval *)malloc(sizeof(interval));
    node->i->start=start;
    node->i->end=end;
    node->left=NULL;
    node->right=NULL;
    
    return node;
}

bool overlap_bool(interval a, interval b){
    if(a.start<=b.end && b.start<=a.end){
        return true;
    }
    return false;
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

    
    return head;

}

void mergeIntervals(interval *a, interval b) {
    a->start=(a->start<b.start)?a->start:b.start;
    a->end=(a->end>b.end)?a->end:b.end;
}

struct Node *addMergedIntervals(struct Node *head,int start,int end){
    
    if(head==NULL){
        return createNode(start,end);
    }
    
    interval temp={start,end};
    
    if(overlap_bool(*(head->i),temp)){
        mergeIntervals(head->i,temp);
        
    }else if(start<head->i->start){
        head->left=addIntervals(head->left,start,end);
        
    }else{
        head->right=addIntervals(head->right,start,end);
        
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
    printf("|left|\n");
    printtree(head->left,level+1);
    
    tabspace(level);
    printf("|right|\n");
    printtree(head->right,level+1);
    
    
    
}

int main(){
    struct Node *head=NULL;
    struct Node *head2=NULL;
    
    int menu;
    printf("======================\n");
    printf("         MENU         \n");
    printf("======================\n");
    printf("1.Add Interval\n");
    printf("2.Print Non-Merged Intervals\n");
    printf("3.Print Merged Intervals\n");
    printf("4.Exit\n");
    
    
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&menu);
        printf("\n");
        
        if(menu==1){
                int a,b;
                printf("Enter Intervals: ");
                scanf("%d %d",&a,&b);
                printf("\n");
                head=addIntervals(head,a,b);
                head2=addMergedIntervals(head2,a,b);
                printf("Task Completed!\n");

        }else if(menu==2){
            printf("\n----Non-Merged Intervals----\n");
            printtree(head,0);

        }else if(menu==3){
            printf("\n----Merged Intervals----\n");
            printtree(head2,0);

        }else if(menu==4){
            printf("\nExit Complete!");
            break;
        }else{
            printf("Invalid Input!\n");

        }

    }
    
    return 0;
}