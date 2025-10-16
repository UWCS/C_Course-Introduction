#include <stdio.h>
#include <string.h>

struct Player {
    int health;
    int level;

    char name[20];
    int inventory[5];
};

char items[3][20] = {
    "A spear",
    "Spoon",
    "Potion"
};

static int maxHealth = 20; // (static variables don't change)

struct Player myPlayer; // declare the struct

// you don't have to understand how this function works at all
int requestInteger(char* str){
    int d; 
    int n = 0;

    while(n == 0){ // keep asking until we get 1 replacement!
        printf("%s", str);
        n = scanf("%d", &d);

        if(n == 0){
            scanf("%*s"); // we don't need to provide a pointer to a string, if it just discards it!
        }
    }

    printf("\n"); 

    return d;
}

void printInfo(){
    printf("===%s's stats===\n", myPlayer.name);

    printf("Hp: %d/%d\n", myPlayer.health, maxHealth);
    printf("Level: %d\n\n", myPlayer.level);

    /*  
        FILL IN CODE TO PRINT OUT INVENTORY
    */

    printf("\n\n");
}

void initialPlayerData(){
    myPlayer.health = maxHealth;
    myPlayer.level = 1;

    strcpy(myPlayer.name, "Springle");

    for (int i = 0; i < 5; i++){
        myPlayer.inventory[i] = 0;
    }
}

int main(){
    initialPlayerData();

    while(1){
        printf("You are %s, and you can:\n\n", myPlayer.name);

        printf("1 - Gain a level\n");
        printf("2 - Print your data\n");
        
        int option = requestInteger("What do you want to do:\n");

        if(option == 1){
            printf("cool! You gained a level\n");
            myPlayer.level += 1;
        }else if (option == 2){
            printInfo();
        }
    }

    return 0;
}