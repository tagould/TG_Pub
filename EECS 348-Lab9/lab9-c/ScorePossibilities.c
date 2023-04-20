/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: t813g195
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ScoreCombos(int Score)
{
    int TD_0, TD_1, TD_2, FG, SFT;  // touchdown(6), touchdown with extra point(7), touchdown with 2-point conversion(8), field goal(3), SFTety(1) 
    printf("Possible combinations of scoring plays:\n\n");
    for (TD_2 = 0; TD_2 <= Score / 8; TD_2++)   // checking for touchdowns with 2 pt conversions
    {
        for (TD_1 = 0; TD_1 <= (Score - (8 * TD_2)) / 7; TD_1++)    // checking for touchdowns with extra pt
        {
            for (TD_0 = 0; TD_0 <= (Score - (8 * TD_2) - (7 * TD_1)) / 6; TD_0++)
            {
                for (FG = 0; FG <= (Score - (8 * TD_2) - (7 * TD_1) - (6 * TD_0)) / 3; FG++)
                {
                    for (SFT = 0; SFT <= (Score - (8 * TD_2) - (7 * TD_1) - (6 * TD_0) - (3 * FG)) / 2; SFT++)
                    {
                        int combo = Score - (8 * TD_2) - (7 * TD_1) - (6 * TD_0) - (3 * FG) - (2 * SFT);
                        if (combo == 0)
                        {
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FG, %i Safety\n", TD_2, TD_1, TD_0, FG, SFT);
                        }
                    }
                }
            }
        }    
    }
}


int main()
{
    int stopcode = 1, u_score;

    do
    {
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score:");
        scanf("%i", &u_score);
        if (u_score <= 1)
        {
            stopcode = 0;
            printf("\nGo Chiefs!\n");
        }
        else
        {
            ScoreCombos(u_score);
        }
    } while (stopcode == 1);
    
    

    return 0;
}