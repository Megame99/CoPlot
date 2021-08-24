/***********************************************************************************************
 * Filename: coPlot.c
 * Version: 1.3.1
 * Student Name: Megan Machkouri
 * Student Number: 041006409
 * Course Name/Number: CST 8234
 * Lab Section: 014
 * Assignment Name: Lab 04
 * Due Date: July 23rd
 * Submission Date: June 18th
 * Professor Name: Gerald Hurdle
 * Purpose: A simple program that accepts a command then runs the appropriate function and displays
 *  result to user's.
 * ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "coPlot.h"

/***********************************************************************************************
 * Function Name: main
 * Purpose: Allows for program execution and testing.
 * Function In parameters: nothing
 * Function Out parameters: 0 or 1 
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/
int main(){
    
    /*loop control variable*/
    int exitProgram = 0;
    /*Iteration integer in for loop*/
    int a , b, i, p, z;
    /*Temporary storage variable(used for dynamic memory allocation*/
    char buffer[100];
    /*Variable Declarations*/
    char *command, *userChoice, *message;

    /*A do while loop that prompts user to run command*/
    do{

       
        /* Prompt User for number of students. */
        printf("\nPlease enter a command to run:\n");
        scanf("%s", buffer);
        /* dynamically allocate enough memory at run-time to store userChoice; void* calloc(size_t number of elements, size_t size of data type)*/
        userChoice = (char *)calloc((strlen(buffer)+1), sizeof(char));
        /* copy buffer string into userChoice*/
        strcpy(userChoice, buffer);
        /* dynamically allocate enough memory at run-time to store command; void* calloc(size_t number of elements, size_t size of data type)*/
        command = (char *)calloc((strlen(buffer)+1), sizeof(char));
            
            
            /*A for loop for reading and copying userChoice into command array until whitespace(\0)*/
            for(i=0; userChoice[i] != '\0'; i++){
                command[i] = toupper(userChoice[i]); 
            }
            command[i] = '\0'; 
            /*If else structure for processing command and performing corresponding functions*/
            if (strcmp(command, "REVERSE") == 0) /* Print Reverse String*/
            {
                
                scanf("%s", buffer); /*Read in remaing input within stream  until new line */
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                /* dynamically allocate enough memory at run-time to store message; void* calloc(size_t number of elements, size_t size of data type)*/
                message = (char *)calloc((strlen(buffer)+1), sizeof(char));
                /* copy buffer string into message*/
                strcpy(message, buffer);
                
                /*A for loop for reading and printing message  in reverse*/
                for(p = (strlen(message) - 1); p >= 0; p--){
                    printf("%c", message[p]);
                }
                /*Free Memory*/
                free(command);
                free(userChoice);
                free(message);

            }
            else if (strcmp(command, "BIT_AND") == 0) /* Bit_And Operation*/
            {
               scanf("%d %d", &a, &b); /*Scan 2 Integers*/
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("Output = %d", a&b); /*Output bit_and operation result*/
                free(command);
                free(userChoice);
            }
            else if (strcmp(command, "BIT_OR") == 0) /* Bit_Or Operation*/
            {
               scanf("%d %d", &a, &b); /*Scan 2 Integers*/
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("Output = %d", a|b); /*Output bit_or operation result*/
                free(command);
                free(userChoice);
            }
            else if (strcmp(command, "BIT_XOR") == 0) /* Bit_xor Operation*/
            {
               scanf("%d %d", &a, &b);
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("Output = %d", a^b); /*Output bit_xor operation result*/
                free(command);
                free(userChoice);
            }
            else if (strcmp(command, "BIT_SHIFT_LEFT") == 0)
            {
               scanf("%d %d", &a, &b);/*Scan 2 Integers*/
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("Output = %d", a<<b); /*Output bit_shift_left operation result*/
                /*Free Memory*/
                free(command);
                free(userChoice);
            }
            else if (strcmp(command, "BIT_SHIFT_RIGHT") == 0)
            {
               scanf("%d %d", &a, &b);/*Scan 2 Integers*/
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                printf("Output = %d", a>>b); /*Output bit_shift_right operation result*/
                /*Free Memory*/
                free(command);
                free(userChoice);
            }
            else if (strcmp(command, "RANDOM") == 0) /* Generate Random Sentence Case*/
            {
                /*A for loop to generate 20 random sentences*/
               for (z = 0; z <= 20; z++)
               {
                   generateRandomSentence(); /* Method Call*/
               }
               /* Free Memory*/
                free(command);
                free(userChoice);
                
            }
            
            else if (strcmp(command, "EXIT") == 0)/* Exit Program Case*/
            {
               
                printf("Goodbye...\n");
                /* Free Memory*/
                free(command);
                free(userChoice);
                
                return EXIT_SUCCESS;/* Exit Program */
            }
            else{/* Unknown Command Case*/
                printf("\nError: Unknown action: %s\nTry again...", userChoice);/*Print Error Message*/
            }
        

    } while (exitProgram == 0);/* End-While*/
    
    return EXIT_SUCCESS;/* Exit Program with Sucess */
}/* End-Main*/

/***********************************************************************************************
 * Function Name: generateRandomSentence
 * Purpose: Generate a random sentence.
 * Function In parameters: Nothing
 * Function Out parameters: void  
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/
 
void generateRandomSentence() {
    /* Array containing required articles */
    const char* articles[] = {"the", "a", "one", "some", "any", "about"};
    /* Array containing required nouns */
    const char* nouns[] = {"men", "woman", "dog", "town", "mouse", "car" };
    /* Array containing required verb */
    const char* verbs[] = {"wrote", "barked", "ran", "walked", "clicked"};
    /* Array containing required prepositions */
    const char* prepositions[] = {"to", "from", "at", "over", "under", "on"};
    
    /* Dynamic memory allocation of sentence character array*/
    char *sentence = (char *)calloc(MAX_LENGTH_FOR_SENTENCE, sizeof(char));

    /* Generate random article from array */
    strcat(sentence, articles[rand() % sizeof(articles)/sizeof(articles[0])]); /* Generate random noun from array within acceptable range(Calculate size of array divide by size of element) */
    /* Add to sentence proceeded by whitespace */
    strcat(sentence, " ");
    /* Set first character as an uppercase */
    sentence[0] = toupper(sentence[0]);
    /* Generate random noun from array */
    strcat(sentence, nouns[rand() % sizeof(nouns)/sizeof(nouns[0])]);
     /* Add to sentence proceeded by whitespace */
    strcat(sentence, " ");
    /* Generate random verb from array */
    strcat(sentence, verbs[rand() % sizeof(verbs)/sizeof(verbs[0])]);
     /* Add to sentence proceeded by whitespace */
    strcat(sentence, " ");
    /* Generate random preposition from array */
    strcat(sentence, prepositions[rand() % sizeof(prepositions)/sizeof(prepositions[0])]);
     /* Add to sentence proceeded by whitespace */
    strcat(sentence, " ");
    /* Generate random noun from array */
    strcat(sentence, nouns[rand() % sizeof(nouns)/sizeof(nouns[0])]);
     /* Add to sentence proceeded by whitespace */
    strcat(sentence, ".");
    /* Output sentence */
    printf("%s\n", sentence);

    /* Free Memory */
    free(sentence);
    
}

