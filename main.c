#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//creation of interval structure 
typedef struct{
    int start;
    int end;
    
}interval;

//creation of Node structure
struct Node{
    interval *i;

    struct Node *left;
    struct Node *right;
  
};

//function to create a new node
struct Node *createNode(int start, int end){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)); //manual memory allocation of node
    node->i=(interval *)malloc(sizeof(interval)); //manual memory allocation of i(pair) within node
    node->i->start=start; //assigning start value of interval
    node->i->end=end; //assigning end value of interval
    node->left=NULL; //creates left branch of the tree
    node->right=NULL; //creates right branch of the tree
    
    return node;
}

//function to check for overlap in intervals
bool overlap_bool(interval a, interval b){
    if(a.start<=b.end && b.start<=a.end){// if {1,3} & {2,5} exist, first condition returns true & second conditio returns true, therefore it returns true
        return true; //returns true if end value of b is greater than or equal to start value of and if end value of a is greater than of equal to start value of b
    }
    return false;
}

//adds the new node to the existing tree associated through head without merging any intervals
struct Node *addIntervals(struct Node *head,int start,int end){
    
    if(head==NULL){
        return createNode(start,end); //if head is empty, creates a top node
    }

    if(head->i->start>start){
        head->left=addIntervals(head->left,start,end); //if start value of head's pair is greater than start value, goes to left branch
    }else{
        head->right=addIntervals(head->right,start,end);//if start value of head's pair is lesser than start value, goes to right branch
    }

    
    return head;

}

//function to merge the intervals a and b
void mergeIntervals(interval *a, interval b) { // a is taken as pointer so that a's value an be modified easily and used again in recursive code
    a->start=(a->start<=b.start)?a->start:b.start; //if start value of b is greater than of a, a->start=a->start else b.start
    a->end=(a->end>=b.end)?a->end:b.end;//if end value of a is greater than of b, a->end=a->end else b.end
    //hence in {1,3}{2,5} it produces the output {1,5}


}
//function to merge the intervals in the tree
struct Node *addMergedIntervals(struct Node *head,int start,int end){
    
    if(head==NULL){
        return createNode(start,end);
    }
    
    interval temp={start,end};
    
    if(overlap_bool(*(head->i),temp)){//if the value of overlap is true, then it merges and head pointer's value is updated as the new merged interval
        mergeIntervals(head->i,temp);
        
    }else if(start<head->i->start){
        head->left=addMergedIntervals(head->left,start,end); //to access the left branch of current head node in the merge
        
    }else{
        head->right=addMergedIntervals(head->right,start,end); //to access the right branch of current head node in the merge
        
    }

    return head; //returns the head pointer

}
//function to give proper spacing according to the level
void tabspace(int level){
    for(int i=0;i<level;i++)
        printf("\t");
}

//function to print the tree
void printtree(struct Node *head,int level){

//returns empty if the value of head is null
    if(head==NULL){
        tabspace(level);
        printf("---<empty>---\n");
        return;
    }

    //prints out the interval stored in i structure which is stored within node structure
    tabspace(level);
    printf("[%d ",(head->i->start));
    printf(", %d]\n",(head->i->end));
    
    tabspace(level);
    printf("|left|\n");
    printtree(head->left,level+1); //to access and print the left side of the current head node
    
    tabspace(level);
    printf("|right|\n");
    printtree(head->right,level+1); //to access and print the left side of the current head node
    
    
    
}
//main code
int main(){
    //two heads are created to print out two separate interval trees for better explanation
    struct Node *head=NULL;
    struct Node *head2=NULL;
    
    //menu driven program
    int menu;
    printf("======================\n");
    printf("         MENU         \n");
    printf("======================\n");
    printf("1.Add Interval\n");
    printf("2.Print Non-Merged Intervals\n");
    printf("3.Print Merged Intervals\n");
    printf("4.Exit\n");
    
    
    while(1){ //remains 1 until program is exited at menu=4
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
    
    return 0; //returns 0
}