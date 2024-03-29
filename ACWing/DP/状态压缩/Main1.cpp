#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 1 << N;

long long f[N][M];
bool st[M];
vector<vector<int>> state(M);

int n, m;
int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < (1 << n); i++)
        {
            int cnt = 0;
            bool is_legal = true;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    if (cnt & 1)
                    {
                        is_legal = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            if (cnt & 1)
                is_legal = false;
            st[i] = is_legal;
        }

        for (int i = 0; i < (1 << n); i++)
        {
            state[i].clear();
            for (int j = 0; j < (1 << n); j++)
            {
                if ((i & j) == 0 && st[i | j])
                {
                    state[i].push_back(j);
                }
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                for (auto k : state[j])
                {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        cout << f[m][0] << endl;
    }
}