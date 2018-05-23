#ifndef _MONOPOLY_H_
# define _MONOPOLY_H_

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "gui.h"
# include "utils.h"
# include "card_effects.h"
# include "constants.h"

/* 
case_t CASES[] = {
    {(char *)"Depart", 0, TYPE_START, -1, 0, 0},
    {(char *)"Belleville", 0, TYPE_STREET, -1, 60, 60},
    {(char *)"Lecourbe", 0, TYPE_STREET, -1, 60, 60},
    {(char *)"Impots", 0, TYPE_TAX, -1, 200, 200 },
    {(char *)"Montparnasse", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Vaugirard", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Courcelles", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Prison", 0, TYPE_PRISON, -1, 0, 0},
    {(char *)"La Vilette", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"Neuilly", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"de Lyon", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Mozart", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Saint-Michel", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Pigalle", 3, TYPE_STREET, -1, 200, 200},
    {(char *)"Parc Gratuit", 0, TYPE_PARK, -1, 0, 0},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Henri-Martin", 4, TYPE_STREET, -1, 240, 240},
    {(char *)"du Nord", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Saint-Honore", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"La Bourse", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"Go prison", 0, TYPE_GOPRISON, -1, 0, 0},
    {(char *)"Breteuil", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Foch", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Saint-Lazare", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Champs-Elysees", 7, TYPE_STREET, -1, 350, 350},
    {(char *)"Taxe de Luxe", 0, TYPE_TAX, -1, 200, 200},
    {(char *)"La Paix", 7, TYPE_STREET, -1, 400, 400}
};
*/
case_t CASES[] = {
    {(char *)"Depart", 0, TYPE_START, -1, 0, 0},
    {(char *)"Belleville", 0, TYPE_STREET, 1, 60, 60},
    {(char *)"Lecourbe", 0, TYPE_STREET, 1, 60, 60},
    {(char *)"Impots", 0, TYPE_TAX, -1, 200, 200 },
    {(char *)"Montparnasse", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Vaugirard", 1, TYPE_STREET, 1, 100, 100},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Courcelles", 1, TYPE_STREET, 1, 100, 100},
    {(char *)"Prison", 0, TYPE_PRISON, -1, 0, 0},
    {(char *)"La Vilette", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"Neuilly", 2, TYPE_STREET, -1, 140, 140},
    {(char *)"de Lyon", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Mozart", 3, TYPE_STREET, 1, 180, 180},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Saint-Michel", 3, TYPE_STREET, 1, 180, 180},
    {(char *)"Pigalle", 3, TYPE_STREET, 1, 200, 200},
    {(char *)"Parc Gratuit", 0, TYPE_PARK, -1, 0, 0},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Henri-Martin", 4, TYPE_STREET, -1, 240, 240},
    {(char *)"du Nord", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Saint-Honore", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"La Bourse", 5, TYPE_STREET, -1, 260, 260},
    {(char *)"Go prison", 0, TYPE_GOPRISON, -1, 0, 0},
    {(char *)"Breteuil", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Foch", 6, TYPE_STREET, -1, 300, 300},
    {(char *)"Saint-Lazare", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Champs-Elysees", 7, TYPE_STREET, -1, 350, 350},
    {(char *)"Taxe de Luxe", 0, TYPE_TAX, -1, 200, 200},
    {(char *)"La Paix", 7, TYPE_STREET, -1, 400, 400}
};


card_t CARDS[] = {
   {(char *)"Prison", (char *)"Vous allez en prison.", 0, card_prison},
   {(char *)"Prison", (char *)"Vous allez en prison.", 0, card_prison},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 500, card_prize},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 1000, card_prize},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 2000, card_prize},
   {(char *)"Amende", (char *)"Vous recevez une amende.", 100,  card_tax},
   {(char *)"Amende", (char *)"Vous recevez une amende.", 200,  card_tax},
   {(char *)"Amende", (char *)"Vous recevez une amende.", 500,  card_tax},
   {(char *)"Rejouer", (char *)"Vous pouvez rejouez.", 0,  card_replay},
   {(char *)"Rejouer", (char *)"Vous pouvez rejouez.", 0,  card_replay},
   {(char *)"Rejouer", (char *)"Vous pouvez rejouez.", 0,  card_replay},
   {(char *)"Gare", (char *)"On vous depose a la gare.",  0,  card_station},
   {(char *)"Gare", (char *)"On vous depose a la gare.",  0,  card_station},
   {(char *)"Gare", (char *)"On vous depose a la gare.",  0,  card_station},
   {(char *)"Rue&Gare", (char *)"On vous depose dans une rue.", 0,  card_street_station},
   {(char *)"Rue&Gare", (char *)"On vous depose dans une rue.", 0,  card_street_station},
   {(char *)"Rue&Gare", (char *)"On vous depose dans une rue.", 0,  card_street_station},
   {(char *)"Destruction", (char *)"Une rue ou gare va etre reinitialise.",  0, card_destroy},
   {(char *)"Parc gratuit", (char *)"On vous depose au parc gratuit.", 0, card_parc},
};

#define CARD_COUNT  (sizeof(CARDS)/sizeof(card_t))

int SHUFFLED_CARDS[CARD_COUNT];

#endif /* _MONOPOLY_H_ */
