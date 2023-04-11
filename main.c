#include <stdio.h>

int main() {
    // initiate d (decimal), i (radix), r(remainder)
    int d, i, r;
    char result[50] = "";
    printf("Enter decimal number: ");
    scanf("%d", &d);
    printf("Enter radix (between 2 and 16): ");
    scanf("%d", &i);

    if (d < 0) {
        sprintf(result, "-");
        d = -d;
    }

    while (d > 0) {
        r = d % i;
        if (r < 10) {
            sprintf(result, "%d%s", r, result);
        } else {
            sprintf(result, "%c%s", r - 10 + 'A', result);
        }
        d /= i;
    }

    if (result[0] == '\0') {
        sprintf(result, "0");
    }

    printf("Converted number: %s\n", result);
    return 0;
}
