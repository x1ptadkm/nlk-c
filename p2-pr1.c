#include <stdio.h>
#include <math.h>
#include <ctype.h>


int isPerfectSquareNumber(int n) {
    int sqrt_n = (int)sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

void printMinMaxDigit(int n) {
    int minDigit=9, maxDigit=0, digit;
    while(n>0) {
        digit=n%10;
        if(digit<minDigit) minDigit=digit;
        if(digit>maxDigit) maxDigit=digit;
        n/=10;
    }
    printf("min digit: %d\n", minDigit);
    printf("max digit: %d\n", maxDigit);
}

void printCharData(char ch1, char ch2) {
	char ch;
    if(ch1<ch2)
        for(ch=ch2; ch>=ch1; ch--)
            printf("%c: %d\n", ch, ch);
    else 
        for(ch=ch1; ch>=ch2; ch--)
            printf("%c: %d\n", ch, ch);
}

int main() {
    int choice, n;
    char ch1, ch2;

    do {
        printf("1- Process PerfectSquareNumber\n");
        printf("2- Min, max digit in an integer\n");
        printf("3- Character descending order\n");
        printf("4- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);

 		switch(choice) {
            case 1:
                do {
                    printf("Enter a non-negative integer: ");
                    scanf("%d", &n);
                    if(n<0) 
                        printf("Invalid input! Please enter a non-negative integer\n");
                } while(n<0);

                if(isPerfectSquareNumber(n))
                    printf("%d is a PerfectSquareNumber\n", n);
                else 
                    printf("%d is not a PerfectSquareNumber\n", n);
                break;

            case 2:
                do {
                    printf("Enter a non-negative integer: ");
                    scanf("%d", &n);
                    if (n<0) 
                        printf("Invalid input! Please enter a non-negative integer\n");
                } while(n<0);
                printMinMaxDigit(n);
                break;

            case 3:
                printf("Enter two characters: ");
                scanf(" %c %c", &ch1, &ch2); 
                printCharData(ch1, ch2);
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please choose again\n");
                break;
        }
    } while(choice!=4);

    return 0;
}

