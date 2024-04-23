#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(double *a,double *b){      //function to swap two numbers
    double p;
    p = *a;
    *a = *b;
    *b = p;
}


long long int comparisons_quicksort=0;
long long int comparisons_mergesort=0;
long long int comparisons_improvedmergesort=0;


int partition(double A[],int p,int r){       //partition for quick sort 

    
    double x=A[r];                              //pivot is the last element
    int i=p;
    int j=r;
    while(i<j){                                //when there is a comparision then we will increase the comparision counter by one
        comparisons_quicksort++;                //can be commented while calculating time stuff
        while(x<A[j] && i<=j){
            j--;
            comparisons_quicksort++;            //can be commented while calculating time stuff
            }
       comparisons_quicksort++;                 //can be commented while calculating time stuff
        while(x>A[i] && i<=j){
            i++;
            comparisons_quicksort++;            //can be commented while calculating time stuff
        }

        if(i<j){swap(&A[i],&A[j]);
        j--;i++;    
        }
          
    }
    if(i==j && j!=r && A[i]<=x){return i;}
    else{
          
          return i-1;
    }
}

void quicksort(double A[],int p,int r){    //code for quicksort
    if(p<r){
    int a= partition(A,p,r);
    
    quicksort(A,p,a);
    
    quicksort(A,a+1,r);
    
    }
}
void Merge_Sort(double *B, int l, int r){        //code for merge sort
     if(l>=r)
     return;

     int mid = (l+r)/2;
     
     Merge_Sort(B,l,mid);                         //recursive calls to merge sort
     Merge_Sort(B,mid+1,r);

    double *a,*b;
    a = (double*)malloc((mid-l+1)*sizeof(double));      //dynamically allocating the arrays 
    b = (double*)malloc((r-mid)*sizeof(double));

     for(int i = 0; i<mid-l+1; i++){              //since B is sorted from l to mid so
        a[i] = B[i+l];                           //array a will be sorted
     }

     for(int i = 0; i<r-mid; i++){              //array B is sorted from mid+1 to r so
        b[i] = B[mid+1+i];                      //array b will also be sorted 
     }

     int i = 0, j = 0,k = 0;

    while(i<=(mid-l) && j <= r-mid-1){          //copyint the arrays a and b to the array B such that B is sorted from l to r
       if(a[i] < b[j]){
        B[k+l] = a[i];
        i++;
       }
       else{
        B[l+k] = b[j];
        j++;
       }
       k++;
       comparisons_mergesort++;
    } 

    while(i<= (mid-l)){            // if the array a remains uncopied 
        B[k+l] = a[i];
        i++;
        k++;
    }
    while(j<= (r-mid-1)){        //if the array b remains uncopied
        B[k+l] = b[j];
        j++;
        k++;
    }

    free(a);                     //making the space allocated to arrays a and b to be free
    free(b);
}

//the improved merge sort is very much same as merge sort except in the merge sort we were declaring two arrays every time
//but in the improved merge sort we have declared the arrays once. since the array declaration also takes time so the improved
//merge sort takes less time
void Improved_Merge_Sort(double*arr1, int l, int r, double*improved_a, double *improved_b){
      if(l>=r)
     return;
                                                  
     int mid = (l+r)/2;

     Improved_Merge_Sort(arr1,l,mid, improved_a,improved_b);
     Improved_Merge_Sort(arr1,mid+1,r, improved_a ,improved_b);

     for(int i = 0; i<mid-l+1; i++){
        improved_a[i] = arr1[i+l];
     }

     for(int i = 0; i<r-mid; i++){
        improved_b[i] = arr1[mid+1+i];
     }

     int i = 0, j = 0,k = 0;

    while(i<=(mid-l) && j <= r-mid-1){
       if(improved_a[i] < improved_b[j]){
        arr1[k+l] = improved_a[i];
        i++;
       }
       else{
        arr1[l+k] = improved_b[j];
        j++;
       }
       k++;
       comparisons_improvedmergesort++;
    } 

    while(i<= (mid-l)){
        arr1[k+l] = improved_a[i];
        i++;
        k++;
    }
    while(j<= (r-mid-1)){
        arr1[k+l] =improved_b[j];
        j++;
        k++;
    }

}

