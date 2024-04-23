#include<stdio.h>
#include <stdlib.h>

struct node{
    int val ,row ,clm;
    struct node *right,*down;
};

struct node *Row_head1 = NULL, *Row_head2 = NULL; // for row and column numbers
struct node *Column_head1 = NULL, *Column_head2 = NULL;

void Make_row_head1(int n){

    for( int i = 0; i<n; i++){

        struct node*temp = (struct node*)malloc(1*sizeof(struct node));

        temp->val = 0;
        temp->clm = 0;
        temp->row = i+1;
        temp->right = NULL;
        temp->down = NULL;

        if(Row_head1== NULL){    //for matrix 1
            Row_head1 = temp;
        }
        else{
            struct node *test1 = Row_head1;

            while(test1->down != NULL){
                test1 = test1->down;
            }
            test1->down = temp;
        }
    }
}

void Make_row_head2(int n){

    for(int i = 0; i<n; i++){

        struct node*temp = (struct node*)malloc(1*sizeof(struct node));

        temp->val = 0;
        temp->clm = 0;
        temp->row = i+1;
        temp->right = NULL;
        temp->down = NULL;

        if(Row_head2== NULL){    //for matrix 2
            Row_head2 = temp;
        }
        else{
            struct node *test2 = Row_head2;

            while(test2->down != NULL){
                test2 = test2->down;
            }
            test2->down = temp;
        }
    }
}

void Make_column_head1(int n){

    for(int i = 0; i<n; i++){

        struct node*temp = (struct node*)malloc(sizeof(struct node));
        temp->val = 0; 
        temp->row = 0;
        temp->clm = i+1;

        if(Column_head1 == NULL){
            Column_head1 = temp;
        }
        else{
            struct node*test1 = Column_head1;

            while(test1->right != NULL){
                test1 = test1->right;
            }
            test1->right = temp;
        }
    }
}

void Make_column_head2(int n){

    for(int i = 0; i<n; i++){

        struct node*temp = (struct node*)malloc(sizeof(struct node));
        temp->val = 0; 
        temp->row = 0;
        temp->clm = i+1;

        if(Column_head2 == NULL){
            Column_head2 = temp;
        }
        else{
            struct node*test2 = Column_head2;

            while(test2->right != NULL){
                test2 = test2->right;
            }
            test2->right = temp;
        }
    }
}

struct node *Make_node(int val, int row,int column){
    
    struct node *nd = (struct node*)malloc(1*sizeof(struct node));
    nd->val = val;
    nd->row = row;
    nd->clm = column;
    nd->right = NULL;
    nd->down = NULL;

    return nd;
}

void freeright(struct node* head)
{
   struct node* temp;

   while (head != NULL)
    {
       temp = head;
       head = head->right;
       free(temp);
    }

}
void freedown(struct node* head)
{
   struct node* temp;

   while (head != NULL)
    {
       temp = head;
       head = head->down;
       free(temp);
    }

}
void input_matrices(int n){
    int mat_num;
        
    Make_row_head1(n);
  Make_row_head2(n);// allocating space to the link list for row number
  Make_column_head1(n);
  Make_column_head2(n);// allocatoing space to the link list for column number

  scanf("%d", &mat_num);

  while(mat_num!=0){
        int row,column,val;
        scanf("%d%d%d",&row, &column, &val);

        if(mat_num == 1){
            struct node *temp_row = Row_head1, *temp_column = Column_head1;

            for(int i = 1; i<row; i++){
                temp_row = temp_row->down;
            }
            while(temp_row->right != NULL){
                temp_row = temp_row->right;
            }

            for(int i = 1; i<column; i++){
                temp_column = temp_column->right;
            }
            while(temp_column->down != NULL){
                temp_column = temp_column->down;
            }

            struct node *insert = Make_node(val,row,column);

            temp_row->right = insert;
            temp_column->down = insert;
        }

        else if(mat_num == 2){
                struct node *temp_row = Row_head2, *temp_column = Column_head2;

                for(int i = 1; i<row; i++){
                    temp_row = temp_row->down;
                }
                while(temp_row->right != NULL){
                    temp_row = temp_row->right;
                }

                for(int i = 1; i<column; i++){
                    temp_column = temp_column->right;
                }
                while(temp_column->down != NULL){
                    temp_column = temp_column->down;
                }

                struct node *insert = Make_node(val,row,column);

                temp_row->right = insert;
                temp_column->down = insert;

            }
        
        scanf("%d",&mat_num);
    }
    
}
void printing_resultant_matrix(struct node*Row_head1,struct node* Column_head2,int n){
    struct node *temp_row = Row_head1,*temp_column = Column_head2;
    int flag=0;
    for( int i = 1; i<=n; i++){
    
    temp_column = Column_head2;
    
    for(int k = 1; k<=n; k++){
        
        struct node *Row1 = temp_row->right;
        struct node *Column2 = temp_column->down;
        
      int sum = 0;
        
        while(Row1!= NULL && Column2 != NULL){
            
            while(Row1 != NULL && Column2 != NULL && Row1->clm != Column2->row){
                
                if(Row1->clm > Column2->row){
                    Column2 = Column2->down;
                }
                else if(Row1->clm < Column2->row){
                    Row1 = Row1->right;
                }
            }
            
            if(Row1 != NULL && Column2 != NULL && Row1->clm == Column2->row){
                sum += (Row1->val)*(Column2->val);
            }
            if(Row1!= NULL)
              Row1 = Row1->right;
            if(Column2!= NULL)
              Column2 = Column2->down;
        }
        
        if(sum){flag=1;
            printf("%d %d %d\n", i, k, sum);
        }
        
        temp_column = temp_column->right;
    }
    temp_row = temp_row->down;
}
if(flag==0){printf("NULL MATRIX!");}
}
int main(){

   int n;
   scanf("%d", &n);
   
  input_matrices(n);

  printing_resultant_matrix(Row_head1,Column_head2,n);

    for(int i=0;i<n;i++){
         if(Row_head1->right!=NULL) freeright(Row_head1->right);
        Row_head1=Row_head1->down;
    }
    freedown(Row_head1);
    freeright(Column_head1);
    for(int i=0;i<n;i++){
        if(Row_head2->right!=NULL) freeright(Row_head2->right);
        Row_head2=Row_head2->down;
    }
    freedown(Row_head2);
    freeright(Column_head2);

return 0;
 }