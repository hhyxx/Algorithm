//时间复杂度 O(NC) N为节点个数，C是字符集大小

int trie[N][26], cnt[N], tot=1;
// 0号点既是根节点，又是空节点
// trie[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
inline void insert(char *str)
{
    int p = 1;
    for (int i = 0; str[i]; i ++ )
    {
        int ch = str[i] - 'a';
        if (!trie[p][ch]) trie[p][ch] = ++ tot;
        p = trie[p][ch];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
inline int query(char *str)
{
    int p = 1;
    for (int i = 0; str[i]; i ++ )
    {
        int ch = str[i] - 'a';
        if (!trie[p][ch]) return 0;
        p = trie[p][ch];
    }
    return cnt[p];
}