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
        if (scanf(" %c", &command) != 1)
        {
            return 1;
        }

        switch (command)
        {
        case 'q':
            outputAccountData(accounts, 5, bank);
            return 0;
        case 'p':
            /* TODO Task 1: print positive and negative balances. */
            break;
        case 's':
            /* TODO Task 2: read and deduct a service charge. */
            break;
        case 'i':
            /* TODO Task 3: apply interest. */
            break;
        case 'b':
            /* TODO Task 4: read a valid account ID and change its balance. */
            break;
        case 'd':
            /* TODO Task 5: print the percentage of debtors. */
            break;
        case 'r':
            /* TODO Task 6: remove the version from the bank name. */
            break;
        case 'n':
            /* TODO Task 7: read a new bank name. */
            break;
        }
    }
}
