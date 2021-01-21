Trick​
----
## 快读快输

```cpp
int getint()
{
    register int num=0;
    register char ch;
    do ch=getchar(); while (ch<'0' || ch>'9'); “
    do num=num*10+ch-'0', ch=getchar(); while (ch>='0' && ch<='9');
    return num;
}
void putint(bool num)
{
    if (num==0) printf("TAK\n");
    else printf("NIE\n");
}
```
----
# 1. 语言
## 1.1. java​
### 1.1.1. 输入输出

```java
import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;
public class Main
{
	static Scanner sc;
	public static void main(String[] args)
        {
		sc=new Scanner(System.in);
	}
	String s=sc.nextline(); //读一行字符串
	int n=sc.nextInt(); //读整数
	double d=sc.nextDouble(); //读实数
	sc.hasNext() //是否读完
}
```
----

### 1.1.2. 数组

```java
	int[] arr=new int[100]; //数组
	int[] arr=new int[]{1,2,3}; //有初始值、不指定长度的声明
	int[] arr={1,2,3}; //有初始值、不指定长度的声明
	arr.length //获取数组长度
	int[][] arr=new int[10][10]; //二维数组
	Array.sort(arr,l,r); //对arr[l..(r-1)]排序（import java.util.Arrays;）    
```

----
### 1.1.3. 类的比较函数

```java
public void sort_in_values(a,1,n+1,new Comparator<Node>()
    {
	public int compare(Node a,Node b)
            {
		return a.x>b.x
	}
});
```

----
### 1.1.4. BigInteger​


```java
import java.math.BigInteger;
BigInteger n=new BigInteger("123456");
BigInteger[] arr=new BigInteger[10];  //BigInteger数组
n.intValue() //转换为int
n.longValue() //转换
n.doubleValue() //转换
n.add(m) //加法
n.subtract(m) //减法
n.multiply(m) //乘法
n.divide(m) //除法
n.mod(m) //取模
BigInteger.valueOf(I) //int转换为BigInteger
n.compareTo(m) //n>m返回1，n<m返回-1，n==m返回0
n.abs()
n.pow(I)
n.toString(P) //返回P进制字符串
```

----
### 1.1.5. BigDecimal​
小数位取位规则：

+ $ROUND\_CEILING$：向正无穷方向舍入

+ $ROUND\_DOWN$：向零方向舍入

+ $ROUND\_FLOOR$：向负无穷方向舍入

+ $ROUND\_HALF_DOWN$：向最近的一边舍入, 如果相等，向下舍入

+ $ROUND\_HALF_UP$：向最近的一边舍入, 如果相等，向上舍入

+ $ROUND\_HALF_EVEN$：向最近的一边舍入，如果相等

    + 保留位数是奇数，使用$ROUND\_HALF\_UP$，如果是偶数，使用$ROUND\_HALF\_DOWN$

+ $ROUND\_UP$：向远离$0$的方向舍入

```java
import java.math.BigDecimal;
n=new BigDecimal("123456");
n.divide(m,2,BigDecimal.ROUND_HALF_UP)  //n/m , 保留两位（四舍五入）
```

----

## 1.2. c++ stl​
### 1.2.1. vector​

+ 动态分配内存，即变长数组

+ 迭代器

    + $begin()/rbegin()$：正向/逆向的首元素

    + $end()/rend()$ ：正向/逆向的尾元素，容器末端/首部占位符的迭代器，无元素

+ 序列操作

    + $resize()$：改变 $vector$ 的长度，多退少补。补充元素可以由参数指定

    + $reserve()$：使得 $vector$ 预留一定的内存空间，避免不必要的内存拷贝
----

### 1.2.2. deque​

+ 支持下标访问

+ 元素访问

    + $clear()$：清除所有元素

    + $at()$：返回容器中指定位置元素的引用，执行越界检查， 常数复杂度 。

    + $operator[]$：返回容器中指定位置元素的引用。不执行越界检查， 常数复杂度 。

    + $front()$：返回首元素的引用。

    + $back()$：返回末尾元素的引用。
----

### 1.2.3. set​

+ 无重复值，内部有序，查询、移除和插入复杂度$O(logn)$。

+ 插入与删除

    + $insert(x)$ ：当容器中没有等价元素的时候，将元素 $x$ 插入到 $set$ 中。

    + $erase(x)$ ：删除值为 $x$ 的元素，返回删除元素的个数。

    + $erase(pos)$ ：删除迭代器为 $pos $的元素，要求迭代器必须合法。

    + $erase(first,last)$： 删除迭代器在  范围内的所有元素。

    + $clear()$ ：清空 $set$ 。

+ 元素访问 

    + $begin() /rbegin()$ ：返回指向首元素的迭代器

    + $end()/rend()$： 返回指向数组尾端/首端占位符的迭代器，注意是没有元素的。

+ 查询

    + $count(x)$ ：返回 $set$ 内键为 $x$ 的元素数量。

    + $find(x)$：在 $set$ 内存在键为 $x$ 的元素时会返回该元素的迭代器，否则返回 $end()$ 。

    + $lower\_bound(x)$ ：返回指向首个不小于给定键的元素的迭代器。如果不存在这样的元素，返回 $end()$。

    + $upper\_bound(x)$ ：返回指向首个大于给定键的元素的迭代器。如果不存在这样的元素，返回 $end()$ 。

    + $empty()$ ：返回容器是否为空。

    + $size()$ ：返回容器内元素个数。
----

### 1.2.4. multiset​

+ 允许存在重复值，内部有序，查询、移除和插入复杂度$O(logn)$。

+ 操作与$set$相同
----
### 1.2.5. map​

+ 有序键值对容器，键是唯一的。查询、移除和插入复杂度$O(logn)$

+ $iterator \; find( const \; \;Key\; \& \; key\; )$; 来确定一个索引是否在 $map$ 中。返回指向该元素的迭代器；若索引不在 $map$ 中，返回尾后迭代器 $mp.end()$ 。

+ 遍历$map$方式：迭代器

```cpp
for (iter = mp.begin(); iter != mp.end(); ++iter)
  cout << iter->first << " " << iter->second << endl;

//c++11 以上使用auto
for (auto &i : mp) {
  printf("Key : %d, Value : %d\n", i.first, i.second);
}
```

