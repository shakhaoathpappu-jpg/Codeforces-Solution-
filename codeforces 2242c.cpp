#include<bits/stdc++.h>
using namespace std;

constexpr int N = 5e3 + 20;
int dp[N][N];

vector<vector<int>> makeMinLen(string s) {
    const int n = (int) s.size();
    vector<vector<int>> minPos(n, vector<int>(10, N));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += s[j] - '0';
            if (sum >= 10) {
                sum -= 10;
            }
            minPos[i][sum] = min(minPos[i][sum], j);
        }
    }
    return minPos;
};

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        const int n = (int) a.size(), m = (int) b.size();

        vector<vector<int>> minPosA = makeMinLen(a), minPosB = makeMinLen(b);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -N;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 10; k++) {
                    int ma = minPosA[i][k], mb = minPosB[j][k];
                    if (ma != N && mb != N) {
                        dp[ma + 1][mb + 1] = max(dp[ma + 1][mb + 1], dp[i][j] + 1);
                    }
                }
            }
        }

        int answer = -1;
        int sumA = 0;
        for (int i = n; i > 0; i--) {
            int sumB = 0;
            for (int j = m; j > 0; j--) {
                if (sumA == 0 && sumB == 0) {
                    answer = max(answer, dp[i][j]);
                }
                sumB += b[j - 1] - '0';
                if (sumB >= 10) {
                    sumB -= 10;
                }
            }

            sumA += a[i - 1] - '0';
            if (sumA >= 10) {
                sumA -= 10;
            }
        }
        cout << answer << endl;
    }
}
