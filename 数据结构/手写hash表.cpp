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



// 开放寻址法
int h[N];

// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x)
{
   int t = (x % P + P) % P;
   while (h[t] != null && h[t] != x)
   {
      t ++ ;
      if (t == N) t = 0;
   }

   return t;
}