+ 删除元素，利用 $find$ 函数找到 $Tom$ ，然后再 $erase $

```cpp
map<string, int>::iterator it;
it = mp.find("Tom");
mp.erase(it)
```
+ 查询

    + $count$ ：返回匹配特定键的元素出现的次数，例如 $mp.count("Tom")$ 。

    + $swap$ ：可以交换两个 $map$ ，例如 $swap(m1,m2)$ 。

    + $size$ ：返回 $map$ 中元素的个数。

    + $empty$ ：如果 $map$ 为空则返回 $true$
----

 ### 1.2.6. multimap​
+ 有序键值对容器，允许元素拥有相同的键值。查询、移除和插入复杂度$O(logn)$

+ 与 $map$ 相同
---
### 1.2.7. priority\_queue​

+ 默认下是大根堆
```cpp
priority_queue<int,vector<int>,greater<int> > q_small;//小根堆
```
+ 节点为结构体时必须给定比较方式

+ 运算符重载
```cpp
struct node{
    int x,y;
    bool operator< (const node &a)const {
        return x < a.x ; // 堆中随node的x属性为大根堆
        return x > a.x ; // 堆中随node的x属性为小根堆
    }
    //  可以比较nodeA == nodeB
    bool operator == (const node &a)const{
        return x == a.x && y == a.y;
    }
    //  可以比较nodeA = nodeB
    bool operator != (const node &a)const{
        return x != a.x || y != a.y;
    }
    //  可以用nodeA + nodeB生成一个新的node
    node operator + (const node &a)const {
        return node(x + a.x,y+a.y);
    }
};
```
---

### 1.2.8. bitset​

+ 可以用于压位，$bitset$ 存储二进制数位，一个元素一般只占$1\; bit$ ，优于$bool$的$8\; byte$

+ $bitset$中的每个元素都能单独被访问，例如对于一个叫做$f$的$bitset$，表达式$f[3]$访问了它的第$4$个元素，就像数组一样。

+ $bitset$特性：整数类型和布尔数组都能转化成$bitset$。

+ $bitset$位数在编译时就需要确定。不确定长度的$bitset$，用$vector<bool>$

+ $bitset<10000> s$;   $<>$内为数组大小

+ 构造

    + $bitset()$ : 每一位都是 $false$ 。

    + $bitset(unsigned\; long\; val)$ : 设为 $val$ 的二进制形式

    + $bitset(const\; string\; \& \;str)$ : 设为$01$串 $str$ 

+ $bitset$运算

    + $[]$ : 访问其特定的一位。

    + $==、!=$ : 比较两个 bitset 内容是否完全一样。

    + $\&$ 、$\&$$=$、$|$、$|$$=$、$\wedge$、$\wedge$$=$、$\sim$: 进行按位与/或/异或/取反操作。 $bitset$ 只能与 $bitset$ 进行位运算 ，若要和整型进行位运算，要先将整型转换为 $bitset$ 。

    + $<<、>>、<<=、>>=$ : 进行二进制左移/右移。

+ 函数方法

    + $bs.size()$ ：返回大小（位数）

    + $bs.count()$ ：返回$1$的个数

    + $bs.any()$ ：返回是否有$1$

    + $bs.none()$ ：返回是否没有$1$

    + $bs.set()$ ：全都变成$1$

    + $bs.set(p)$ ：将第$p + 1$位变成$1$

    + $bs.set(p, x)$ ：将第$p + 1$位变成$x$

    + $bs.reset()$ ：全都变成$0$

    + $bs.reset(p)$ ：将第$p + 1$位变成$0$

    + $bs.flip()$ ：全都取反

    + $bs.flip(p)$ ：将第$p + 1$位取反

    + $bs.to\_ulong()$ ：返回它转换为$unsigned\; long$的结果，如果超出范围则报错

    + $bs.to\_ullong()$ ：返回它转换为$unsigned\; long\; long$的结果，如果超出范围则报错

    + $bs.to\_string()$ ：返回它转换为$string$的结果

----

### 1.2.9. string​

+ 转$char$数组 
```cpp
string s="hyx"
char s_[10];
s_=s.c_str;
```
+ 获取字符串的长度

    + $s.size()$

    + $s.length()$

+ 寻找某字符串第一次出现的位置

    + $s.find(c)$

    + $s.find(c,pos)$ 从$pos$往后找$c$出现的下标

+ 截取子串

    + $substr(pos,len)$从$pos$开始截取长度为$len$的子串，长度不够为后缀

----

### 1.2.10. BinarySearch​

+ $lower\_bound(起始地址，结束地址，要查找的数值)$： 返回的是数值 第一个 大于等于当前数值出现的位置。

+ $upper\_bound(起始地址，结束地址，要查找的数值)$：返回的是数值 第一个大于出现的位置。

+ $binary\_search(起始地址，结束地址，要查找的数值)$：返回的是是否存在这么一个数，是一个$bool$值。

----

# 2. Basic ​
## 2.1. 龟速乘

+ 时间复杂度：$O(log k)$

+ 将其中一个乘数拆分成二进制后分别相乘再相加，取模时防止溢出

```cpp
ll qmul(ll a, ll k, ll p){
    ll res=0;
    while(k){
        if(k&1) res=(res+a)%p;
        a=(a+a)%p;
        k>>=1;
    }
    return res;
}
```

----

## 2.2. 快速幂

+ 时间复杂度：$O(log k)$

+ 将指数拆分成二进制后，底数相同相乘即指数相加

```cpp
ll qmi(ll a,ll k, ll p)
{
    ll ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ans;
}
```

----

## 2.3. 离散化

+ 将值域远大于数量的映射到一个较小的区间

```cpp
int cnt=0;
int a[N];
rep(i,0,n)
{
    int x;
    scanf("%d",&x);
    a[++cnt]=x;
}

sort(a+1,a+1+cnt);
unique(a+1,a+1+cnt);
```
----

## 2.4. 二维前缀和公式

+ $s[i][j]$表示第$i$行，$j$列元素的前缀和

+ $s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j]$

+ $sum_{x_{1}\sim x_{2},y_{1}\sim y_{2}} = s[x_{2}][y_{2}] - s[x_{2}][y_{1}-1] - s[x_{1}-1][y_{2}] + s[x_{1}-1][y_{1}-1]$

----

