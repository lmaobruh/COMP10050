/* Software Engineering Assignment 2 by Aayan Atiq (16203115)
Note: Since my group partner dropped out, this program only has limited capabilities.
There are no functionalities related to 'slots' or there implementation in this program.
This is as per instructions given by Dr. Liliana Pasquale */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PlayerSet(int i);
void Attack(int i);

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

char Elf[] = {"Elf"};
char Human[] = {"Human"};
char Ogre[] = {"Ogre"};
char Wizard[] = {"Wizard"};

int main() {
    int n;
    printf("Enter Number of Players (1 - 6): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        PlayerSet(i);
    }
    /* Since I was asked not to include slots, the players are not
    given options asking them what to do. Instead they just attacl */
    for (int i = 0; i < n; i++) {
        Attack(i);
    }
    return 0;
}

void PlayerSet(int i) {
    Player *P;
    P = (int*)malloc(6 * sizeof(P));
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

void Attack(int i) {
    /* Since there are no slots, I'm going to provide code on what to do
    if there are either one or two players nearest to the attacker */

}
