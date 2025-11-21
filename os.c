#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void move_cursor_up(int n) {
    printf("\033[%dA", n);
}

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int *req = malloc(n * sizeof(int));
    if (!req) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_movement = 0;
    int current = head;

    printf("\nFCFS Head Movement:\n");

    printf("%d\n", head);
    fflush(stdout);
    usleep(500000);

    for (int i = 0; i < n; i++) {
        total_movement += abs(req[i] - current);
        current = req[i];

        move_cursor_up(1);

        printf("%d", head);
        for (int j = 0; j <= i; j++)
            printf(" -> %d", req[j]);

        printf("   ");
        printf("\n");
        fflush(stdout);

        usleep(500000);
    }

    printf("\nTotal Seek Time: %d\n", total_movement);

    free(req);
    return 0;
}
