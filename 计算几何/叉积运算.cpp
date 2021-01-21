#define db double
typedef struct {db x,y;} Point;

// 实现了point1 叉乘 point2
db det(db x1,db y1,db x2,db y2){
    return x1*y2-x2*y1;
}


db cross(Point a,Point b,Point c){
    return det(b.x-a.x , b.y-a.y , c.x - a.x , c.y - a.y);
}