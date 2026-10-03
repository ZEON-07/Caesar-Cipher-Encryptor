#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * Encrypts the input text in-place using the Caesar cipher algorithm.
 *
 * @param text  Pointer to the null-terminated string to encrypt.
 * @param shift The numeric key indicating how many positions to shift letters.
 */
void encrypt(char *text, int shift) {
    // TODO: Issue #1 & #2 - Implement ASCII math and alphabet wrap-around here.
}

int main(void) {
    char text[BUFFER_SIZE];
    int shift = 0;

    printf("Enter plaintext: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Error reading input text.\n");
        return 1;
    }

    // Strip trailing newline character if present
    text[strcspn(text, "\r\n")] = '\0';

    printf("Enter shift key (integer): ");
    if (scanf("%d", &shift) != 1) {
        fprintf(stderr, "Invalid shift key provided.\n");
        return 1;
    }

    // Call encryption function (currently empty)
    encrypt(text, shift);

    printf("Ciphertext: %s\n", text);

    return 0;
}
