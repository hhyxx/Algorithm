for(int i=1;i<=n;i++)
    cin>>h[i];
size=n;
for(int i=n/2;i;i--)
    down(i);
//建堆，根据完全二叉树的性质，n/2后的都是叶子结点，只需要把所有的根结点从后往前down一遍就完成了堆的建立


//小根堆
int h[N];
int idx[N];//存的是第k个插入的点在堆中的位置，即下标
int no[N];//存的是下标为k的点是第几个插入的
int size,no_;//size为下标，no为第几个插入的编号
inline void heap_swap(int a,int b)
{
    swap(idx[no[a]],idx[no[b]]);
    swap(no[a],no[b]);
    swap(h[a],h[b]);
}
inline void up(int u)
{
    while(u/2 && h[u]<h[u/2])
    {
        heap_swap(u,u/2);
        u>>=1;
    }
}
inline void down(int u)
{
    int t=u;
    if(u*2<=size && h[u*2]<h[t])
        t=u*2;
    if(u*2+1<=size && h[u*2+1]<h[t])
        t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}
inline void insert()
{
    int x;
    cin>>x;
    no_++;
    h[++size]=x;
    idx[no_]=size;
    no[size]=no_;
    up(size);
}
inline void poptop()
{
    heap_swap(1,size);
    size--;
    down(1);
}
inline void remove(int p)
{
    heap_swap(p,size--);
    up(p),down(p);
}