int main(){
    int n;
    scanf("%d",&n);                     //taking length of array
    double *A,*B,*C;                    // declaring 3 arrays one for quick sort, one for merge sort and one for improved merge sort
    double *t=(double*)malloc(500*sizeof(double));   //time array for quick sort
    A=(double*)malloc(n*sizeof(double));
    B=(double*)malloc(n*sizeof(double));
    C=(double*)malloc(n*sizeof(double));
 int mergesort_outperformed_quicksort=0;
 int improvedmergesort_outperformed_quicksort=0;
 double time_merge=0;
 double time_improvedmerge=0;
 srand((unsigned)time(NULL)) ;
   
 int MAX_SIZE = 50 ;
 clock_t t1,t2,t3,t4;
  double total_t=0;
 
 for(int k=0;k<500;k++){
 for(int i=0;i<n;i++){
     A[i]=B[i]=C[i]=((double)rand()/RAND_MAX)*MAX_SIZE;      //all the 3 arrays are same 
   
 }
    double *improved_a = (double*)malloc((n+1)/2*(sizeof(double)));     //arrays for inproved merge sort
    double *improved_b = (double*)malloc((n+1)/2*(sizeof(double)));
 
    t1=clock();
    quicksort(A,0,n-1);
    t2=clock();
    Merge_Sort(B,0,n-1);
    t3=clock();
    Improved_Merge_Sort(C, 0,n-1,improved_a,improved_b);
    t4=clock();
    
    if(t3-t2<t2-t1) mergesort_outperformed_quicksort++;     // if mergesort is taking less time than quicksort 
    if(t4-t3<t2-t1) improvedmergesort_outperformed_quicksort++; //if improved merge sort is taking less time than quick sort
    free(improved_a);
    free(improved_b);
    t[k]=(double)(t2-t1);               //storing the time of quick sort in array
    total_t += (double)(t2-t1);         //summing up the time for quick sort
    time_merge+=(double)(t3-t2);         //summing up the time for merge sort
    time_improvedmerge+= (double)(t4-t3);  //summing up the time for improved merge sort
 }
 

FILE *file;

file = fopen("file_assignment#5.csv","w");

// code for table in the  part 1.1 
fprintf(file,"comparisons_quicksort_avg= %lld\n", comparisons_quicksort/500);
fprintf(file, "comparisons_mergesort_avg= %lld\n", comparisons_mergesort/500);
 
 //code for table in the part 2
 int e5=0;
 int e10=0;
 int e20=0;
 int e30=0,e50=0,e100=0;
     double avg=total_t/500;
    fprintf(file, "avg running(quicksort)= %f\n",avg);
    for(int i=0;i<500;i++){

        if(t[i]>1.05*avg) e5++;
        if(t[i]>1.10*avg) e10++;
        if(t[i]>1.20*avg) e20++;
        if(t[i]>1.30*avg) e30++;
        if(t[i]>1.50*avg) e50++;
        if(t[i]>2.0*avg) e100++;

    }   
fprintf(file,"e5= %d\ne10= %d\ne20= %d\ne30= %d\ne50= %d\ne100= %d\n",e5,e10,e20,e30,e50,e100);
// code for table in the part 1.3
fprintf(file, "avgtime_merge= %f\n",time_merge/500);
fprintf(file, "mergesort_outperformed_quicksort= %d\n",mergesort_outperformed_quicksort);
//code for table in the part 1.4
fprintf(file, "avgtime_improvedmerge= %f\n",time_improvedmerge/500);
fprintf(file, "improvedmergesort_outperformed_quicksort= %d\n",improvedmergesort_outperformed_quicksort);

return 0;
}
