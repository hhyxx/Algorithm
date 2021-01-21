

// 推论 1～N中每个数的约数个数的总和大约为NlogN
// 每个数的约数大小不超过N
// 时间复杂度 O（ NlogN ） 
vector<int>factor[N];
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n/i; j++)
    factor[i*j].push_back(i);

for(int i = 1; i <= n; i++){
    for(int j = 0; j < factor[i].size(); j++)
        printf("%d",factor[i][j]);
    puts("");    
}


// 算术基本定理：任意一个大于1的正整数都能唯一分解成有限个质数的乘积
// 即 N = p1^c1 * p2^c2 * ... *pk^ck，其中p表示质数
// 如果约数 d = p1^c1 * p2^c2 * ... *pk^ck
// 约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
// 约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)



