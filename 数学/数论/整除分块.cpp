    for(l = 1;l<=n;l=r+1)
    {
        if(k/l == 0) break;//0对答案无贡献
        r=min(k/(k/l),n);
        ans-=(ll) (k/l) *(l+r)  *(r-l+1)/2;//等差数列
    }