## 2.5. 二维差分

+ 将$（x_{1}，y_{1}）\sim（x_{2}，y_{2}）$的元素全部加上$c$

    + $b[x_{1}][y_{1}] += c$

    + $b[x_{2}+1][y_{1}] -= c$

    + $b[x_{1}][y_{2}+1] -= c$

    + $b[x_{2}+1][y_{2}+1] += c$

----

## 2.6. 归并排序求逆序对

+ 归并排序不断递归至只有一个元素进行合并

+ 合并的时候不断比较两边的小的放前面大的放后面

+ 归并时出现左边的比右边大的时候，因为两边有序，左边后面的也一定比右边当前大，累计
```cpp
ll res=0;
void merge_sort(int a[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    int k=1,i=l,j=mid+1;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j]) tmp[k++]=a[i++]; //等于的时候不能计算
        else
        {
            tmp[k++] = a[j++];
            res+=mid-i+1; //当前左右有序，左边比右边当前大的数量
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i=l,j=1;i<=r;i++,j++)
        a[i]=tmp[j];   
}
```

----

# 3. 动态规划
## 3.1. LCS​

+ $dp[i][j]$表示$A（1\sim i）$和$B（1\sim j）$的最长公共子序列

+ 状态转移： $dp[i][j] = max(dp[i-1][j] , dp[i][j-1])$

    + 如果$A[i]=B[j]$,$dp[i][j] = max(dp[i][j] , dp[i-1][j-1]+1)$

+ 时间复杂度：$O(NM)$
```cpp
rep(i,1,n+1) rep(j,1,m+1)
{
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
}
cout<<dp[n][m]<<endl;
```
----

## 3.2. LIS​
### 3.2.1. $N^{2}$做法

+ 需要保证子序列下标和值都是上升的

+ $dp[i]$表示前$i$个数中的最长上升子序列，初始化$dp[1\sim n]=1$

+ 转移方程为当前的，如果当前的第$a[i] > a[j]$，$dp[i] = max(dp[i] , dp[j]+1)$

+ 时间复杂度：$O(N^{2})$

```cpp
rep(i,1,n+1)
{
    dp[i]=1;
    rep(j,1,i) if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
}
```
### 3.2.2. $NlogN$做法

+ 设置哨兵使得第一个元素可以被取到

+ 二分使用向右靠近的模板

+ $dp$中存的上升子序列的最后一个元素的值一定随长度单调上升

+ 时间复杂度：$O(NlogN)$
```cpp
int len=0;
dp[0] =- 2e9; // 设置哨兵         
rep(i,1,n+1)
{
    int l=0,r=len;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(dp[mid]<a[i]) l=mid;// 二分的时候+1避免此处死循环 
        else r=mid-1;
    }
    len=max(len,r+1);
    dp[r+1]=a[i];
}
```
----

## 3.3. 数字三角形

+ $dp[i][j]$表示在位置$(i,j)$上的最大值

+ 每个位置$(i,j)$只能由左上$(i-1,j-1)$，$(i-1,j)$右上转移而来

+ 时间复杂度：$O(N^{2})$

```cpp
memset(dp,-0x3f,sizeof dp);
dp[1][1]=a[1][1];
rep(i,2,n+1)
    rep(j,1,i+1)
        dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
```
----

## 3.4. 背包
### 3.4.1. $01$背包

+ $dp[i][j]$表示前$i$个物品，体积不超过$j$的最大价值和

+ 求体积恰好为$V$的最大价值，只需要在初始化时将所有的初始化为$-INF$即可

+ 初始化为$-INF$后，如果$dp[i][j-v[i]]$没有被装入过，体积不恰好为$j-v[i]$，不被计算，得到就是体积恰好为$V$的最大容量

+ 时间复杂度：$O(NV)$，空间复杂度$O(NV)$

```cpp
rep(i,1,n+1)
    rep(j,1,m+1)
    {
        dp[i][j]=dp[(i-1)][j];
        if(j>=w[i])
            dp[i][j]=max(dp[i][j],dp[(i-1)][j-w[i]]+v[i]);
    }
cout<<dp[n][m];
```
----

+ 滚动数组

```cpp
rep(i,1,n+1) rep(j,1,m+1)
{
    dp[i&1][j]=dp[(i-1)&1][j];
    if(j>=w[i]) dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-w[i]]+v[i]);
}
cout<<dp[n&1][j]<<endl;
```
----

+ 利用滚动数组的思想，将空间压缩为一维后时间复杂度不变，空间复杂度为$O(V)$

```cpp
rep(i,1,n+1)
    per(j,w[i],m+1)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
cout<<dp[m]<<endl;
```
----

### 3.4.2. 完全背包问题

