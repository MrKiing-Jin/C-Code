#include <bits/stdc++.h>
using namespace std;
// ��⣺https://blog.csdn.net/qq_52652816/article/details/122333311?ops_request_misc=&request_id=&biz_id=102&utm_term=%E5%B7%A6%E5%AD%A9%E5%AD%90%E5%8F%B3%E5%85%84%E5%BC%9F&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-122333311.first_rank_v2_pc_rank_v29&spm=1018.2226.3001.4187
// ������ǰ�>2���ֵܽڵ�������Ļ�����ô��������һ���ڵ�������������ģ���������ڵ�ĸ߶Ⱦ͵��ڸ߶ȼ���ȣ��������������Ҫ��ø���ĸ߶ȣ�ֻ��Ҫ�Ѹ߶������Ǹ��ڵ��ҳ����������ŵ����һ�����ɡ�
// �����Ļ����ݹ��ϵ�ͳ����ˣ��ҵ��߶����ĺ��ӽڵ㣬����������ԭ���ĸ��ڵ�����
// ֪ʶ�㣺����dp
vector<int> edge[100000];
int dp[1000090]; // dp[i]�����i����㵱���ڵ�ʱ����ʱ����Ϊ����������������Ϊ����
void dfs(int x)  // xΪ��ǰ�ڵ�
{
    int len=edge[x].size();
    int max1=0;
    for(int i=0;i<len;i++)//Ѱ�������߶������ӽڵ�
    {
        int son=edge[x][i];
        dfs(son);
        max1=max(max1,dp[son]);
    }
    dp[x]=max1+len;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int remp;
        cin >> remp;
        edge[remp].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}