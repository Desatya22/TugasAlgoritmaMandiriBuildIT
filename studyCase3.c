#include <stdio.h>
#include <stdlib.h>

/* Study Case 3: Menghitung pasangan koin dengan nilai berbeda. */
static const long long MOD = 1000000007LL;

static int compare_long_long(const void *left, const void *right) {
    long long a = *(const long long *)left;
    long long b = *(const long long *)right;

    if (a < b) {
        return -1;
    }
    if (a > b) {
        return 1;
    }
    return 0;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    long long *coins = (long long *)malloc((size_t)n * sizeof(*coins));
    if (coins == NULL) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &coins[i]) != 1) {
            free(coins);
            return 0;
        }
    }

    qsort(coins, (size_t)n, sizeof(*coins), compare_long_long);

    long long answer = ((long long)n * (n - 1) / 2) % MOD;

    int group_start = 0;
    while (group_start < n) {
        int group_end = group_start + 1;

        while (group_end < n && coins[group_end] == coins[group_start]) {
            ++group_end;
        }

        long long frequency = group_end - group_start;
        long long equal_pairs = frequency * (frequency - 1) / 2;
        answer = (answer - equal_pairs % MOD + MOD) % MOD;

        group_start = group_end;
    }

    printf("%lld\n", answer);

    free(coins);
    return 0;
}
