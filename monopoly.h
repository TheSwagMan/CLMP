#ifndef _MONOPOLY_H_
# define _MONOPOLY_H_

# include <stdio.h>
# include "gui.h"

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
    {(char *)"Gare de Lyon", 8, TYPE_STATION, -1, 200, 200},
    {(char *)"Mozart", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Saint-Michel", 3, TYPE_STREET, -1, 180, 180},
    {(char *)"Pigalle", 3, TYPE_STREET, -1, 200, 200},
    {(char *)"Parc Gratuit", 0, TYPE_PARK, 0, 0, 0},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Chance", 0, TYPE_LUCKY, -1, 0, 0},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 220, 220},
    {(char *)"Henri-Martin", 4, TYPE_STREET, -1, 240, 240},
    {(char *)"Gare du Nord", 8, TYPE_STATION, -1, 200, 200},
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
chance_t chance[] = {
   {(char *)"prison",0,0};
   {(char *)"cadeaux",0,1};
   {(char *)"amende",0,2};
   {(char *)"rejouer",0,3};
   {(char *)"gare",0,4};
   {(char *)"rue",0,5};
   {(char *)"destruction",0,6};
   {(char *)"impots",0,7};
   {(char *)"parc gratuit",0,8};
   {(char *)"sortie de prison",1,9};
   {(char *)"loyer gratuit",1,10};
   {(char *)"prochain loyer doublé",1,11}
 };

#endif /* _MONOPOLY_H_ */
