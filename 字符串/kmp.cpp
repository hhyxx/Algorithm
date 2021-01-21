//求Next数组：
//ne[1]=0，方便判断
// s[]是模式串，p[]是模板串, n是s的长度，m是p的长度
int j=0;
rep(i,2,n+1)
{
    while(j && p[i]!=p[j+1]) j=ne[j];
    if(p[i]==p[j+1]) j++;
    ne[i]=j;
}
// i-ne[i]即前i个的最小循环节长度，len | i说明是由循环节循环构成的完美串

// 匹配
j=0;
rep(i,1,m+1)
{
    while(j && s[i]!=p[j+1]) j=ne[j];
    if(s[i]==p[j+1]) j++;
    if(j==n) cout<<i-n<<' ',j=ne[j];
}


