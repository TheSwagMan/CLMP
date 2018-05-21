#ifndef _MONOPOLY_H_
# define _MONOPOLY_H_

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "gui.h"
# include "utils.h"
# include "card_effects.h"
# include "constants.h"

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
    {(char *)"La Paix", 7, TYPE_STREET, -1, 400, 400}

};

chance_t CHANCE[] = {
   {(char *)"Prison", (char *)"Vous allez en prison.", 0, card_prison, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 100, card_prize, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 300, card_prize, 0},
   {(char *)"Cadeaux", (char *)"On vous offre un cadeau.", 1000, card_prize, 0}
   {(char *)"Amende", (char *)"Vous recevez une amende.", 200,  card_prize, 0},

   {(char *)"Rejouer",  (char *)"Vous pouvez rejouez.", 0,  card_replay, 0},
   {(char *)"Gare", (char *)"On vous dépose à la gare.",  0,  card_station, 0},
   {(char *)"Rue&Gare",  (char *)"On vous dépose dans une rue.", 0,  card_street_station, 0},
   {(char *)"Destruction",  (char *)"Une rue ou gare va être réinitialisé.",  0,  card_restart 0},
   {(char *)"Impots", (char *)"Vous devez payer vos impôts.",  0,  card_tax, 0},
   {(char *)"Parc gratuit", (char *)"On vous dépose au parc gratuit.", 0, card_park, 0},
   {(char *)"Sortie de prison", (char *)"On vous donne un moyen de vous évadez de prison.",  0, card_escape, 1},
   {(char *)"Loyer gratuit",  (char *)"Votre prochain loyer sera gratuit." ,  0,  card_free, 1},
   {(char *)"Prochain loyer double",  (char *)"Votre prochain loyer sera doublé.", 0, card_double, 1}

};

#endif /* _MONOPOLY_H_ */
