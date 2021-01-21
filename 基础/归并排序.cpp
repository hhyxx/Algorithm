// 归并排序算法模板
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] < q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

//归并求逆序对
double res=0;
void merge_sort(int q[],int l,int r){
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) ans[k++]=a[i++];
        else {
            ans[k++] = a[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid) ans[k++]=a[i++];
    while(j<=r) ans[k++]=a[j++];
    for (int i = l,j=0; i <=r ; i++,j++)
        a[i]=ans[j];
}