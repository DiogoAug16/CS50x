#include <stdio.h>
#include <cs50.h>

void print_row(int n) {
    for (int i = 1; i <= n; i++) {
        
        for (int k = n; k > i; k--) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("#");
        }
        
        printf("\n");
    }
}

int ask_height() {
    int n;
    do {
        n = get_int("Height: ");
    } while (n <= 0 );
    return n;
}

int main(int argc, char const *argv[])
{
    /* code */
    print_row(ask_height());

    return 0;
}
