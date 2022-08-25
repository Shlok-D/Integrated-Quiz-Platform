#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main(){
    struct bank* b;
    initialise_bank(&b);
    //display_status(b);
    int quit = 1, input = 0, i, sc;
    //printf("%s %s %i %i", user->password, user->username, strlen(user->username), strlen(user->password));
    add_questions();
    //display();
    struct user* user;
    user = starting_page(user, b);
    user->password[strcspn(user->password,"\n")] = 0;
    user->username[strcspn(user->username,"\n")] = 0;
    while(quit != 0){
        printf("\n1) Progress Bar\n");
        printf("2) Quiz\n");
        printf("3) Solutions Review\n");
        printf("4) Reset\n");
        printf("5) Quit\n");
        printf("Enter Mode : ");
        scanf("%d",&input);
        if(input == 1){
            display_progress_report(user,b);
        }
        else if(input == 2){
            for(i = 0; i < b->sub;i++){
                printf("%i) %s SC : %i\n",i+1,b->list, b->codes[i]);
            }
            printf("Enter SC of Subject : ");
            scanf("%d",&sc);
            quiz_main(sc, b);
            user = update_user(user,sc,b);
        }
        else if(input == 3){
            solutions_review(user);
        }
        else if(input == 4){
            user = reset(user, b);
        }
        else if(input == 5){
            quit = 0;
        }
        else{
            printf("Enter Valid Input!(1-5)\n");
        }
        // update_user(user, sc, b)
    }
    printf("Thank You for using the Quiz.");
}