+ 必须要先初始化$dp[i][j=dp[i-1][j]$，然后每次更新都是更新的$dp[i][j']$的值，因为第$i$个可以重复取

+ 需要在当前的背包容量能够放下当前物品时才能放入

+ 时间复杂度$O(NV)$，空间复杂度$O(NV)$

```cpp
rep(i,1,n+1) rep(j,1,m+1)
{
    dp[i][j]=dp[i-1][j];
    if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i]);
}
cout<<dp[n][m];
```
----

+ 直接在上一次的迭代的基础上进行迭代即可，不需要从后往前，因为可以重复选取同一个物品无限次

+ 也可以通过奇偶性的滚动数组来进行，上一个事偶数下一个是奇数，奇数同理

```cpp
rep(i,1,n+1)
    rep(j,v[i],m+1)// 因为物品i 可以无限次的选取所以，不同的容量状态的只要取其中的最大值就可以
        dp[j]=max(dp[j],dp[j-v[i]] + w[i] );
cout<<dp[m]<<endl;
```
----
### 3.4.3. 分组背包

+ 每一组只能取一个，转化成$01$背包即可

+ 压缩状态时只能相同只能倒序

+ 时间复杂度：$O(NMK)$
```cpp
rep(i,1,n+1)
{
    int s;cin>>s;
    rep(j,1,s+1) cin>>w[j]>>v[j];
    per(j,0,m+1) rep(k,1,s+1)
    {
        if(j>=w[k]) dp[j]=max(dp[j],dp[j-w[k]] + v[k]);
    }
}
```
### 3.4.4. 多重背包二进制优化

### 3.4.5. 多重背包单调队列优化

# 4. 数据结构
## 4.1. 模拟链表
### 4.1.1. 单链表

+ $head$存储链表头，$e$存储节点的值，$ne$存储节点的$next$指针，$idx$表示当前用到了哪个节点

+ 不能实现在尾部插入数据

```cpp
int head, e[N], ne[N], idx;
// 初始化
void init()
{
    head = -1;
    idx = 0;
}
// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}
// 将头结点删除，需要保证头结点存在
void remove(){
    head = ne[head];
}

// 遍历整个链表
for (int i = head; i !=-1 ; i=ne[i]) 
    cout<<e[i]<<' ';
```
----

### 4.1.2. 双链表

+ $e$表示节点的值，$l$表示节点的左指针，$r$表示节点的右指针，$idx$表示当前用到了哪个节点
```cpp
int e[N], l[N], r[N], idx;
// 初始化
void init()
{
    //0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}
// 在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}
// 删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

// 链表从左到右输出
for (int i = r[0]; i !=1 ; i=r[i]) 
    cout<<e[i]<<' ';

```
----

## 4.2. 单调栈

```cpp
while(n--)
{
    int x;
    cin>>x;
    while(tt && x <= stk[tt])
        tt--;
    if(tt) cout<<stk[tt]<<' ';
    else cout<<"-1"<<' ';
    stk[++tt]=x;
}
```
----

## 4.3. 单调队列

```cpp
for(int i=1;i<=n;i++)
{
    if(hh <= tt && i-k+1 > que[hh]) hh++;
    while(hh <= tt && a[que[tt]] >= a[i]) tt--;
    que[++tt]=i;
    if(i-k+1 > 0)
        cout<<a[que[hh]]<<' ';
}
```
----

## 4.4. 二叉堆
时间复杂度：$O(log_{2}n)$

```cpp
for(int i=1 ;i<=n; i++)
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
```
----

## 4.5. Hash​ 表
### 4.5.1. 拉链法

+ 前向星式链表

+ 当前$Hash$函数对应的有就在其后链接下去
```cpp
//拉链法
struct node
{
   int val,next;
}e[N];
int h[N],idx;
// 向哈希表中插入一个数
void insert(int x)
{
   int k = (x % P + P) % P; // 防止负数
   e[idx].val = x;
   e[idx].next = h[k];
   h[k] = idx ++ ;
}

// 在哈希表中查询某个数是否存在
bool find(int x)
{
   int k = (x % P + P) % P;
   for (int i = h[k]; i != -1; i = e[i].next)
      if (e[i].val == x)
         return true;
   return false;
}
```
----

### 4.5.2. 开放寻址法

+ 如果$x$在哈希表中，返回$x$的下标

+ 如果$x$不在哈希表中，返回$x$应该插入的位置
```cpp
int h[N];
int find(int x)
{
   int t = (x % N + N) % N;
   while (h[t] != null && h[t] != x)
   {
      t ++ ;
      if (t == N) t = 0;
   }
   return t;
}
```
----

## 4.6. 并查集

+ 时间复杂度：$ O（logn）$
###4.6.1. 朴素版
```cpp
// 初始化，假定节点编号是1~n
rep(i,1,n+1)      fa[i] = i;
int fa[N]; //存储每个点的祖宗节点
// 返回x的祖宗节点 路径压缩
int find(int x){
      if (fa[x] != x) fa[x] = find(fa[x]);
      return fa[x];
}
// 合并a和b所在的两个集合：
p[find(a)] = find(b);
```
----

### 4.6.2. 维护 size​

+ $size$ 即集合中元素个数

+ $p[]$存储每个点的祖宗节点,

+ $size[]$只有祖宗节点的有意义

+ 表示祖宗节点所在集合中的点的数量
```cpp
int p[N], size[N];
// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i ++ ){
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
```

----

### 4.6.3. 扩展域并查集

+ $d[x]$维护$x$到其根的距离

+ $find$复杂度近乎$O(1)$，常数级别

```cpp
int find(int x){
    if(fa[x]==x)
        return x;
    int root=find(fa[x]);//递归计算代表
    d[x]+=d[fa[x]];//维护d数组对边权求和
    return fa[x]=root;//路径压缩
}
void merge(int a,int b){
    a=find(a),b=find(b);
    fa[a]=b;d[a]=sz[b];sz[b]+=sz[a];
}
```
----

## 4.7. 一维树状数组

+ 时间复杂度：查询、插入都是 $O（nlogn）$
```cpp
int lowbit(int x) {
   return x & -x;
}

void add(int x, int y) {
   for (int i = x; i <= n; i += lowbit(i)) 
    c[i] += y;
}

int ask(int x) {
   int res = 0;
   for (int i = x; i; i -= lowbit(i)) 
    res += c[i];
   return res;
}
```
----

## 4.8. $ST$表

+ 时间复杂度：$O（nlogn）$预处理，$O（1）$查询最值
```cpp
inline void st_pre(){
    for(int i = 1; i <= n; i++)
        f[i][0]=a[i];
    int t=log(n)/log(2);
    for(int j = 1; j <= t; j ++)
        for(int i = 1; i <= n - (1 << j) + 1; i++)//计算所有起点为i，长度为2^j区间内部的最大值
            f[i][j] = max(f[i][j-1] , f[i + (1 << (j - 1))][j-1]);
}
inline int ST_query(int l,int r){
    int k=log(r-l+1)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
```
----

# 5. 字符串
## 5.1. 字符串哈希

+ 核心思想：将字符串看成$P$进制数，$P$的经验值是$131$或$13331$，取这两个值的冲突概率低

+ 小技巧：取模的数用$2^{64}$，这样直接用$unsigned \;long\; long$存储，溢出的结果就是取模的结果
```cpp
typedef unsigned long long ull;
ull h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64
// 初始化
p[0] = 1;
rep(i,1,n+1)
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}
// 计算子串 str[l ~ r] 的哈希值
ull get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
```

----
## 5.2. 最小表示法

+ 时间复杂度：$O（n）$
```cpp
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
```
----

## 5.3. KMP​

+ 时间复杂度：$O（n）$
+ $i-ne[i]$即前$i$个的最小循环节长度，$len | i$说明是由循环节循环构成的完美串

+ 求模板串$p$的$next$数组即前缀函数的过程

+ 初始化$ne[1]=0$，方便判断
```cpp
int j=0;
rep(i,2,n+1)
{
    while(j && p[i]!=p[j+1]) j=ne[j];
    if(p[i]==p[j+1]) j++;
    ne[i]=j;
}
```
+ 用模板串匹配的过程

```cpp
j=0;
rep(i,1,m+1)
{
    while(j && s[i]!=p[j+1]) j=ne[j];
    if(s[i]==p[j+1]) j++;
    if(j==n) cout<<i-n<<' ',j=ne[j];
}
```
----

## 5.4. Manacher​

+ 时间复杂度：O(n) 
+ $\frac{p[i]}{2}$ 以$i$为中心的回文子串个数
+ $p[i]-1$ 以$i$为中心的回文串的长度
```cpp
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
```
----

## 5.5. 字典树 Trie​

+ 时间复杂度：$O(NC)$,$N$为节点个数，$C$是字符集大小

+ 0号点既是根节点，又是空节点

+ trie[][]存储树中每个节点的子节点

+ cnt[]存储以每个节点结尾的单词数量

```cpp
int trie[N][26], cnt[N], tot=1;

// 插入一个字符串
inline void insert(char *str){
    int p = 1;
    for (int i = 0; str[i]; i ++ ){
        int ch = str[i] - 'a';
        if (!trie[p][ch]) trie[p][ch] = ++ tot;
        p = trie[p][ch];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
inline int query(char *str){
    int p = 1;
    for (int i = 0; str[i]; i ++ ){
        int ch = str[i] - 'a';
        if (!trie[p][ch]) return 0;
        p = trie[p][ch];
    }
    return cnt[p];
}
```
----

# 6. 数论
## 6.1. 质数

+ $1\sim n$质数的上界是$\frac{n}{In(n)}$
+ 反素数：$g(x)$表示$x$的约数个数，对于任意的小于$x$的$i$，$g(i)<g(x)$，$x$为反素数
+ $1\sim n$ 中约数个数最多的数值最小的就是最大的反素数
###6.1.1. 试除法判定质数
+ 时间复杂度：$O（ \sqrt{n} )$
```cpp
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
```
----

### 6.1.2. 试除法分解质因数

+ 因为从小到大枚举，小的质因数会被除尽所以剩下的就是大的质因数

    + 最后还要判断一下有没有指数为$1$的剩余

+ 时间复杂度：$O（ \sqrt{n} )$

