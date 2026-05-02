#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 2) {
        printf("%lld\n", n);
        return 0;
    }

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (mid == 0) {
            low = 1;
            continue;
        }

        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
