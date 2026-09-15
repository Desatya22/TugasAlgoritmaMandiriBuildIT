#include <stdio.h>

/* Study Case 2: Menghitung ronde permainan tiga pemain. */
static void swap(long long *a, long long *b) {
    long long temporary = *a;
    *a = *b;
    *b = temporary;
}

int main(void) {
    long long cards[3];

    if (scanf("%lld %lld %lld", &cards[0], &cards[1], &cards[2]) != 3) {
        return 0;
    }

    if (cards[0] > cards[1]) {
        swap(&cards[0], &cards[1]);
    }
    if (cards[1] > cards[2]) {
        swap(&cards[1], &cards[2]);
    }
    if (cards[0] > cards[1]) {
        swap(&cards[0], &cards[1]);
    }

    long long left_gap = cards[1] - cards[0];
    long long right_gap = cards[2] - cards[1];
    long long rounds = (left_gap < right_gap) ? left_gap : right_gap;

    printf("%lld\n", rounds);
    return 0;
}
