#include <cs50.h>
#include <stdio.h>

void meow(int n) {
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}

int get_positive_int (void) {
    int n;

    do {
        n = get_int("Number of meows: ");
    } while (n < 1);
    return n;
}

int main(int argc, char const *argv[])
{
    int times = get_positive_int();
    meow(times);

}
