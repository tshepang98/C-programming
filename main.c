/*****************************
DECIMAL TO RADIX-i converter
Written by: Tshepang
Date: 2023
*****************************/
#include <stdio.h>

int main() {
    // initiate d (decimal), i (radix), r(remainder)
    int d, i, r;
    char result[50] = "";
    printf("Enter decimal number: ");
    scanf("%d", &d);

    // if the decimal number is negative terminate the program
    if(d < 0){
        return 0;
    }
    printf("Enter radix (between 2 and 16): ");
    scanf("%d", &i);
    int increment = 0;
    while (d > 0) {
        r = d % i;
        if (r < 10) {
            // I want to convert r by number asscociated with the ascii by adding with ('0'=48)
            result[increment] = r + '0';
        } 
        else {
            if (r == 10) {
                result[increment] = 'A';  
            }
            else if (r == 11) {
                result[increment] = 'B';
            }
            else if (r == 12) {
                result[increment] = 'C';
            }
            else if (r == 13) {
                result[increment] = 'D';
            }
            else if (r == 14) {
                result[increment] = 'E';
            }
            else if (r == 15) {
                result[increment] = 'F';
            }
        }
        increment++;
        d = d / i;
    }
    int start = 0;
    int end = increment - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    printf("Converted number:\n%s base %d\n", result, i);
    return 0;
}