```cpp
vector<pair<int,int>> primes_factors;
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            primes_factors.push_back{i,s};
        }
    // first 表示素数，second 表示当前的指数
    if (x > 1) primes_factors.push_back{x,1}; 
}
```
----

### 6.1.3. 线性筛

+ 每一个合数只会被最小的质因子标记

+ $i\; mod \; p_{j} = 0$的时候

    + 因为$p_{j}$是从小到大枚举的，所以一定是$i$的最小质因子

+ $i\; mod \; p_{j} != 0$时

    + 同样因为是从小到大枚举的素数，且不是$i$的因子，所以一定是$i \times p_{j}$的最小质因子

+ 每个数只会被筛一次，所以算法是线性的

+ 时间复杂度：$O（n）$
```cpp
int primes[N],cnt;
bool st[N];
void get_primes(int n)
{
    rep(i,2,n+1)
    {
        if(!st[i]) primes[++cnt]=i;
        for(int j=1;primes[j]<=n/j;j++)
        {
            st[primes[j]*i]=1;
            if(i%primes[j]==0) break;
        }
    }
}
```
----

## 6.2. 约数

+ 算术基本定理：任意一个大于$1$的正整数都能唯一分解成有限个质数的乘积

+ 即 $N = p_{1}^{c_{1}} \times p){2}^{c_{2}} \times \dots \times p_{k}^{c_{k}}$，其中$p$表示质数

+ 如果约数 $d = p_{1}^{c_{1}} \times p_{2}^{c_{2}} \times \dots \times p_{k}^{c_{k}}$

+ 约数个数： $(c_{1} + 1) \times (c_{2} + 1) \times \dots \times (c_{k} + 1)$

+ 约数之和： $(p_{1}^{0} + p_{1}^{1} + ... + p_{1}^{c_{1}}) \times  \dots \times (p_{k}^{0} + p_{k}^{1} + ... + p_{k}^{c_{k}})$

+ 一个数$n$的约数个数的上界为$2 \times \sqrt{n}$

+ $1\sim N$中每个数的约数个数的总和大约为$NlogN$

### 6.2.1. 试除法求所有约数

+ 数$x$的约数个数上限为$2\times \sqrt{x}$

+ 时间复杂度：$O（ \sqrt{n} ）$

```cpp
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            //大的那一个如果相同只加一个即可
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end()); 
    return res;
}
```
-----


###6.2.2. 求$1\sim N$中约数个数和

+ $1\sim N$ 中每个数的约数个数的总和大约为$NlogN$

+ 每个数的约数大小不超过$N$

+ 时间复杂度 $O（ NlogN ）$

```cpp
vector<int>factor[N];
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n/i; j++)
        factor[i*j].push_back(i);
```
----
## 6.3. 模线性方程

### 6.3.1 单个线性方程
+ 求解$x$满足$a \times x ≡ b (mod\; m)$

+ 线性同余方程有解当且仅当 $gcd(a,m) | b$

+ 特解：$x=\frac{x_{0}\times b}{gcd(a,m)}$

+ 通解是所有模$\frac{m}{gcd(a,m)}$与特解同余的整数

```cpp
int exgcd(int a,int b,int &x,int &y)
{
  if(!b){x=1,y=0;return a;}
  int d=exgcd(b,a%b,y,x);
  y -= (a/b)*x;
  return d;
}
```
----
### 6.3.2 模线性方程组

## 6.4. Euler​ 函数

+ 欧拉函数的定义：$1\sim N$中与$N$互质的数的个数成为欧拉函数，通常为$\phi (N)$
+ 若$N$分解质因数后为
$$
p_{1}^{c_{1}} \times p_{2}^{c_{2}}\times \dots \times p_{n}^{c_{n}}
$$

+ 求欧拉函数公式

$$
\phi(N) = N \times (1-\frac{1}{p_{1}}) \times (1-\frac{1}{p_{2}})\times \dots \times (1-\frac{1}{p_{n}})
$$




