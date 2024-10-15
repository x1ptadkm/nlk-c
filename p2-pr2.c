#include <stdio.h>
int fibo(int n) {
    if(n==1||n==2) return 1;
    int t1=1, t2=1, f=1, i;
    for(i=3; i<=n; i++){
        f=t1+t2;
        t1=t2;
        t2=f;
    }
    return f;
}
int isLeapYear(int y) {
    return(y%400==0 || (y%4==0 && y%100!=0));
}
int validDate(int d,int m,int y){
    if(d<1 || m<1 || m>12)return 0;
    int maxd=31;
    if(m==4 || m==6 || m==9 || m==11) maxd=30;
    else if(m==2) maxd=isLeapYear(y) ? 29 : 28;
    return d<=maxd;
}
int main() {
    int choice;
    do{
        printf("1- Fibonacci sequence\n");
        printf("2- Check a date\n");
        printf("3- Quit\n");
        printf("Choose an operation: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int n;
                do{
                    printf("Enter n (>=1): ");
                    scanf("%d",&n);
                    if(n<1) printf("Please enter a number greater than or equal to 1\n");
                } while(n<1);
                printf("Fibonacci number at position %d: %d\n", n, fibo(n));
                break;
            }
            case 2:{
                int d, m, y;
                printf("Enter day, month, year: ");
                scanf("%d %d %d", &d, &m, &y);
                if(validDate(d, m, y)) printf("Valid date\n");
                else printf("Invalid date\n");
                break;
            }
            case 3:
                printf("Quitting program\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
        }
    }while(choice!=3);
    return 0;
}

