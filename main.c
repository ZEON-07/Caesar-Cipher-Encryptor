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
    shift = (shift % 26 + 26) % 26;
    for (; *text; text++)
        if (*text >= 'A' && *text <= 'Z') *text = 'A' + (*text - 'A' + shift) % 26;
        else if (*text >= 'a' && *text <= 'z') *text = 'a' + (*text - 'a' + shift) % 26;
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

    // Call encryption function
    encrypt(text, shift);

    printf("Ciphertext: %s\n", text);

    return 0;
}
