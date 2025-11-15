#include <stdio.h>
#include <cs50.h>

void ask_name_and_greet() {
    string name = get_string("What is your name? ");
    printf("Hello, %s !\n", name);
}

int main(int argc, char const *argv[])
{
    /* code */
    ask_name_and_greet();
    return 0;
}
