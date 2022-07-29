/* I found out that Apple m1 chip only allowed to run up to 500 integers, it failed for more integers and gave error later */

#include <stdlib.h>
#include <math.h>
#define n 500
#define tolerance 3
float X[n+2][n+2], Y[n+2][n+2];
int i,j;
float diff, abs_diff;
int count;
spinlock Arrival, Departure;
boolean globaltest;
int stream synchan[n];
int stream high[n+1];
int stream low[n+1];

/* method for test for efficient barrier */


void Barrier(int i){
int temp;
if(i > 1)
  send(high[i-1],1);
if(i < n){
 send(low[i+1],1);
 recv(high[i],temp);
}
 if(i >1)
 recv(low[i],temp);
}

/*method for test for Aggregation */


boolean Aggregation(boolean mytest){
boolean solution;

Lock(Arrival);
count = count +1;
globaltest = globaltest && mytest;
if(count <n)
 Unlock(Arrival);
  else Unlock(Departure);

Lock(Departure);
count = count -1;
solution = globaltest;
if(count > 0)
 Unlock(Departure);
else{
 Unlock(Arrival);
 globaltest = true;
}
return(solution);

}

main()
{

count = 0;
Unlock(Arrival);
Lock(Departure);
globaltest=true;

for(i=0;i<=n+1;i++){
 for(j=0;j<=n+1;j++)
   X[i][j] = (rand()%n);}

Y=X;
forall i =1 to n do{
int j;
float diff,abs_diff;
boolean test;

do{
 abs_diff=0;
 for(j=1;j<=n;j++){
 Y[i][j] = (X[i-1][j] + X[i+1][j] + X[i][j+1] +  X[i][j-1])/4;
diff = fabs(Y[i][j] - X[i][j]);
if(diff > abs_diff) abs_diff = diff;
Barrier(i);
X[i]=Y[i];
Barrier(i);

}

test = Aggregation(abs_diff<tolerance);
}while(!test);

}

}

