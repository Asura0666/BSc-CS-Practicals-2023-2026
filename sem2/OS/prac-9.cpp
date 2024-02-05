
#include<stdio.h>
#include<conio.h>
int fr[3] = { -1, -1, -1 };
void display() {
    printf("\n");
    for(int i = 0; i < 3; i++)
        printf("%d\t", fr[i]);
}
void main() {
    clrscr();
    int page[12] = { 2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2 };
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;
    for(int i = 0; i < 3; i++)
        fr[i] = -1;
    for(int j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;
        for(int i = 0; i < 12; i++) {
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
                if(top > 0)
                    top--;
                else
                    top = frsize - 1;
                fr[top] = page[j];
                pf++;
            }
        }
        if(flag2 == 0) {
            pf++;
        }
        display();
    }
    printf("Number of page faults: %d ", pf + frsize);
    getch();
}
