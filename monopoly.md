# CLMP
## Règles
Chaque joueur commence avec 2000 (provisoire)

### Victoire
* possède 4 gares
* possède 3 monopoles
* possède 1 ligne
* les autres joueurs sont en faillite

### Chance
* aller en prison
* sortie de prison (carte conservable)
* recevoir de l'argent (25 de tout le monde)
* perdre de l'argent (100)
* rejouer
* aller à une gare (random)
* aller à une maison (random)
* revente de maison/gare (choisi)
* destruction de maison/gare (random sur un joueur choisi)
* loyer gratuit (carte conservable)
* prochain loyer doublé (carte conservable)
* aller aux impôts
* aller au parc gratuit



### Taxe
Cumule l'argent reçu dans une variable "caisse taxe"

### Parc gratuit
Le joueur prend l'argent stocké dans "caisse taxe"

### Départ
Reçoit une certaine somme (300 provisoire)

### prison
3 tours pour sortir
Possibilité de sortir si:
* utilisation de la carte sortie de prison
* joueur fait un double
* payer amende qui finit dans "caisse taxe" (200 provisoire)
si au bout du 3ème tour le joueur n'a toujours pas fait de double, au prochain
tour, il doit payer l'amende et il peut sortir.

### maison
#### 1er achat
prix initial
#### taxe à payer
0.4 * prix initial (provisoire)
#### rachat/revente maison
1.3 ou 1.4 * prix initial
#### prix monopole
si un joueur possède un monopole (2 villes de la même couleur),
alors les loyers de chaque maison = 2 * 0.4 * prix initial

### gares
#### achat
prix initial
#### taxe
0.4 * prix initial * nombre de gares possédés
#### rachat/revente
pas de rachat mais revente possible (1.3 ou 1.4 * prix initial)
