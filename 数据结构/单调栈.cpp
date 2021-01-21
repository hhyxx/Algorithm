
while(n--)
{
    int x;
    cin>>x;
    while(tt&&x<=stk[tt])
        tt--;
    if(tt) cout<<stk[tt]<<' ';
    else cout<<"-1"<<' ';
    stk[++tt]=x;
}