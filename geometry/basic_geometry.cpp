#include<bits/stdc++.h>
using namespace std;
// 2d point
class point2d
{ 
    // i will do some operator overloading
     public:
     int x,y;
     
     point2d(int x,int y){
         this->x=x;
         this->y=y;
     }

};
// 3d point
class point3d
{ 
    // i will do some operator overloading
     public:
     int x,y,z;
     point3d(int x,int y,int z){
         this->x=x;this->y=y;this->z=z;
     }
};
// dot product
int dot2d(point2d a,point2d b){
    return a.x*b.x + a.y*b.y;}
int dot3d(point3d a,point3d b){
    return a.x*b.x + a.y*b.y + a.z*b.z ;}
// properties in 2d
int  norm(point2d a) {
    return dot2d(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot2d(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot2d(a, b) / abs(a) / abs(b));
}
// cross product
point3d cross3d(point3d a, point3d b) {      // b*c 3d
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
double triple(point3d a, point3d b, point3d c) {       // a.(b*c)
    return dot3d(a, cross3d(b, c));
}
double cross2d(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;  // a*b == normal k whose magnitude is---
}
// some line and plane intersection  after reading math vector
int main()
{ 


}