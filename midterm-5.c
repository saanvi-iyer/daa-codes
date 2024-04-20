//Design a solution to see if a content C = PGGA is plagiarized in Text T = SAQSPAPGPGGAS


#include <stdio.h>
#include <string.h>
// Function to check if content C is plagiarized in text T
int isPlagiarized(const char *content, const char *text) {
    int content_len = strlen(content);
    int text_len = strlen(text);

    // Iterate through text T using a sliding window
    for (int i = 0; i <= text_len - content_len; ++i) {
        // Check if substring matches content C
        if (strncmp(text + i, content, content_len) == 0) {
            return 1; // Plagiarism detected
        }
    }

    return 0; // No plagiarism detected
}

int main() {
    const char *content = "PGGA";
    const char *text = "SAQSPAPGPGGAS";

    if (isPlagiarized(content, text)) {
        printf("Content is plagiarized in the text.\n");
    } else {
        printf("Content is not plagiarized in the text.\n");
    }

    return 0;
}
