



for(int i=1;i<=n;i++)
{
    if(hh<=tt && i-k+1>que[hh]) hh++;
    while(hh<=tt && a[que[tt]]>=a[i]) tt--;
    que[++tt]=i;
    if(i-k+1>0)
        cout<<a[que[hh]]<<' ';
}