### 6.4.1. 求 x​ 的 Euler 函数
时间复杂度：$O(\sqrt{n})$
求一个数x的欧拉函数: 试除法分解质因数

```cpp
int phi(int x){
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0){
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
```
----

### 6.4.2. 线性筛求 Euler​ 函数

+ 时间复杂度：$O(N)$ 求 $1\sim N$ 中每一个数的欧拉函数
```cpp
int primes[N], cnt;        // primes[]存储所有素数
int euler[N];            // 存储每个数的欧拉函数
bool st[N];            // st[x]存储x是否被筛掉

void get_eulers(int n){
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ ){
        if (!st[i]){
            primes[cnt ++ ] = i;
            euler[i] = i - 1;//质数的欧拉函数
        }
        for (int j = 0; primes[j] <= n / i; j ++ ){
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0){
                euler[t] = euler[i] * primes[j];
                break;
            // phi(p[j] * i) = p[j] * i * (1-1/p1)*(1-1/p2)……(1-1/pn)
            // p[j]是i的质因子，因为质数从小到大枚举所以又是最小的质因数，在i的质因子中出现过，所以后面不需要多乘
            }
            euler[t] = euler[i] * (primes[j] - 1);
            // phi(p[j] * i) = p[j] * i * (1-1/p1) * (1-1/p2) …… (1-1/pn) * (1-1/pj)
            // phi(p[j] * i) = phi(i) * (p[j] - 1)
        }
    }
}
```
----

# 7. 组合计数
## 7.1. 组合数
### 7.1.1. 递推

+ 时间复杂度 ：$O(n^{2})$

+ 公式：

$$
C_{n}^{m}=C_{n-1}^{m-1}+C_{n-1}^{m}
$$



```cpp
// 递推所有组合数,C(n,m)=C(n-1,m-1)+C(n-1,m)
// O(n^2)
int c[N][N];
void init(){
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j <=i ; ++j) {
            if(!j) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}
```

----
# 8. 搜索
## 8.1. 二分
### 8.1.1. 整数二分

+ 时间复杂度：$O(log_{2}n)$

+ 在单调递增序列$a$中查找$\geq x$的数中最小的一个（即$x$或$x$的后继）

+ 找在单调序列中第一个出现的元素

```cpp
while (l < r) 
{
    int mid = (l + r) / 2;
    if (a[mid] >= x) 
        r = mid; 
    else 
        l = mid + 1;
}

```
+ 在单调递增序列$a$中查找$\leq x$的数中最大的一个（即$x$或$x$的前驱）

+ 找在单调序列中最后一个出现的元素

+ 每次取中点$+1$是为了避免 $L=0，r=1$时候$L=mid=0$无限循环

```cpp
while (l < r) 
{
    int mid = (l + r + 1) / 2;
    if (a[mid] <= x) 
        l = mid; 
    else 
        r = mid - 1;
}
```

----

### 8.1.2. 浮点数二分
时间复杂度：$O(log_{2}n)$

```
while (r-l>eps) 
{
    double mid = (l + r) / 2;
    if (calc(mid)) r = mid; 
    else l = mid;
}
```

----
## 8.2. 三分
### 8.2.1. 整数三分

+ 时间复杂度：$O(log_{3}n)$

+ 求凸函数的极大值
```cpp
    ll l=0,r=INF;
    while(l<r){
        ll lmid=(l*2+r)/3,rmid=(r*2+l+2)/3;
        if(cal(lmid)>cal(rmid)) r=rmid-1;
        else l=lmid+1;
    }
    cout<<cal(l)<<endl;
```
+ 求凹函数的极小值
```cpp
    ll l=0,r=INF;
    while(l<r){
        ll lmid=(l*2+r)/3,rmid=(r*2+l+2)/3; 
        if(cal(lmid)< cal(rmid)) r=rmid-1;
        else l=lmid+1;
    }
cout << min(cal(l),cal(r)) << endl;
```

----
### 8.2.2. 浮点数三分
时间复杂度：$O(log_{3}n)$

```cpp
const double EPS = 1e-9;
while(r - l < EPS) 
{
    double lmid = l + (r - l) / 3;
    double rmid = r - (r - l) / 3;
    
    lans = f(lmid),rans = f(rmid);
    // 求凹函数的极小值
    if(lans <= rans) r = rmid;
    else l = lmid;
    // 求凸函数的极大值
    if(lans >= rans) l = lmid;
    else r = rmid;
}
// 输出 l 或 r 都可
cout << l << endl;
```

----
# 9. 图论
## 9.0. 图存储
### 9.0.1. 结构体存边

```cpp
//结构体存边
struct Edge{
    int st,to,w;
    bool operator < (const Edge &W){
        return w<W.w;
    }
}edges[M];
```

----
### 9.0.2. 链式前向星

+ $to$表示边终点，$ne$表示当前节点下一个节点，$w$表示权重
```cpp
struct node{int to,ne,w;}e[N*2];
int h[N],id;
void add(int u,int v,int w){
    e[++id].to = v;
    e[id].w=w;
    e[id].ne=h[u];
    h[u]=id;
}
```

----
## 9.1. 最短路

+ 记录具体的最短路径维护一个$pre$数组，在更新路径长度的时候进行更新

    + $Floyd$记录$pre[i][j] = k$
+ $Bellman、Dijkstra$记录$pre[v]=u$



### 9.1.1. 单源 Dijkstra​ 朴素

+ 思想：将所有节点分成两个集合：
    + 已经确定最短路的
    + 还未确定的
+ 一开始确定最短路的集合中只有起点，然后重复下面操作

    + 在未确定最短路的集合中找到一个起点到其路径最短的

    + 通过刚加入确定最短路集合的点来对所有点进行松弛操作，直到所有点确定最短路
+ 每次都用 **距离最小的更新其他点** 一定是正确的，因为到达其他的点的距离大于当前的最小值，且不含负权边

    + 所以当前最小值点的最小距离即当前内置的点
