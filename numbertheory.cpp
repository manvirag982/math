// gcd(a,b)=d  /// gcd(a/d,b/d)=1
// math full 

//LCM(1,n)+LCM(2,n)+…+LCM(n−1,n)=sum   
// proof https://forthright48.com/spoj-lcmsum-lcm-sum/
// 2*sum=n/2*( summation(phi(d)*d)) + 1)  // d is divisor of n
#include<bits/stdc++.h>
using namespace std;
#define mod 10000007
int x,y,d,n;
const int MAX=1e5;
int prime[MAX];
int extendedeuclid(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = extendedeuclid(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
// note that this code does not consider the case a=b=0)
// linear diphantine equation checking for a single solution // diphantine equation  solution is integer solution // if no restriction infinite no of solution
// c  is divisible by g=gcd(a,b), then the given Diophantine equation has a solution, otherwise it does not have any solution. 
// for multiple solution visit cp algorithm
// Find the solution with minimum value of x+y
// find the no of solution visit co algorithm
/*Getting all solutions
From one solution (x0,y0)==upper solution, we can obtain all the solutions of the given equation.

Let g=gcd(a,b) and let x0,y0 be integers which satisfy the following:

a⋅x0+b⋅y0=c
Now, we should see that adding b/g to x0, and, at the same time subtracting a/g from y0 will not break the equality:

a⋅(x0+b/g)+b⋅(y0−a/g)=a⋅x0+b⋅y0+a⋅b/g−b⋅a/g=c
Obviously, this process can be repeated again, so all the numbers of the form:

"x=x0+k⋅b/g"    // this can be used to check whether solution may be positive 
"y=y0−k⋅a/g"
are solutions of the given Diophantine equation.

// Moreover, this is the set of all possible solutions of the given Diophantine equation.*/
// Chicken McNugget Theorem
// The Chicken McNugget Theorem (or Postage Stamp Problem or Frobenius Coin Problem) states that for any two relatively prime positive integers $m,n$, the greatest integer that cannot be written in the form $am + bn$ for nonnegative integers $a, b$ is $mn-m-n$.
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = extendedeuclid(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
//Finding the number of solutions and the solutions in a given interval
// for practice problem visit cp algorithm
// there is an o(n) solution
// time complexity == nloglogn
void soe()
{
   prime[0]=0;
   prime[1]=0;

   for(int i=2;i<=sqrt(MAX-1);i++)
   {
     if(prime[i]==true)
     {
       for(int j=i*i;j<MAX;j+=i)
        prime[i]=false;
     }
   }

}
int egcd(int a,int b)
{
    if(b==0)
      return a;

    return egcd(b,a%b);
}
// mod should be priem
int inv[mod];
void mmiar()
{
      inv[1] = 1;
    for(int i = 2; i < mod; ++i)
    inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}
int mmi(int a)
{
   // if(__gcd(x,mod)!=1){
    // cout<<"not possible"; }
    // x is mmi of a
    // (a.x)%m=1   ax=my+1 ... find x by extended euclid
    // b is mod
    int x,y;
  extendedeuclid(a,mod,x,y);
  return (x%mod+mod)%mod; // id x is negative


  
}
int power(int x,int p)
{
   if(p==0)
    return 1;

   int r=power(x,p/2)%mod;

   r=(r%mod *r%mod)%mod;

   if(p&1)
    r=(r%mod * x%mod)%mod;

    return r; 
}
inline int madd(int x,int y)
{
   return (x%mod +y%mod)%mod;
}
inline int msub(int x,int y)
{
   return (mod+x%mod -y%mod)%mod;
}
inline int mmul(int x,int y)
{
   return (x%mod *y%mod)%mod;
}
inline int mdiv(int x,int y)
{
   return (x%mod * power(y,mod-2)%mod)%mod;  // when mod is prime
   // return (x%mod * mmi(y)%mod)%mod;
}
// no of divisor == multiplication of addition 1 with power of priem factorisation
void primefact(int x)
{

       while(x%2==0)
       {
          // cout<<"2 ";
          x=x/2;
       }

       for(int i=3;i<=sqrt(x);i+=2)
       {
            while(x%i==0)
            {
               cout<<"i ";
               x=x/i;
            }
       }

       if(x>2)
        cout<<x<<" ";

}
// count coprime <n of n is totient function
// product of n*(1-1/p1)..... p1,p2.. are the prime factorization of n?
//  for proof visit cp algorithm
// int phi(int x)
// {
       // let 9 is no now for x  totient no pf are 3 only therfore phi==9*(1-1/3)==6

// }
int phi[MAX];
// calculate array of phi (1,,MAX)
// Computes and prints totien of all numbers 
// smaller than or equal to n. 
void computeTotient(int n) 
{ 
    // Create and initialize an array to store 
    // phi or totient values 
    long long phi[n+1]; 
    for (int i=1; i<=n; i++) 
        phi[i] = i; // indicates not evaluated yet 
                    // and initializes for product 
                    // formula. 
  
    // Compute other Phi values 
    for (int p=2; p<=n; p++) 
    { 
        // If phi[p] is not computed already, 
        // then number p is prime 
        if (phi[p] == p) 
        { 
            // Phi of a prime number p is 
            // always equal to p-1. 
            phi[p] = p-1; 
  
            // Update phi values of all 
            // multiples of p 
            for (int i = 2*p; i<=n; i += p) 
            { 
               // Add contribution of p to its 
               // multiple i by multiplying with 
               // (1 - 1/p) 
               phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    } 
  
    // Print precomputed phi values 
    for (int i=1; i<=n; i++) 
      cout << "Totient of " << i << " is "
           << phi[i] << endl; 
} 
// cal phi(n)
int phii(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int main()
{
      //   for(int i=0;i<MAX;i++)
         //  prime[i]=true;
         // int x,y;
  extendedeuclid(4,7,x,y);
  cout<<x<<endl<<y<<endl;
}
