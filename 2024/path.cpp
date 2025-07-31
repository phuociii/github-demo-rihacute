#include <bits/stdc++.h>

using namespace std;

template <class T1, class T2>
    bool maximize (T1 &a, T2 b) {
        if (a < b) {a = b; return true;} return false;
    }

template <class T1, class T2>
    bool minimize (T1 &a, T2 b) {
        if (a > b) {a = b; return true;} return false;
    }

#define el '\n'
#define MASK(n) (1 << (n))
#define GETBIT(mask, n) (((mask) >> (n)) & 1)

const int oo  = (int) (1e9 + 2007);
const long long INF = (long long) (1e18 + 2007);

/* Author: Pham Gia Phuoc */

/** Drink a cup of coffee before read my code :> **/

const int MAXN_SUB2 = 1111;
const int MAXK_SUB4 = 10;
const int MAXN = (int)(1e5 + 111);
const int MOD = (int)(1e9 + 7);

int numRow, numCol, numBan;
bool isBaneed[MAXN_SUB2][MAXN_SUB2];
vector <pair<int, int>> baneed;

void init (void) {
    cin >> numRow >> numCol >> numBan;
    memset(isBaneed, false, sizeof(isBaneed));
    for (int i = 1; i <= numBan; i++) {
        int x, y; cin >> x >> y;
        if (numRow <= 1000 && numCol <= 1000) isBaneed[x][y] = true;
        baneed.push_back(make_pair(x, y));
    }
}

namespace subtask2 {
    bool ok (void) {
        return (numRow <= 1000 && numCol <= 1000);
    }   

    long long dp[MAXN_SUB2][MAXN_SUB2];

    void solve (void) {
        dp[1][1] = 1;
        for (int i = 1; i <= numRow; i++) {
            for (int j = 1; j <= numCol; j++) {
                if(i == 1 && j == 1) continue; 
                if (isBaneed[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        cout << dp[numRow][numCol] << el;
    }
}

namespace subtask3 {
    bool ok (void) {
        return (numBan == 0);
    }

    long long factorial[MAXN];
    long long inverseFactorial[MAXN];

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    void solve (void) {
        factorial[0] = 1;
        for (int i = 1; i <= numRow + numCol - 2; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        inverseFactorial[numRow + numCol - 2] = 1;
        for (int i = numRow + numCol - 3; i >= 0; i--) {
            inverseFactorial[i] = (power(factorial[i + 1], MOD - 2, MOD) * (i + 1)) % MOD;
        }

        long long result = (factorial[numRow + numCol - 2] * inverseFactorial[numRow - 1]) % MOD;
        result = (result * inverseFactorial[numCol - 1]) % MOD;

        cout << result << el;
    }
}

namespace subtask5 {
    bool ok (void) {
        return true;
    }

    long long product[MAXN][2], dist[MAXK_SUB4][MAXK_SUB4];
    long long factorial[MAXN];
    long long inverseFactorial[MAXN];

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    void preCompute (void) {
        factorial[0] = 1;
        for (int i = 1; i <= numRow + numCol - 2; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        inverseFactorial[numRow + numCol - 2] = 1;
        for (int i = numRow + numCol - 3; i >= 0; i--) {
            inverseFactorial[i] = (power(factorial[i + 1], MOD - 2, MOD) * (i + 1)) % MOD;
        }
    }

    long long distFromStart (int x, int y) {
        long long result = (factorial[x + y - 2] * inverseFactorial[x - 1]) % MOD;
        result = (result * inverseFactorial[y - 1]) % MOD;
        return result;
    }

    long long distToEnd (int x, int y) {
        long long result = distFromStart(numRow, numCol);
        result = (result * )
    }

    void solve (void) {

    }
}

void solve (void) {
    if (subtask2::ok()) {subtask2::solve(); return;}
    if (subtask3::ok()) {subtask3::solve(); return;}
}

int main (void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    init();
    solve();

    return 0;
}

/*** T1WIN ***/