#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
 
int main() {
	int nn=1000000000;
	int mx=sqrt(nn);
    vector<int> primes;
    vector<int> p(mx+1,1);
//    primes.push_back(2);
    p[0]=0;
    p[1]=0;
 
    for(int i=2;i<=sqrt(mx);i++)
    {
    	  if(p[i])
    	  {
    	  	 for(int j=2*i;j<=mx;j+=i)
    	  	 p[j]=0;
		  }
	}
	for(int  i=0;i<=mx;i++)
	if(p[i])primes.push_back(i);
 
    int T,N,M;
 
    cin >> T;
 
    for (int t = 0; t < T; t++) {
        if (t) cout << endl;
 
        cin >> M >> N;
        if (M < 2) M = 2;
 
        int cap = sqrt(N) + 1;
 
        set<int> notprime;
        notprime.clear();
 
        vector<int>::iterator p;
        for (p = primes.begin(); p != primes.end(); p++) {
 
            if (*p >= cap) break;
            int start;
 
            if (*p >= M) start = (*p)*2;
            else start = M + ((*p - M % *p) % *p);   // % p ==> if m%*p==0
 
            for (int j = start; j <= N; j += *p) {
                notprime.insert(j);
            }
        }
 
        for (int i = M; i <= N; i++) {
            if (notprime.count(i) == 0) {
                cout << i << endl;
            }
        }
 
    }
    return 0;
} 
