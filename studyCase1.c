#include <stdio.h>

/* Study Case 1: Minimum operasi agar jumlah array menjadi nol. */
int main(void) {
    int n;
    long long total = 0;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        long long element;

        if (scanf("%lld", &element) != 1) {
            return 0;
        }

        total += element;
    }

    long long minimum_operations = (total < 0) ? -total : total;
    printf("%lld\n", minimum_operations);

    return 0;
}
