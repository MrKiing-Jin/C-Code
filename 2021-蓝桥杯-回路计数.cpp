#include <bits/stdc++.h>
using namespace std;
// �����ţ�https://blog.csdn.net/qq_36306833/article/details/121872050
// ��⣺https://blog.csdn.net/weixin_50533561/article/details/122753240?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164440729916780264043462%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164440729916780264043462&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-6-122753240.first_rank_v2_pc_rank_v29&utm_term=%E8%93%9D%E6%A1%A5%E6%9D%AF%E5%9B%9E%E8%B7%AF%E8%AE%A1%E6%95%B0&spm=1018.2226.3001.4187
// ״ѹdp
bool edge[30][30];
const int N = 22, M = 1 << 21; // ��MΪ������10000...000(21��0), M-1 = 21��1
long long dp[M][30];           // dp[i][j]����״̬Ϊiʱ,�ߵ���j����ʱ��ʱ�ķ�����
// ����Ҫlong long���������(��������ô֪����T_T)
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
bool judge(int x, int y)
{
    if (gcd(x, y) == 1)
        return true;
    else
        return false;
}
int main()
{
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j <= 21; j++)
            if (judge(i, j))
                edge[i][j] = 1;
    // ״ѹdp
    dp[1][1] = 1;                                                          //��1�ŵ��������ʱ״̬Ϊ00000...0001
    for (int i = 1; i <= M - 1; i++)                                       // M-1��Ϊ111....11111(21��1)��ö������״̬
        for (int j = 1; j <= 21; j++)                                      //ö��1-21��
            if (i >> (j - 1) & 1)                                          //���������j������ʱ��Ϊ�棬������״̬�д�������j�����߹�
                for (int k = 1; k <= 21; k++)                              //��״̬�к��иõ㣬��ö��j��ͨ�ĵ㣬Ѱ����kΪ��ת����j��
                    if (edge[k][j] && (i - (1 << (j - 1))) >> (k - 1) & 1) //��δ��j֮ǰ��״̬Ϊ i-(1<<j) �ж��Ƿ��߹�k��
                    //(i - (1 << (j - 1))) >> k & 1)�ж�i״̬ʱû��j�Ƿ�����k
                    {
                        dp[i][j] += dp[(i - (1 << (j - 1)))][k]; //���߹�k��˵������j��״̬i��������ȥj���Ǻ���k��״̬���
                    }
    long long ans = 0;
    for (int i = 2; i <= 21; i++) // dp[1111111..1111][i]�����������겢���յ�Ϊi������
    //Ҫ��i=2��ʼ����Ϊ�յ㲻��������㣡
    {
        ans += dp[M - 1][i];
    }
    cout << ans;
    return 0;
}