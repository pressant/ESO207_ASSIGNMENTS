#RFIB#

#include<stdio.h>
#include<time.h>
int fib(long long int n){
    if(n==0){return 0;}
    else if(n==1){return 1;}
    else{return (fib(n-1)%2021+fib(n-2)%2021)%2021;}
}
int main(){
    time_t start,end;
    double total;
    long long int n;
    scanf("%lld",&n);
    start=clock();
    printf("%d\n",fib(n));
    end=clock();
    total = (double)(end - start) /CLOCKS_PER_SEC;

    printf("%f",total);
    return 0;
}

#include<stdio.h>
#include<time.h>
int IFib(int n){
     int a=0,b=1;
    int c=0;
     if(n==0){return a;}
    else if(n==1){return b;}
    else{
       for(long long int i=1;i<n;i++){
       c=(a%2021+b%2021)%2021;
       a=b;
       b=c;
         }
    return c;
      }
}


#IFIB#

int main(){
    long long int n;
    time_t start,end;
    double total;
    
    scanf("%lld",&n);
   
    start=clock();
   
    printf("%d ",IFib(n));
    
    end=clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%f\n",total);
    return 0;
}

#CLEVERFIB#

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int** matmult(int** a,int** b)
{
    int **c = (int**)malloc(2*sizeof(int*));
    for(int i=0;i<2;i++){
        *(c+i) = (int*)malloc(2*sizeof(int));
    }
    c[0][0]=((((a[0][0]%2021)*(b[0][0]%2021))%2021+((a[0][1]%2021)*(b[1][0]%2021)))%2021)%2021;
    c[0][1]=((((a[0][0]%2021)*(b[0][1]%2021))%2021+((a[0][1]%2021)*(b[1][1]%2021)))%2021)%2021;
    c[1][0]=((((a[1][0]%2021)*(b[0][0]%2021))%2021+((a[1][1]%2021)*(b[1][0]%2021)))%2021)%2021;
    c[1][1]=((((a[1][0]%2021)*(b[0][1]%2021))%2021+((a[1][1]%2021)*(b[1][1]%2021)))%2021)%2021;
    return c;
}


int** matpow(int** a,long long int n){
    if(n==1){return a;}
    int **c = matpow(a,n/2);
    if(n%2==0){return matmult(c,c);}
    if(n%2==1){return matmult(c,matmult(c,a));}
}

    

int main(void) {
    clock_t start,end;
    double total;
    
    long long int n;
    scanf("%lld",&n);
    int **a = (int**)malloc(2*sizeof(int*));
    for(int i=0;i<2;i++){
        *(a+i) = (int*)malloc(2*sizeof(int));
    }
    a[0][0]=1;
    a[0][1]=1;
    a[1][0]=1;
    a[1][1]=0;
    int** d;
    
    start = clock();
    for(long long int i=0;i<10000;i++){
    d=matpow(a,n);
            }
    end= clock();
    printf("%d ",*(*d+1));
    
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n",total/10000);
    free(a);
	return 0;
}