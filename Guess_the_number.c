#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int check_and_update_highscore(int current_score , const char* filename);
int check_and_update_highscore(int current_score , const char* filename)
{
    FILE *ptr;
    int high_score;

    ptr = fopen(filename, "r");

    // CASE 1: File doesn't exist yet — create one
    if (ptr == NULL)
    {
        printf("Writing to file: %s\n", filename); 
        ptr = fopen(filename, "w");
        fprintf(ptr, "%d", current_score);
        fclose(ptr);
        printf("You set the first high score: %d\n", current_score);
        return 1;
    }

    // CASE 2: File exists — check and update if needed
    fscanf(ptr, "%d", &high_score);
    fclose(ptr);

    if (current_score < high_score)
    {
        ptr = fopen(filename, "w");
        fprintf(ptr, "%d", current_score);
        fclose(ptr);
        printf(" You made a new high score of %d\n", current_score);
        return 1;
    }
    else
    {
        printf("Previous High Score was %d Guesses\n", high_score);
        return 0;
    }
}
int main()
{
    srand(time(0)); // Seed random number generator with current time
    while (1)       // Whole logic inside a loop to Let the player play again
    {
        int diff;
        int max_attempts = -1;
        char filename[30];
        printf("\033[1;33mSelect Difficulty level 0->easy,1->medium,2->hard:\033[0m\n");//Difficulty logic
        scanf("%d", &diff);

        int random_num;
        if (diff == 0) // EASY
        {
            strcpy(filename, "highscore_easy.txt");
            random_num = (rand() % 50) + 1; // Generate random number between 1 and 50
            printf("I've picked a number between 1 and 50 . Try to guess it!\n");
        }
        else if (diff == 1) // MEDIUM
        {
            strcpy(filename, "highscore_medium.txt");
            random_num = (rand() % 100) + 1; // Generate random number between 1 and 100
            printf("I've picked a number between 1 and 100 . Try to guess it!\n");
        }
        else if (diff == 2) // HARD
        {
            strcpy(filename, "highscore_hard.txt");
            random_num = (rand() % 200) + 1; // Generate random number between 1 and 200
            max_attempts = 10;
            printf("Hard Mode! You have 10 attempts to guess between 1 and 200.\n");
        }
        else
        {
            printf("Invalid input. Exiting...\n");
            return 1;
        }
        int no_of_guesses = 0;
        int guessed_number;

        do
        {
            if (max_attempts != -1 && no_of_guesses >= max_attempts)
            {
                printf(" You've used all %d attempts. The number was %d.\n", max_attempts, random_num);
                break; // Player failed
            }
            if(diff==2 && no_of_guesses == 5){   // small Hint after 5 guesses in hard mode
                printf("\033[1;33mHint: The number is %s.\033[0m\n", random_num % 2 == 0 ? "even" : "odd");
            }
            printf("\033[1;36mGuess the number (%d attempts left): \033[0m",
                   max_attempts == -1 ? 999 : max_attempts - no_of_guesses);
            scanf("%d", &guessed_number);
            no_of_guesses++;

            if (guessed_number > random_num)
                printf("\033[1;31mLower number please!\033[0m\n\n");
            else if (guessed_number < random_num)
                printf("\033[1;31mHigher number please!\033[0m\n");
            else
            {
                printf(" \033[1;32mCongratulations! You guessed it right. It is %d\033[0m\n", random_num);
                check_and_update_highscore(no_of_guesses,filename);
                break;
            }

        } while (1); 

        printf("you took %d guesses. \n", no_of_guesses);
        char choice;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            printf("\033[1;35mThanks for playing!\033[0m\n");
            break;
        }
        printf("-----------------------------------------------------------------------------------------\n");
    }
    return 0;
}