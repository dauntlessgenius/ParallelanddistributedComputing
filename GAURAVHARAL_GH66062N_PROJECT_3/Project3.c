
/*Program Parallel Sieve Number*/
#include <math.h>
#include <stdlib.h>
#define n 50
int i,number,location,x;
boolean prime[n+1];

void compute(boolean primes[n+1]){
for(i = 1; i <= n; i++)
{
primes[i]=True;
}
}

void calculate(){
for(number = 2; number <= Sqrt(n); number++) /* initializing array values to true in portions of sqrt(50) i.e. 7.07 */
  if(prime[number]){
    location = number+number;
    while(location<=n){
    prime[location] = False;
    location = location + number;
}
}

}

main()
{
compute(prime);
forall x=1 to 5 do 
calculate();

}