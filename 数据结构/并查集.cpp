// O（logn）
// 初始化，假定节点编号是1~n
rep(i,1,n+1)
    p[i] = i;

int p[N]; //存储每个点的祖宗节点
// 返回x的祖宗节点 路径压缩
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 合并a和b所在的两个集合：
p[find(a)] = find(b);



//——————————————————————————————————————————————
/*
维护size 的并查集
size 即集合中元素个数
p[]存储每个点的祖宗节点,
size[]只有祖宗节点的有意义，
表示祖宗节点所在集合中的点的数量
*/
int p[N], size[N];
// 初始化，假定节点编号是1~n
rep(i,1,n+1)
{
    p[i] = i;
    size[i] = 1;
}

// 返回x的祖宗节点
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
// 合并a和b所在的两个集合：
p[find(a)] = find(b);
size[b] += size[a];
//————————————————————————————————————————————————
// 扩展域并查集
//d[x]维护x到其根的距离
int find(int x)
{
    if(fa[x]==x)
        return x;
    int root=find(fa[x]);//递归计算代表
    d[x]+=d[fa[x]];//维护d数组对边权求和
    return fa[x]=root;//路径压缩
}
void merge(int a,int b)
{
    a=find(a),b=find(b);
    fa[a]=b;d[a]=sz[b];sz[b]+=sz[a];
}