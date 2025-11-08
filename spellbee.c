#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define BOLD    "\033[1m"

void jumbleWord(char *word, char *jumbled) {
    strcpy(jumbled, word);
    int len = strlen(jumbled);
    for (int i = 0; i < len; i++) {
        int r = rand() % len;
        char temp = jumbled[i];
        jumbled[i] = jumbled[r];
        jumbled[r] = temp;
    }
}

// Function to get a random unused index
int getUniqueIndex(int used[], int size, int total) {
    int idx;
    do {
        idx = rand() % total;
    } while (used[idx] == 1);  // repeat until unused found
    used[idx] = 1;             // mark as used
    return idx;
}

int main() {
    char *animals[] = {"tiger", "lion", "elephant", "zebra", "monkey", "giraffe", "rabbit", "kangaroo", "panda", "cheetah"};
    char *hints[] = {
        "It has stripes and roars.",
        "King of the jungle.",
        "Largest land animal.",
        "Black and white stripes.",
        "Loves bananas.",
        "Has a long neck.",
        "Has long ears and hops.",
        "Carries its baby in a pouch.",
        "Eats bamboo.",
        "Fastest land animal."
    };

    int n = 10;
    int rounds = 5;
    int score = 0;
    int used[10] = {0}; // track used animals
    char guess[50], jumbled[50];

    srand(time(0));
    
    printf(CYAN "\n=============================================================\n" RESET);
    printf(BOLD BLUE  "                🐾 Animal SpellBee Game 🐾\n" RESET);
    printf(CYAN "=============================================================\n" RESET);
    printf(BOLD YELLOW "       A fun console game to unscramble animal names!\n" RESET);
    printf(BOLD GREEN  "       Developed by: Swaroop Lenka\n" RESET);
    printf(CYAN "-------------------------------------------------------------\n" RESET);
    printf(BLUE "🧩 Instructions: Unscramble the animal name and type your answer.\n\n" RESET);



    for (int i = 0; i < rounds; i++) {
        int idx = getUniqueIndex(used, i, n);
        jumbleWord(animals[idx], jumbled);

        printf(MAGENTA "Round %d of %d\n" RESET, i + 1, rounds);
        printf(BOLD YELLOW "Jumbled Word: " RESET GREEN "%s\n" RESET, jumbled);
        printf(BLUE "Hint: %s\n" RESET, hints[idx]);
        printf(CYAN "Your Guess: " RESET);
        scanf("%s", guess);

        if (strcasecmp(guess, animals[idx]) == 0) {
            printf(GREEN "✅ Correct!\n" RESET);
            score++;
        } else {
            printf(RED "❌ Wrong! The correct word was: %s\n" RESET, animals[idx]);
        }

        printf(YELLOW "Current Score: " BOLD "%d / %d\n" RESET, score, i + 1);
        printf(CYAN "---------------------------------------------\n\n" RESET);
    }

    printf(BOLD CYAN "\n🎯 Game Over! 🎯\n" RESET);
    printf(BOLD "Your Final Score: %d / %d\n" RESET, score, rounds);

    if (score == rounds)
        printf(GREEN "Excellent! You’re a true Animal Expert! 🦁\n" RESET);
    else if (score >= 3)
        printf(YELLOW "Good job! You know your animals well. 🐘\n" RESET);
    else
        printf(RED "Keep practicing! You’ll get better! 🐾\n" RESET);

    printf(CYAN "=============================================\n" RESET);
    printf(BLUE "Thanks for playing the Animal SpellBee Game!\n" RESET);
    printf(CYAN "=============================================\n\n" RESET);

    return 0;
}

// gcc JumbleBee_The_Animal_Word_Game.c -o JumbleBee && ./JumbleBee
