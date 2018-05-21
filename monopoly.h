#ifndef _MONOPOLY_H_
# define _MONOPOLY_H_

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "gui.h"
# include "utils.h"

# define MONEY_START        1000
# define MONEY_TURN_REWARD  200
# define MONEY_TAX          200
# define TIME_PRISON        3

case_t CASES[] = {
    {(char *)"Depart", 0, TYPE_START, 0, 0, 0},
    {(char *)"Belleville", 0, TYPE_STREET, -1, 60, 60},
    {(char *)"Lecourbe", 0, TYPE_STREET, -1, 60, 60},
    {(char *)"Impots",0,TYPE_TAX, 0, 200, 200 },
    {(char *)"Montparnasse", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Vaugirard", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Courcelles", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Prison", 0, TYPE_PRISON, 0, 0, 0},
    {(char *)"La Vilette", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"Neuilly", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"de Lyon", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Mozart", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Saint-Michel", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Pigalle", 3, TYPE_STREET, -1, 200, 200},
    {(char *)"Parc Gratuit", 0, TYPE_PARK, 0, 0, 0},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Henri-Martin", 4, TYPE_STREET, -1, 240, 240},
    {(char *)"du Nord", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Saint-Honore", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"La Bourse", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"Go prison", 0, TYPE_GOPRISON, 0, 0, 0},
    {(char *)"Breteuil", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Foch", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Saint-Lazare", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Champs-Elysees", 7, TYPE_STREET, -1, 350, 350},
    {(char *)"Taxe de Luxe", 0, TYPE_TAX, -1, 200, 200},
    {(char *)"La Paix", 7, TYPE_STREET, -1, 400, 400},

};

void card_prison(int);
void card_prize(int);

chance_t CHANCE[] = {
   {(char *)"Prison", (char *)"Vous allez en prison.", 0, card_prison, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 100, card_prize, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 300, card_prize, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 1000, card_prize, 0},
   {(char *)"amende", 0},
   {(char *)"rejouer", 0},
   {(char *)"gare", 0},
   {(char *)"rue", 0},
   {(char *)"destruction", 0},
   {(char *)"impots", 0},
   {(char *)"parc gratuit", 0},
   {(char *)"sortie de prison", 1},
   {(char *)"loyer gratuit", 1},
   {(char *)"prochain loyer double", 1}
 };

#endif /* _MONOPOLY_H_ */
