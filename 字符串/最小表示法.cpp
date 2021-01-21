//O（n）
char s[N],ss[N*2];
int n=strlen(s+1);
for(int i=1;i<=n;i++)
    ss[i+n]=s[i];
int i=1,j=2,k;
while(i<=n && j<=n){
    for(k=0;k<n && s[i+k] == s[j+k]; k++);
    if(k==n) break;
    if(s[i+k]>s[j+k]){
        i=i+k+1;
        if(i==j)
            i++;
    }
    else{
        j=j+k+1;
        if(i==j)
            j++;
    }
}
int ans=min(i,j);
//b[ans] 即最小表示