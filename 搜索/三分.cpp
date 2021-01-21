//整数三分
int l = 1,r = INF,lmid,rmid;
while(l < r) {
    lmid = l + (r - l >> 1);
    rmid = lmid + (r - lmid >> 1);  // 对右侧区间取半
    if (cal(lmid) > cal(rmid))
      r = rmid;
    else
      l = lmid;
}
// 求凸函数的极大值
cout << max(cal(l),cal(r)) << endl;

int l = 1,r = INF,lmid,rmid;
while(l < r) {
    lmid = l + (r - l >> 1);
    rmid = lmid + (r - lmid >> 1);  // 对右侧区间取半
    if (cal(lmid) < cal(rmid))
      r = rmid;
    else
      l = lmid;
}
// 求凹函数的极小值
cout << min(cal(l),cal(r)) << endl;





//浮点数三分
const double EPS = 1e-9;
while(r - l < EPS) {
    double lmid = l + (r - l) / 3;
    double rmid = r - (r - l) / 3;
    
    lans = f(lmid),rans = f(rmid);
    // 求凹函数的极小值
    if(lans <= rans) r = rmid;
    else l = lmid;
    // 求凸函数的极大值
    if(lans >= rans) l = lmid;
    else r = rmid;
}
// 输出 l 或 r 都可
cout << l << endl;