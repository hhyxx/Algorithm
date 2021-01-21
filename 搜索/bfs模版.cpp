/*
1）只有在访问完成第i层节点后，才会访问第i+1层节点
2）任意时刻队列中最多有两个层次的节点
3）以上两点即两段性和单调性
4）复杂度是O（n+m）
*/
void bfs(){
   memset(d,0,sizeof d);//d即节点在树中的深度
   queue<int>q;
   q.push(1);
   d[1]=1;
   while(q.size()>1){
      int x=q.front();
      q.pop();
      for(int i=head[x];i;i=next[i]){
         int y=ver[i];
         if(d[y]) continue;
         d[y]=d[x]+1;
         q.push(y);
      }
   }
}