// 自适应 Simpson
double simpson(double l, double r) {// 根据Simpson公式计算二次函数积分值
  double mid = (l + r) / 2;
  return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;  // 辛普森公式
}

double asr(double l, double r, double eqs, double ans) {
  double mid = (l + r) / 2;
  double fl = simpson(l, mid), fr = simpson(mid, r);
  if (abs(fl + fr - ans) <= 15 * eqs)
    return fl + fr + (fl + fr - ans) / 15;  // 足够相似的话就直接返回
  return asr(l, mid, eqs / 2, fl) +
         asr(mid, r, eqs / 2, fr);  // 否则分割成两段递归求解
}

