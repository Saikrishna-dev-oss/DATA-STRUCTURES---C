#include <stdio.h>
#include <string.h>

// Function to compute the prefix table (partial match table)
void computePrefixTable(char* pattern, int patternLength, int* prefixTable) {
    int length = 0; // Length of the previous longest prefix suffix
    prefixTable[0] = 0; // First element is always 0

    for (int i = 1; i < patternLength; i++) {
        while (length > 0 && pattern[i] != pattern[length]) {
            length = prefixTable[length - 1];
        }

        if (pattern[i] == pattern[length]) {
            length++;
        }

        prefixTable[i] = length;
    }
}

// KMP pattern matching function
void KMP(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int prefixTable[patternLength];

    // Preprocess the pattern to create the prefix table
    computePrefixTable(pattern, patternLength, prefixTable);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i - j);
            j = prefixTable[j - 1];
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%99s", text);

    printf("Enter the pattern: ");
    scanf("%49s", pattern);

    printf("Performing KMP Pattern Matching...\n");
    KMP(text, pattern);

    return 0;
}