#include <cstdio>
#include <cstring>
const int MAXN = 10000 + 1234;
int n, q;
int con[MAXN];
int p[MAXN];
int num[MAXN];
int find(int x)
{
    if(p[x] == x) return x;
    int t = p[x]; //��Ϊѹ��·��������,���Բ����ظ��ӣ�����ֵΪ0��
    p[x] = find(p[x]);
    num[x] += num[t];
    return p[x];
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        p[a] = b;
        con[b] += con[a];
        num[a] = 1;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        scanf("%d%d", &n, &q);
        //�����Ŀ�ĳ�����ʵ�����ǿ����ϵĸ��ڵ㡣��������
        for(int i = 1; i <= n; i++)  con[i] = 1;
        for(int i = 1; i <= n; i++)  p[i] = i;
        memset(num, 0, sizeof(num));
        char str[10];
        printf("Case %d:\n",cas ++);
        for(int i = 1; i <= q; i++)
        {
            scanf("%s", str);
            if(str[0] == 'T')
            {
                int a, b;
                scanf("%d%d", &a, &b);
                Union(a, b);
            }
            else
            {
                int a;
                scanf("%d", &a);
                int fa = find(a);
                printf("%d %d %d\n",fa, con[fa], num[a]);
            }
        }
    }
    return 0;
}

