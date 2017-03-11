/* Software Engineering Assignment 2 by Aayan Atiq (16203115)
 Note: Since my group partner dropped out, this program only has limited capabilities.
 There are no functionalities related to 'slots' or there implementation in this program.
 This is as per instructions given by Dr. Liliana Pasquale */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Player {
    float life;
    int smart;
    int magic;
    int strength;
    int dexterity;
    int luck;
    char playerType[10];
    char playerName[50];
}Player;
//this struct stores and keeps track of each player's info

void PlayerSet(int i, struct Player *P);
void Attack(int i, int n, struct Player *P);
void print(int n, struct Player *P);

char Elf[] = {"Elf"};
char Human[] = {"Human"};
char Ogre[] = {"Ogre"};
char Wizard[] = {"Wizard"};
//player Types

int main() {
    int n;
    printf("Enter Number of Players (1 - 6): ");
    scanf("%d", &n);
    Player *P;
    P = (int*)malloc(n * sizeof(P));
    for (int i = 0; i < n; i++) {
        PlayerSet(i, P);
    }
    /* Since I was asked not to include slots, the players are not
     given options asking them what to do. Instead they just attack */
    for (int i = 0; i < n; i++) {
        Attack(i, n, P);
    }
    print(n, P);
    //for printing the status of the game
    return 0;
}

void PlayerSet(int i, struct Player *P) {

    char c;
    printf("Enter Player %d Type:\nA: Elf\nB: Human\nC: Ogre\nD: Wizard\n", i+1);
    scanf("%s", &c);
    if (c == 'a' || c == 'A') strcpy(P[i].playerType , Elf);

    if(c == 'b' || c == 'B') strcpy(P[i].playerType , Human);

    if(c == 'c' || c == 'C') strcpy(P[i].playerType , Ogre);

    if(c == 'd' || c == 'D') strcpy(P[i].playerType , Wizard);
    //player type

    printf("Enter Player %d Name: ", i+1);
    scanf("%s", P[i].playerName);

    P[i].life = 100.00;
    //initializing life points to 100
    int total = 0;
    srand(time(NULL));
    /* The following code generates the various skill points of the players based
     on their types and the rules provided to us */

    if(strcmp(Human , P[i].playerType) == 0) {

        do {
            P[i].smart = 1 + rand()%100;
            P[i].strength = 1 + rand()%(100);
            P[i].magic = 1 + rand()%(100);
            P[i].luck = 1 + rand()%(100);
            P[i].dexterity = 1 + rand()%(100);
            total = P[i].smart + P[i].strength + P[i].magic + P[i].luck + P[i].dexterity;

        } while(total > 299);
    }

    if(strcmp(Ogre , P[i].playerType) == 0) {

        P[i].magic = 0;
        P[i].strength = rand()%(100 +1 -80)+80 ;
        P[i].dexterity = rand()%(100 +1 -80)+80;

        do {
            P[i].smart = rand()%20;
            P[i].luck = rand()%50;
            total = P[i].smart + (int)P[i].luck;
        } while(total > 49);
    }

    if(strcmp(Elf, P[i].playerType)==0) {

        P[i].luck = rand()%(100 +1 -60)+60;
        P[i].smart = rand()%(100 +1 -70)+7;
        P[i].strength = rand()%(50 +1 -1)+1;
        P[i].magic = rand()%(79 +1 -51)+51;
        P[i].dexterity=rand()%100 +1;
    }

    if(strcmp (Wizard, P[i].playerType)==0) {

        P[i].luck = rand()%(100 +1 -50)+50;
        P[i].smart =rand()%(100 +1 -90)+90;
        P[i].strength = rand()%(20 +1 -1)+1;
        P[i].magic = rand()%(100 +1 -80)+1;
        P[i].dexterity = rand()%100;
    }
}

void Attack(int i, int n, struct Player *P) {
    /* I was asked to implement attacks without placing players on slots.
     Since there are no slots, I'm going to provide code on what to do
     if there are either one or two players nearest to the attacker
     which are randomly selected */
    srand(time(NULL));

    int random1, random2;
    do {
        random1 = 1 + rand() % n;
    } while(random1 != i);

    if (n == 2) { //only two players
        if(P[random1].strength <= 70) {
            P[random1].life -= (0.5*P[random1].strength);
        }
        else {
            P[i].life -= (0.3*P[random1].strength);
        }
        //the above code chooses a random index and attacks the player stored at the index
    }

    if (n > 2) { //more than two players
        do {
            random2 = 1 + rand() % n;
        } while(random2 != i);

        printf("Two players are at equal proximity. Choose which player to attack:\n"
               "A: Name: %s\tType: %s\nB: Name: %s\tType: %s"
               , P[random1].playerName, P[random1].playerType
               , P[random2].playerName, P[random2].playerType);

        char c;
        c = getchar();

        if(c == 'a' || c == 'A') {
            if(P[random1].strength <= 70) {
                P[random1].life -= (0.5*P[random1].strength);
            }
            else {
                P[i].life -= (0.3*P[random1].strength);
            }
        }

        else if(c == 'b' || c == 'B') {
            if(P[random2].strength <= 70) {
                P[random2].life -= (0.5*P[random2].strength);
            }
            else {
                P[i].life -= (0.3*P[random2].strength);
            }
        }
    }
    //the above code chooses two random indices and asks the player whom to attack

}

void print(int n, struct Player *P) {
    for(int i = 0; i < n; i++)
    {
        printf("%s (%s, %.2f)\n", P[i].playerName, P[i].playerType, P[i].life);
    }
}
