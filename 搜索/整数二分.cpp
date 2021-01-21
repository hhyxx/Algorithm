// 在单调递增序列a中查找>=x的数中最小的一个（即x或x的后继）
//找在单调序列中第一个出现的元素
while (l < r) 
{
    int mid = (l + r) / 2;
    if (a[mid] >= x) 
        r = mid; 
    else 
        l = mid + 1;
}

// 在单调递增序列a中查找 <= x的数中最大的一个（即x或x的前驱）
// 找在单调序列中最后一个出现的元素
while (l < r) 
{
    int mid = (l + r + 1) / 2;// 避免 L=0，r=1时候L=mid=0无限循环
    if (a[mid] <= x) 
        l = mid; 
    else 
        r = mid - 1;
}

//1）缩小范围时，r=mid ，l=mid+1，取中间值时候mid=l+r>>1
//2）缩小范围时，l=mid，r=mid-1，取中间值时mid=( l + r + 1) >>1
//对于此种取法如果r-l等于1 时候，有mid=( l + r )>>1 = l 接下来进入 l =mid 分支
//区域并未缩小会进入死循环
//3）二分的终止条件是 l=r