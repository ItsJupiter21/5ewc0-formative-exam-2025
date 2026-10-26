/* Locally reconstructed baseline from page 1 and test case 0.
 * The original exam skeleton was not included with the PDF.
 * Tasks 1-7 are intentionally left for you to implement.
 */
#include <stdio.h>
#include <string.h>

void initializeAccountData(float accounts[], int size, char bank[])
{
    const float initial[] = {-100.00f, 4.65f, 1333.33f, 0.00f, -50.45f};
    for (int i = 0; i < size; i++) {
        accounts[i] = initial[i];
    }
    strcpy(bank, "The first PEC bank [v1.0]");
}

void outputAccountData(float accounts[], int size, char bank[])
{
    printf("** accounts **\n");
    for (int i = 0; i < size; i++) {
        printf("Account %d: %.2f\n", i, accounts[i]);
    }
    printf("** bank **\n%s\n", bank);
}

int main(void)
{
    float accounts[5];
    char bank[64];
    char command;
    initializeAccountData(accounts, 5, bank);
    printf("** Bank **\n");
    for (;;)
    {
        printf("Command? ");
        scanf(" %c", &command);

        if (command == 'q')
        {
            outputAccountData(accounts, 5, bank);
            return 0;
        }

        /* Implement the other commands here. */
    }
}
