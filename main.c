#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ROW 2
#define MAX_COL 2

int count=0;

typedef struct node
{
char data;
int i;
int j;
struct node * nc;
struct node * nl;

}node;

node *col_tab[MAX_COL];
node *row_tab[MAX_ROW];

void insert_node(int,int,char);
bool test_col();
bool is_full();

int main()
{

insert_node(1,1,'*');


printf("%s",(test_col())?"true":"false");

printf("\n");
return 0;
}
node * create_new_node(int i,int j, int data){
    node *new_node;
    new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->i = i;
    new_node->j = j;
    new_node->nc = NULL;
    new_node->nl = NULL;
    return new_node;
}

void insert_node(int i,int j,char data){
if(i > MAX_ROW || j > MAX_COL){
    printf("this index don't exist!");
}
else if(is_full()){
    printf("the matrix is full !");
}

else{
    if(row_tab[i-1] == NULL && col_tab[j-1] == NULL){
        node * node = create_new_node(i,j,data);
        col_tab[j-1] = node;
        row_tab[i-1] = node;
}
    else if(row_tab[i-1] == NULL){
        node * cur1 = col_tab[j-1];
        node * node = create_new_node(i,j,data);
        row_tab[i-1] = node;
        if(col_tab[j-1]->i < i){
            while(cur1->nl!=NULL && cur1->nl->i < node->i)
                cur1 = cur1->nl;
            node->nl = cur1->nl;
            cur1->nl = node;
        }
        else{
            row_tab[i-1]->nl = col_tab[j-1];
            col_tab[j-1] = row_tab[i-1];
        }
}
    else if(col_tab[j-1] == NULL){
        node * cur = row_tab[i-1];
        node * node = create_new_node(i,j,data);
        col_tab[j-1] = node;
        if(row_tab[i-1]->j < j){
            while(cur->nc!=NULL && cur->nc->j < node->j)
                cur = cur->nc;
            node->nc = cur->nc;
            cur->nc = node;
        }
        else{

            col_tab[j-1]->nc = row_tab[i-1];
            row_tab[i-1] = col_tab[j-1];
        }
    }
    else{
        node * cur2 = col_tab[j-1];
        node * node = create_new_node(i,j,data);
        while(cur2->nl!=NULL)
            cur2 = cur2->nl;
        cur2->nl=node;
        cur2 = row_tab[i-1];
        while(cur2->nl!=NULL)
            cur2 = cur2->nc;
        cur2->nc=node;
    }

count ++;
}

}

bool is_full(){
return count == MAX_COL * MAX_ROW;
}
bool is_empty(){
return count == 0;
}

bool test_col(){
int c =0,p=0;
for(int i=0;i<MAX_ROW;i++){
    node * cur = row_tab[i];
    while(cur!=NULL){

    c++;
    cur = cur->nc;
}

}
for(int i=0;i<MAX_COL;i++){
    node * cur = col_tab[i];
    while(cur!=NULL){

    p++;
    cur = cur->nl;
}

}
return p == c;
}


