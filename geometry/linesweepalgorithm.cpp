// line sweep algorithm

/*Vivek likes playing with lasers, but his friend Divyansh says that reading biographies is much more interesting. In order to prove that lasers are fun too, Vivek proposed an interesting task involving them:

You are given N points in a plane (numbered 1 through N); for each valid i, the i-th point is Pi=(i,Ai). There are N−1 line segments between them (numbered 1 through N−1); for each valid i, the i-th line segment is formed by connecting the points Pi and Pi+1.

You should answer Q queries. In each query, a laser beam is fired horizontally to the right, from a point (x1,y) to a point (x2,y) (where it stops and does not propagate further). Find the number of line segments it collides with on the way.

The beam is considered to collide with a line segment if it intersects or touches this segment, except when the left endpoint of this segment is (x2,y) or its right endpoint is (x1,y).

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The second line contains N space-separated integers A1,A2,…,AN.
Each of the next Q lines contains three space-separated integers x1, x2 and y describing a query.
Output
For each query, print a single line containing one integer ― the number of line segments the beam collides with.

Constraints
1≤T≤5
2≤N≤100,000
1≤Q≤100,000
1≤Ai≤109 for each valid i
1≤x1<x2≤N
1≤y≤109
Subtasks
Subtask #1 (30 points): N,Q≤2,000
Subtask #2 (70 points): original constraints

Example Input
1
4 3
1 3 5 1
2 4 4
1 2 3
1 4 1
Example Output
2
1
2
Explanation
Example case 1:

For the first query, the beam collides with the 2-nd line segment and the 3-rd line segment.
For the second query, the beam collides only with the 1-st line segment. We do not consider it to collide with the second line segment, since its left endpoint is (x2,y).
For the third query, the beam collides with the 1-st line segment and the 3-rd line segment*/
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
const int MAX =1e5+10;
// sweeping in bottom to up
// basic of this question is intersection of horizontal and verticle lines by line sweep
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
// making an event
struct events
{
       int y,t,ix;
       bool operator<(const events &p){
       return make_pair(y,t) < make_pair(p.y,p.t);}  ///   suppose when min max and query are in one line like A......B Q....Q here no intersection
};

int a[MAX],BIT[MAX],ans[MAX]; 
int ql[MAX],qr[MAX],qy[MAX];
int n,q;
void update(int i,int val){
     // i++;
     while(i<=n){
          BIT[i]+=val;
          i+=i&(-i);}
}
int get(int i)
{
      int res=0;
      // ++i;
      while(i){
          res+=BIT[i];
          i-=i&(-i);
      }
      return res;
}
void solve(){
           cin>>n>>q;
          // indexing one
           vector<events> event;
          for(int i=1;i<=n;i++) cin>>a[i];
          for(int i=1;i<=q;i++) cin>>ql[i]>>qr[i]>>qy[i]; //ql[i]--; qr[i]--;} 
          for(int i=1;i+1<=n;i++){
               event.push_back({min(a[i],a[i+1]),1,i});
               event.push_back({max(a[i],a[i+1]),3,i});
          } 
          for(int i=1;i<=q;i++)
               event.pb({qy[i],2,i});
         
          sort(all(event));
          for(int i=0;i<event.size();i++)
          {
               auto x=event[i];
              
               // adding segment
               if(x.t==1){
                   update(x.ix+1,1);
               }
               // remove segment
               else if(x.t==3)
               {  
                    update(x.ix+1,-1);
                     
               }
               // query
               else
               {
                     ans[x.ix]=get(qr[x.ix])-get(ql[x.ix]);

               }    
          }
          for(int i=1;i<=q;i++)
               cout<<ans[i]<<endl;
  
}
i32 main(){pls();  
     int t; cin>>t; while(t--){ solve();}
return 0;}
     
