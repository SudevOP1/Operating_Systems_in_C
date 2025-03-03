#include<stdio.h>
#include<conio.h>

int mutex = 1;
int full  = 0;
int empty = 10;
int x     = 0;

void prod() {
    if(mutex == 1 && empty != 0) {
        --mutex;
        ++full;
        --empty;
        x++;
        printf("Producer produced %d\n", x);
        ++mutex;
    } else {
        printf("Buffer is full\n");
    }
}

void cons() {
    if(mutex == 1 && full != 0) {
        ++mutex;
        --full;
        ++empty;
        x--;
        printf("Consumer comsumed %d\n", x);
        --mutex;
    } else {
        printf("Buffer is empty\n");
    }
}

int main() {
    // clrscr();

    int choice, running=1;
    while(running == 1) {

        printf("---------------------------\n");
        printf("Choice 1: Produce\n");
        printf("Choice 2: Consume\n");
        printf("Choice 3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case (1):
                prod();
                break;
            case (2):
                cons();
                break;
            case (3):
                running = 0;
                break;  
            default:
                printf("Enter a valid choice:\n");
                break;
        }
    }


    // getch();
    return 0;
}