int cnt=0;
int a[N];
rep(i,0,n){
    int x;
    scanf("%d",&x);
    a[++cnt]=x;
}

sort(a+1,a+1+cnt);
unique(a+1,a+1+cnt);