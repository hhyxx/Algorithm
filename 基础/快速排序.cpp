//快速排序 O(nlogn)
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l]; //运行时i加1，j减1，故如此
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
        else break;
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

//快速选择求第k大的数字 O(n)
int quick_sort(int l,int r,int k){
    if(l==r) return a[l];
    int x=a[l],i=l-1,j=r+1;
    while(i<j){
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    int sl=j-l+1;
    if(k<=sl) return quick_sort(l,j,k);
    else return quick_sort(j+1,r,k-sl);
}