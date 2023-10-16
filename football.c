/*
Ky Jost 
3070792
EECS 348 Lab 5 
14 October 2023
This program prompts the user for a football score and returns the possible scoring combinations. 
*/

#include <stdio.h>

int main() {
    //This section of the code gets the score from the user
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    int score;
    scanf("%d", &score);

    //This determines if the score is 0 or 1 
    if (score == 0 | score == 1) {
        //If it is, the program prints "STOP" and nothing else 
        printf("\nSTOP\n");
    } else {
        //This prints the first line 
        printf("\nPossible combinations of scoring plays: \n"); 
        //if it isn't, we get to the rest of the code 
        //This sets up the temproary score
        //It also sets up variables for each possible scoring play 
        int tempScore = score;
        int twoP = 0;
        int tdFG = 0;
        int td = 0;
        int FG = 0;
        int safety = 0;
        
        //This determines how many of each play could happen for the score 
        //It's the max amount each scoring play could have 
        //These aren't exact numbers, but I use them to from the loops 
        int safeNum = score/2; 
        int fieldNum = score/3; 
        int touchNum = score/6; 
        int touchFieldNum = score / 7; 
        int touch2Num = score/8; 

        //These are the loops that make up the actual decision making process 
        //Basically, I'm iterating through every possible scoring combination 
        //It starts with everything at 0, and iterates until everything is at its max 
        //This gives us way more combinations than we need 
        while(safety <= safeNum) {
            while(FG <= fieldNum) {
                while(td <= touchNum) {
                    while(tdFG <= touchFieldNum) {
                        while(twoP <= touch2Num) {
                            //This solves the problem of way too many combinations 
                            //These variables represent the point value of each scoring play 
                            int safeScore = safety*2; 
                            int fieldScore = FG*3; 
                            int touchScore = td*6; 
                            int touchFieldScore = tdFG*7; 
                            int touch2Score = twoP*8; 
                            //This gives us the score from a given combination of scoring plays
                            tempScore = safeScore + fieldScore + touchScore + touchFieldScore + touch2Score;
                            //If that set of scoring plays produces the score, it prints it out 
                            if (tempScore == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", twoP, tdFG, td, FG, safety);
                            }
                            //All these variable iterations are used to control the loops 
                            twoP++; 
                        }
                        twoP = 0; 
                        tdFG++; 
                    }
                    tdFG = 0; 
                    td++; 
                }
                td = 0; 
                FG++; 
            }
            FG = 0; 
            safety++; 
        }
    }
}

/*MORE INFO ON FOR LOOPS: 
I'm not sure if my comments earlier explain things the best, so I'm trying again. 
The for loops iterate through every scoring combination, starting at 0, 0, 0, 0, 0. 
It ends at the values given by the "num" variables. 
Each iteration through the loops, the combination is checked against the score. 
If that combination matches the score, it prints. 
If it doesn't match the score, the loop iterates again. */