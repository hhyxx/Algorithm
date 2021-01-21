/*
 给定整数a，b，p，其中a，p 互质，求出一个正整数x，使得 a^x ≡ b (mod p)
*/
// p是不是素数都可以，求出0 <= x < p的解
#define mod 76543
#define ll long long
int h[mod],head[mod],ne[mod],id[mod],top;
void insert(int x,int y){
    int k=x%mod;
    h[top]=x,id[top]=y,ne[top]=head[k],head[k]=top++;
}  
int find(int x){
    int k=x%mod;
    for(int i=head[k];i!=-1;i=ne[i])
        if(h[i]==x)
        return id[i];
        return -1;
}
int bsgs(int a,int b,int p){
    memset(head,-1,sizeof head);
    top=1;
    if(b==1) return 0;
    ll x=1,p=1;
    for(int i=0;i<m;i++,p=p*a%n) insert(p*b%n,i);
    for(ll i=m;;i+=m){
        if((j=find(x=x*p%n))!=-1) return i-j;
        if(i>n) break;
    } 
    return -1;
}