+ 时间复杂度: $O(n^{2} +m) = O(n^{2})$
+ 适用于稠密图即$n\approx m^{2}$，不含负权边
```cpp
// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);

    dist[1]=0;
    rep(i,0,n-1) // O(n) 更新n-1次即更新每个点
    {
        int t=-1;

        // O(n) 在还未确定最短路的点中，寻找距离最小的点
        rep(j,1,n) if(!st[j] && (dist[t]>dist[j] || t==-1)) t=j;
        st[t]=1;

        // 总共有O(m) relax操作，用t更新其他点的距离
        rep(j,1,n) dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==INF) return -1;
    return dist[n];
}
```

----
### 9.1.2. 单源 Dijkstra​ 堆优化

+ 分作两个集合，利用堆加速查找最小值的过程

+ 通过当前值最小的点作为起点去更新终点，通过三角不等式进行松弛操作

+ 时间复杂度: $ O(m\cdot log n)$
	
+ 适用于稀疏图$n\approx m$，不含负权边

```cpp
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii>>heap;
    heap.push({0,1}); // first存储距离，second存储节点编号
    
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int ver=t.se,d=t.fi;
        if(st[ver]) continue;
        st[ver]=1;

        for(int i=h[ver];i;i=e[i].ne)
        {
            int to=e[i].to,w=e[i].w;
            if(dist[to] > d+w)
            {
                dist[to] = d+w;
                heap.push({dist[to],to});
            }
        }
    } 
    if(dist[n]==INF) return -1;
    else return dist[n];
}
```

----
### 9.1.3. 单源 Bellman​

+ 图的存储：结构体存边

+ 时间复杂度：$O(n \cdot m)$

+ 因为一次松弛操作会使最短路的边数$+1$，所以最短路的边数最多为$n-1$

+ 基于松弛操作

$$
\operatorname{dist}(v)=\min \left(\operatorname{dist}(v), \operatorname{dist}(u)+e d g e(u, v)\right)
$$

+ 基于三角不等式

$$
\operatorname{dist}(v) \leq \operatorname{dist}(u)+\text {edge}(u, v)
$$



+ 可以求存在负权边图的最短路以及判断是否存在负权回路

+ 第$n$次迭代仍然会松弛三角不等式，说明存在一条长度是$n$,经过$n+1$个点的最短路径，抽屉原理知至少存在两个相同的点，存在负权回路。

```cpp
bool bellman()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    rep(i,1,n-1) // n-1次
    {
    	bool update=0;
        rep(i,1,m+1) // 遍历每条边
        {
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(dist[v] > dist[u]+w)
            {
            	dist[v]=dist[u]+w;
            	update=1;
            }
        }
        // 已经不会再进行松弛操作了，所以不会存在负权回路
        // 本次没有更新，下次也不会更新
        if(!update) return 1;
    }
    if(dist[n]>INF/2) return -1; 
    else return dist[n];
}
```

----
### 9.1.4. 单源 SPFA​

+ 时间复杂度：一般为$O(kE)$，$k$是常数，最坏$O(E·V)$

+ 即队列优化的$Bellman-Ford$

    + 在进行松弛操作时，只有上一次进行了松弛操作的节点的出边才有可能进行松弛

    + 加更新过的节点编号加入队列，每次更新后入队看队列中是否存在着如果存在不需要重复加入

+ 即队列优化的$bellman-ford$，稠密图、网格图、菊花图会被卡
```cpp
int SPFA()
{
    queue<int>q;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    st[1]=1;
    q.push(1);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0; // 已经出队
        for(int i=h[t];i;i=e[i].ne)
        {
            int to=e[i].to;
            if(dist[to]>dist[t]+e[i].w)
            {
                dist[to]=dist[t]+e[i].w;
                if(!st[to]) q.push(to),st[to]=1;// 队列已存在to，不需要重复插入
            }
        }
    }
    if(dist[n]==INF) return -1;
    else return dist[n];
}
```

----
### 9.1.5. 多源 Floyd​

+ 时间复杂度：$O(n^{3})$

+ 求正权无向图的最小权值和的环

    + $Floyd$过程中求环即可，有时候需要保证经过点的个数

    + $Floyd$求传递闭包

```cpp
void init()
{
    rep(i,1,n) rep(j,1,n) 
    if(i==j) dist[i][j]=0;
    else dist[i][j]=INF;
}
void floyd()
{
    rep(k,1,n) rep(i,1,n) rep(j,1,n)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
```
----
## 9.2. 负环
### 9.2.1. SPFA​ 判负环

+ 时间复杂度：期望的复杂度为$O(k\cdot n)$，最差$O(n\cdot m)$

+ 原理：如果某条最短路径上有$n$个点（除了自己），那么加上自己之后一共有$n+1$个点，由抽屉原理一定有两个点相同，所以存在环。

+ 不需要初始化$dist$,因为有负权回路就会直接在回路打转直到点数超过$n+1$

```cpp
bool SPFA()
{
    queue<int>q;
    rep(i,1,n) {q.push(i);st[i]=1;}
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i;i=e[i].ne)
        {
            int to=e[i].to;
            if(dist[to]>dist[t]+e[i].w)
            {
                dist[to]=dist[t]+e[i].w;
                cnt[to]=cnt[t]+1;
                // 经过n条边，n+1个点
                if(cnt[to]>=n) return 1;  
                if(!st[to]) q.push(to),st[to]=1;
            }
        }
    }
    return 0;
}
```
----
## 9.3. MST​
### 9.3.1. 朴素 prim​

+ 时间复杂度：$O(V^{2})$

+ 维护每个点到$MST$的最小距离

    + 每次找到距离$MST$最近的点用当前点更新所有点到$MST$的最短距离

    + 一共找$n-1$条边即可

+ 图的存储：邻接矩阵

+ 适用于稠密图
```cpp
int prim()
{
    int res=0;
    memset(dist,0x3f,sizeof dist);
    rep(i,0,n) // 第一次找一个最小生成树根点，加n-1条边共n次
    {
        int t=-1;
        rep(j,1,n+1) if((dist[t]>dist[j] || t==-1) && !st[j])
            t=j;
        st[t]=1;
        if(i && dist[t]==INF) return INF;
        if(i) res+=dist[t];
        rep(j,1,n+1) dist[j]=min(dist[j],g[t][j]);
    }
    return res;
}
```

----
### 9.3.2. Kruskal​

+ 时间复杂度：$O(ElogE)$

+ 贪心策略，不断向最小生成树中加当前权值最小的$n-1$条边

    + 利用并查集维护当前边是否已经最小生成树中

