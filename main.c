#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i CONVERTER"
#define AUTHOR "Tshepang Mathlore"
#define YEAR 2023

int main() {
    printf("********************************\n");
    printf("%s\n", TITLE);
    printf("Written by:%s\n", AUTHOR);
    printf("Date: %d\n", YEAR);
    printf("********************************\n");

    // initiate d (decimal), i (radix), r(remainder)
    int d, i, r;
    char result[50] = "";

    while (true) {
        printf("Enter a decimal number: ");
        scanf("%d", &d);
        printf("The number you have entered is %d\n", d);

        if(d < 0){
            // if the decimal number is negative terminate the program
            printf("EXIT");
            break;
        }

        printf("Enter radix for the converter between 2 and 16: ");
        scanf("%d", &i);
        printf("The radix you have entered is %d\n", i);
        double l = log2(d);
        printf("The log2 of number %d is %.2f \n", d,l);
        int integer = d/i;
        int remainOfInteger = d%i;
        printf("The integer result of the number divided by %i is %d\n",i,integer);
        printf("The remainder is  %d \n", remainOfInteger);
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
        printf("The radix-%d value is %s:\n", i, result);
        memset(result, 0, sizeof(result)); // reset result to all zeroes


    }
    return 0;
}
