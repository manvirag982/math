#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
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
// solution by line sweep algorithm
// sort all points by x
// set sort by y
const int MAX =5e4+10;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
#define pt pair<pi,int>
#define y f.f       // NOTE
#define x f.s     // NOTE
#define ix s
int n;
vector< pt > pnts(MAX);
double ix1,ix2;
int compare(pt a, pt b)
{       

        return a.x<b.x; 
}
double closest_pair()
{
        sort(all(pnts),compare);
        double best=1e20;
        set<pt> box;
        box.insert(pnts[0]);
        int left = 0;
        for (int i=1;i<n;++i)
        {  
             // removing all point whose x distance is large than dis
            while (left<i && pnts[i].x-pnts[left].x > best)       
                box.erase(pnts[left++]);
             
             // checking remaining points
            // fartest point x-dis,y-dis
           
            for(auto it=box.lower_bound(mk(mk(pnts[i].y-best,pnts[i].x-best),pnts[0].s));it!=box.end() && pnts[i].y+best>=it->y;it++)  // since set is according to y coordinate so if any element is greater than x+best the all remain element will also be greatest
                {   
                    double ress=sqrt(pow(pnts[i].x - it->x, 2.0)+pow(pnts[i].y - it->y, 2.0));
                    
                    if(ress<best)
                    {
                          best=ress;
                          ix1=it->ix;
                          ix2=pnts[i].ix;
                    }
                }
            box.insert(pnts[i]);
        }
        return best;
}
i32 main(){pls();  
    cin>>n;
    pnts.resize(n);
    for(int i=0;i<n;i++) {cin>>pnts[i].x>>pnts[i].y; pnts[i].ix=i;}
    double dis=closest_pair();
    if(ix1>ix2)
    swap(ix1,ix2);
    cout<<ix1<<" "; cout<<ix2<<" ";
    cout<<fixed<<setprecision(6)<<dis<<endl; 
return 0;}



