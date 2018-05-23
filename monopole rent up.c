#include "monopoly.h"

//Monopole fait monter le loyer par 2
void rent_up(board_t *board)
{
  int player_number = board->current_player;
  int i;
  int mono1 = 0;
  int mono2 = 0;
  int mono3 = 0;
  int mono4 = 0;
  int mono5 = 0;
  int mono6 = 0;
  int mono7 = 0;

//Teste l'appartenance des cases au joueur
  for(i = 0; i < CASE_COUNT; i++)
  {
      if (board->cases[i].owner == player_number && board->cases->category == 1)
      {
        mono1 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 2)
      {
        mono2 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 3)
      {
        mono3 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 4)
      {
        mono4 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 5)
      {
        mono5 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 6)
      {
        mono6 += 1;
      }
      if (board->cases[i].owner == player_number && board->cases->category == 7)
      {
        mono7 += 1;
      }
      i++;
  }
  
//Un monopole = 2 cases de même catégorie
  if(mono1 == 2)
  {
    for(board->cases->category = 1)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono2 == 2)
  {
    for(board->cases->category = )
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono3 == 2)
  {
    for(board->cases->category = 3)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono4 == 2)
  {
    for(board->cases->category = 4)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono5 == 2)
  {
    for(board->cases->category = 5)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono6 == 2)
  {
    for(board->cases->category = 6)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }
  if(mono7 == 2)
  {
    for(board->cases->category = 7)
    {
      board->cases->price = 2*(board->cases->price);
    }
  }  
}
