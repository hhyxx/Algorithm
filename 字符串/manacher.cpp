// O(n) 
// p[i]/2 以i为中心的回文子串个数
// p[i]-1 以i为中心的回文串的长度
char a[N],s[N*2];
int n,mxr,mid,cnt;
int p[N*2];
inline void change() {
    s[cnt] = '~', s[++cnt] = '#';
    for(int i=0;i<n;i++)
    s[++cnt]=a[i],s[++cnt]='#';
    s[++cnt]='@';
}
inline void manacher(){
    for(int i=1;i<=cnt;i++){
        if(i<mxr) p[i]=min(p[2*mid -i],mxr-i);
        else p[i]=1;
        while(s[i+p[i]] == s[i-p[i]])  ++p[i];
        if(mxr < i+p[i]) mxr=i+p[i],mid=i;
    }
}