//spoj BSHEEP - Build the Fence

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end() 
#define i32 int32_t
#define i16 int16_t
#define endl "\n"
#define fastio   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x f.f 
#define y f.s 
#define ix s 
const int MAX =1000010;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int n;
int cp(pair< pi,int > O,pair< pi,int > A,pair< pi,int > B)
{
           return ((A.x-O.x)*(B.y-O.y) - (A.y-O.y)*(B.x-O.x));
}
vector<int> convex_hull(vector< pair<pi,int> > p)
{         
        vector<int> res(n*2);
          int k=0;
         for(int i=0;i<n;i++)
         {      
                // lower hull from left most
                if(k) 
                if(p[i].x==p[res[k-1]].x && p[i].y==p[res[k-1]].y )
                  continue;
                while(k>=2 && cp(p[res[k-2]],p[res[k-1]],p[i])<=0)
                  k--;
                  res[k++]=i;

                  // for(int i=0;i<k;i++)
                    // cout<<p[res[i]].ix<<" ";
                  // cout<<endl;
                
          }
                // upper hull from right most
          int t=k+1;
          // cout<<endl;
          for(int i=n-2;i>=0;i--){
                 
                  if(k) 
                if(p[i].x==p[res[k-1]].x && p[i].y==p[res[k-1]].y )
                  continue;
                while(k>=t && cp(p[res[k-2]],p[res[k-1]],p[i])<=0)
                 k--;
                 res[k++]=i; 
          
             // for(int i=0;i<k;i++)
                    // cout<<p[res[i]].ix<<" ";
                  // cout<<endl;
                
          }
          res.resize(k-1);
          return res;
         
}
i32 main(){pls();
  
   int t; cin>>t;
    while(t--){

      // int n;
      
      vector<int>res;
      // p.clear();
      // res.clear();
      // p.re
    cin>>n;
    vector< pair<pi,int> > p(n);
     for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y,p[i].ix=i;
     if(n==0){
      cout<<"0.00"<<endl;
      cout<<"0"<<endl<<endl;
      continue;
     }
     else if(n==1){
        cout<<"0.00"<<endl;
        cout<<"1"<<endl<<endl;
        continue;
     }

    sort(all(p)); 
    // for(auto i: p)
       // cout<<i.x<<" "<<i.y<<" "<<i.ix<<endl;
    res=convex_hull(p);
    double ans=0;

    for(int i=0;i+1<res.size();i++)
    {
          ans+=sqrt(pow((p[res[i]].x-p[res[i+1]].x),2.0)+pow((p[res[i]].y-p[res[i+1]].y),2.0));
    } 
    int i=res.size()-1;
    ans+=sqrt(pow((p[res[i]].x-p[0].x),2.0)+pow((p[res[i]].y-p[0].y),2.0));

    cout<<fixed<<setprecision(2)<<ans<<endl;
    int mny=0;
    int mn=INT64_MAX;
    for(int i=0;i<res.size();i++)
    {   if(p[res[i]].y<mn)
       {
           mn=p[res[i]].y;
           mny=i;
       }
         
    }
    rotate(res.begin(),res.begin()+mny,res.end());
    for(int i=0;i<res.size();i++)
    cout<<(p[res[i]].ix)+1<<" ";
    cout<<endl<<endl;   
  }
return 0;}
     
