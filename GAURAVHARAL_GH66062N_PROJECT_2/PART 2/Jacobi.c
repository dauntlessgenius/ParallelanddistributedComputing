
#include <stdlib.h>
#include <math.h>
#define num 115
int i;
float B[115][115];
/*Phase I - Compute new values*/

void computing(float A[num][num]){
int x,y;
for(x = 1; x< 115;x++){
   for(y = 1; y < 115; y++){
     A[x][y] = (rand() % 1000);
    }
}
}
void smoothing(float C[num][num]){
int i,j;
for(i = 2; i < 114; i++){
  for(j = 2; j < 114; j++){
    C[i][j] = (C[i - 1][j] + C[i + 1][j] + C[i][j+1] + C[i][j-1]) / 4;
}} 
}
/*Phase II - Copy new values back to A*/
main()
{
computing(B);
forall i = 1 to (num/10) do
      smoothing(B);
}


