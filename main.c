#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ROW 3
#define MAX_COL 3

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
void search_node_with_col(char);
void search_node_with_col(char );
void display_cont();

int main()
{
int k = '1';
for(int i=1;i<=MAX_ROW;i++){
    for(int j=1;j<=MAX_COL;j++){
        insert_node(i,j,k);
        k++;
    }

}


display_cont();
search_node_with_col('1');

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
        if(col_tab[j-1]->i < i){
        while(cur2->nl!=NULL)
            cur2 = cur2->nl;
        cur2->nl=node;
        }
        else{
            node->nl = col_tab[j-1];
            col_tab[j-1] = node;
        }
        cur2 = row_tab[i-1];
        if(row_tab[i-1]->j < j){
        while(cur2->nc!=NULL)
            cur2 = cur2->nc;
        cur2->nc=node;
        }
        else{
            node->nc = row_tab[i-1];
            row_tab[i-1] = node;
        }
    }

count ++;
}

}

void delete_node(int i,int j){
if(col_tab[j-1] == NULL && row_tab[i-1] == NULL)
    printf("this node not exist");



}

void search_node_with_col(char data){
int c = 0;
for(int i=0;i<MAX_ROW;i++){
    node * cur = row_tab[i];
    while(cur->nc!=NULL && cur->data != data)
        cur = cur->nc;
    if(cur->data == data){
        printf("The \" %c \" is found and index i=%d,j=%d",data,cur->i,cur->j);
        c = 1;
        break;
    }

}
if(c==0)
    printf("this \"%c\" not exist !",data);
}

void search_node_with_row(char data){
int c = 0;
for(int i=0;i<MAX_COL;i++){
    node * cur = col_tab[i];
    while(cur->nl!=NULL && cur->data != data)
        cur = cur->nl;
    if(cur->data == data){
        printf("The \"%c\" is found and index i=%d,j=%d",data,cur->i,cur->j);
        c = 1;
        break;
    }

}
if(c==0)
    printf("this \"%c\" not exist !",data);

}



bool is_full(){
return count == MAX_COL * MAX_ROW;
}


bool is_empty(){
return count == 0;
}



/*bool test_col(){
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

}*/
/*void display_conta(){
    for(int i=0;i<MAX_ROW;i++){
        printf("%p-",row_tab[i]);
    }
    printf("\n\n\n");
    for(int i=0;i<MAX_COL;i++){
        printf("%p-",col_tab[i]);
    }
    printf("\n\n\n");
for(int i=0;i<MAX_ROW;i++){
    node * cur = row_tab[i];
    while(cur!=NULL){
    printf("%p-%d-%d-%c-%p-%p \t",cur,cur->i,cur->j,cur->data,cur->nc,cur->nl);
    cur = cur->nc;
}
printf("\n\n\n\n");

}

}*/




void display_cont(){
for(int i=0;i<MAX_ROW;i++){
    node * cur = row_tab[i];
    while(cur!=NULL){
    printf("%c-", cur->data);
    cur = cur->nc;
}
printf("\n");

}

}
