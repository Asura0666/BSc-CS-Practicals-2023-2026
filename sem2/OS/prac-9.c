#include<stdio.h>
#include<conio.h>

void display(int fr[], int frsize) {
    printf("\n");
    for(int i = 0; i < frsize; i++)
        printf("%d\t", fr[i]);
}

int main() {
    int page[12] = { 2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2 };
    int fr[3] = { -1, -1, -1 };
    int pf = 0, frsize = 3, top = 0;

    for(int j = 0; j < 12; j++) {
        int flag1 = 0, flag2 = 0;
        for(int i = 0; i < frsize; i++) {
            if(fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 0) {
            for(int i = 0; i < frsize; i++) {
                if(fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0) {
                fr[top] = page[j];
                top = (top + 1) % frsize; // Circular increment
                pf++;
            }
        }
        display(fr, frsize);
    }
    printf("\nNumber of page faults: %d ", pf);
    return 0;
}
