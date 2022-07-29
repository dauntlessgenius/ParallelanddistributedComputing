
/*Project 4*/
/*BucketSort*/

#include<math.h>
#include<stdlib.h>
#define n 500
#define b 50
#define range 400
int i,j;
int initial;
spinlock L;
spinlock T;
int array[n];
int buckets[b][n];

void fill(){
int i;

for(i = 0; i<n;i++)
  array[i]= (rand()%420);
  
  }


void swapping
(int *d, int *e)
{
 int initial = *d;
 *d = *e;
  *e = initial;

}

void bubble(int test[][n], int n)
{

  int i,j, a;
 for(a = 0; a < b; a++)
  for(i = 0; i < n -1;i++)
   for(j = 0; j < n-i-1;j++)
     if(test[a][j] > test[a][j+1])
       swapping(&test[a][j],&test[a][j+1]);

}

void bucketsort(){


int interval = range/b;


int z;

for(i = 0; i < n; i++)
{ 

    buckets[array[i]/interval][i]= array[i];
}


  bubble(buckets, n);


}


void merger(){
int c,r,initialer,z;
int counter = 0;
for(c=0;c<b;c++)
 for(r=0;r<n;r++){
   if(buckets[c][r] != 0){
   Lock(L);
   initialer = buckets[c][r];
     Unlock(L);
    array[counter]=initialer;
    counter++;
  }}

}

/*driver code*/
/*main*/

main()
{
int q;
forall q=1 to 10000 grouping 4 do
fill();
bucketsort();
merger();
int f,l;
 for(l = 0; l <10;l++)
   cout << array[l];

}


