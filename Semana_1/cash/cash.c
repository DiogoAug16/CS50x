#include <stdio.h>
#include <cs50.h>

int ask_owed_amount(void) {
    int owed_amount;
    do {
        owed_amount = get_int("Owed amount: ");
    } while (owed_amount < 0);
    return owed_amount;
}

int exchange_calculator(int owed_amount) {
    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    for (int i = 0; i < 4; i++) {
        while (owed_amount >= denominations[i]) {
            owed_amount -= denominations[i];
            coins++;
        }
    }
    return coins;
}

int main(int argc, char const *argv[])
{
    /* code */
    int owed_amount = ask_owed_amount();
    int coins = exchange_calculator(owed_amount);
    printf("Number of coins: %d\n", coins);
    return 0;
}