+ 图的存储：结构体存边

+ 适用于稀疏图
```cpp
struct node
{
    int u,v,w;
    bool operator < (const node &t)
    {
        return w<t.w;
    }
}e[N*2];
int find(int u)
{
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
void merge(int a,int b)
{
    int pa=find(a),pb=find(b);
    fa[pa]=pb;
}
int Kruskal()
{
    sort(e+1,e+1+m);
    int res=0,cnt=0;
    rep(i,1,n+1) fa[i]=i;
    rep(i,1,m+1)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int pa=find(u),pb=find(v);
        if(pa!=pb)
        {
            merge(pa,pb);
            cnt++;
            res+=w;
        }
        if(cnt==n-1) break;
    }
    if(cnt<n-1) return INF;
    else return res;
}
```
----
## 9.4. 二分图
### 9.4.1. 染色法判断

+ 时间复杂度：$O(V+E)$

+ 图的存储：链式前向星
```cpp
int n,m;
int h[N],e[M],ne[M],idx;
int color[N];
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
bool dfs(int x,int c){
    color[x]=c;
    for(int i=h[x]; i!=-1; i=ne[i]){
        int j=e[i];
        if(color[j] == -1){
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false;
    }
    return true;
}
bool check(){
    memset(color,-1,sizeof color);
    rep(i,1,n+1)
        if(color[i] == -1)
            if(!dfs(i,1)) return false;
    return true;
}
```
----
### 9.4.2. 匈牙利算法求最大匹配

+ 时间复杂度：$O(V·E)$

+ 图的存储：链式前向星
```cpp
int n1,n2,m;
int h[N],e[M],ne[M],idx;
bool st[N];
int match[N];
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=1;
            if(match[j]==0 || find(match[j])){//要匹配的，还没匹配或但是已经匹配了的，找另一个
                match[j]=x;
                return 1;
            }
        }
    }
    return 0;
}
// 求最大匹配数
int ans=0;
rep(i,1,n1+1){
    memset(st,0,sizeof st);
    if(find(i)) ans++;
}
```

----
## 9.5. 最大流
### 9.5.1. EK​ 求最大流

+ 根据最大流最小割定理，不断寻找增广路来求最大流

+ 图的存储： 链式前向星存图，边和反向边连续保存，异或访问

+ 时间复杂度：$O(VE^{2})$
```cpp
struct edge
{
    int to,c,ne;
}e[M];

int h[N],idx;
int q[N];
int d[N];  // 访问该点时当前所有边容量的最小值
int pre[N]; // 此节点上一个节点编号
bool st[N];

int n,m,s,t;

void add(int u,int v,int c)
{
    e[idx].to = v;
    e[idx].c = c;
    e[idx].ne=h[u];
    h[u]=idx++;

    e[idx].to = u; // 建立反向边
    e[idx].c = 0;
    e[idx].ne=h[v];
    h[v]=idx++;
}
bool bfs()
{
    int hh=0,tt=0;
    memset(st,0,sizeof st);
    q[0] = s,st[s] = true,d[s] = INF; // 源点
    while(hh <= tt)
    {
        int tmp = q[hh++];
        for(int i = h[tmp];~i;i=e[i].ne)
        {
            int to = e[i].to;
            if(!st[to] && e[i].c) // 当前点没有被遍历过并且有剩余的流量
            {
                st[to] = true;
                d[to] = min(d[tmp],e[i].c); // 流量等于当前增广路的最小值
                pre[to] = i;
                if(to == t) return true; // 到达汇点，即一条增广路径
                q[++tt] = to;
            }
        }
    }
    return false;
}
int EK()
{
    int maxf = 0;
    while( bfs() )
    {
        maxf += d[t];
        for (int i = t; i != s; i = e[pre[i]^1].to) //通过反向边找到这条边的起点
        {
            // 每条边是以出点保存的，所以减要从出点减
            e[pre[i]].c -= d[t]; // 当前增广路径上加上残留的流量后，容量减少
            e[pre[i]^1].c += d[t];// 反向边的容量表示可以减少的值，对应增加
        }
    }
    return maxf;
}
```

----
### 9.5.2. Dinic 求最大流
+ 根据最大流最小割定理，多路增广来求最大流

+ 图的存储： 链式前向星存图，边和反向边连续保存，异或访问

+ 时间复杂度：$O(V^{2}E)$
```cpp
struct edge
{
    int to,c,ne;
}e[M];
int h[N],idx;
int q[N],d[N],cur[N];// 队列、层数、当前弧
int n,m,S,T;

void add(int u,int v,int c)
{
    e[idx].to=v;
    e[idx].c = c;
    e[idx].ne=h[u];
    h[u]=idx++;

    e[idx].to=u;
    e[idx].c=0;
    e[idx].ne=h[v];
    h[v]=idx++;
}

bool bfs()
{
    int hh=0,tt=0;
    memset(d,-1,sizeof d); // 每一次都重新分层
    q[0]=S,d[S]=0,cur[S]=h[S];
    
    while(hh <= tt)
    {
        int now = q[hh++];
        for(int i = h[now]; ~i; i = e[i].ne)
        {
            int to = e[i].to;
            if(d[to] == -1 && e[i].c) // 当前点的层数未更新即未访问
            {
                d[to] = d[now]+1;
                cur[to] =  h[to]; // 当前的弧是这个
                if(to == T) return true;
                q[++tt] = to;
            }
        }
    }
    return false;
}

int find(int u,int limit)
{
    if(u == T) return limit;
    int flow = 0;
    for(int i=cur[u]; ~i && flow < limit ; i = e[i].ne)
    {
        cur[u] = i; // 当前弧优化,即当前弧度计算过后，不会再访问这个弧
        int to = e[i].to;
        if(d[to] == d[u] + 1 && e[i].c)
        {
            int tmp= find(to ,min(e[i].c, limit - flow));
            if(!tmp) d[to] =-1;
            e[i].c -= tmp,e[i^1].c += tmp,flow += tmp;
        }
    }
    return flow;
}

int Dinic()
{
    int maxflow = 0,flow;
    while(bfs())
        while(flow = find(S,INF)) // 从源点开始
            maxflow += flow; // 当前有增广路，即可以贪心的增加流量
    return maxflow;
}
```

----