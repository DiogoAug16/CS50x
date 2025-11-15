#include <stdio.h>
#include <cs50.h>

void print_row(int n) {
    for (int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = get_int("Height: ");
    for (int i = 1; i < n; i++) {
        printf(" ");
        print_row(n);
    }
    return 0;
}
