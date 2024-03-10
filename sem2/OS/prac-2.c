#include <stdio.h>
#include <stdlib.h>
#include <dos.h> 

#define BUFFER_SIZE 5

char buffer[BUFFER_SIZE][100]; 
int fill = 0;
int use = 0;

void producer(int product_count) {
    for (int i = 0; i < product_count; i++) {
        sprintf(buffer[fill], "Product %d", i);
        printf("Producer made %s\n", buffer[fill]);
        fill = (fill + 1) % BUFFER_SIZE;
        delay(1000); 
    }
}

void consumer(int product_count) {
    for (int i = 0; i < product_count; i++) {
        printf("Consumer consumed %s\n", buffer[use]);
        use = (use + 1) % BUFFER_SIZE;
        delay(2000);
    }
}

int main() {
    int produce_count, consume_count;
    printf("Enter the number of products to produce and consume: ");
    scanf("%d %d", &produce_count, &consume_count);

    if (produce_count > BUFFER_SIZE || consume_count > BUFFER_SIZE) {
        printf("Buffer size is too small to handle the requested number of products.\n");
        return 1;
    }

    producer(produce_count);
    consumer(consume_count);

    printf("Total products produced: %d\n", produce_count);
    printf("Total products consumed: %d\n", consume_count);

    return 0;
}
