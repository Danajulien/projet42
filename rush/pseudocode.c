

//SYSTEME DE CHECK UP POUR LES ENTREES//
/* il faut verifier si il y a le bon nombre d'argument quand on lance le programme (exemple pour "./a.out argument1 argument2" il y a 3 argument. Le nom du programme, puis ergument1 et argument2, qui seront stocke dans le tableau de string argv[][])
    il faut creer un int main avec argc argv
    il faut verifier si il y a le bon nombre d'argument qui doit etre 17
        si ce n'est pas le cas, on retour le message d'erreur que le rush veut qu on affiche
    
    il faut verifier si tous les arguments entre argv[1] et argv[16] sont des chiffres 
    il faut verifier si ils sont compris entre 1 et 4
    
    il faut trouver une facon de stocker tous ce qui a ete mis en argument en tant que int, dans un tableau ou un tableau de tableau
        il faut parcourir le tableau argv[1][0] -> argv[16][0] et checker 
            pour chacun d'eux on va les convertir depuis un char, en leur version int
            on va stocker ce chiffre dans un tableau ou un tableau de tableau en tant que int
            on parcours ce tableau de int pour voir si ils sont tous entre 1 et 4
            si non , afficher message d'erreur
*/


//SYSTEME DE GENERATION DE GRILLE DE 4x4 CHIFFRES ETANT UNE POTENTIELLE SOLUTION 
/*
il faudrait un systeme de remplissage intelligent qui ne remplisse en premier les case qui sont obligatoirement une valeur
    comment le savoir ? on le sait pour certain cas, comme quand le chiffre clue est 4, 
    on sait que le 1 est forcement au tout debut, puis que ca fait  2 3 4.
    on sait que quqnd le clue est 1, on sait que le 4 est forcement au tout debut
    
    puis apres quand on veut remplir un trou, on regarde si sur la meme ligne 
    ou la meme colonne il y a deja ce chiffre. Si oui on ne le pose pas, et on itere jusqu'au 
    suivant
    on regarde aussi si le chiffre qu on veut poser peut etre poser. exemple, on sait qu on ne 
    peut PAS mettre un 4 en debut de grille si l'indice n'est pas 1

    une fois toute la grille genere, on la teste , mais normalement si on la remplie 
    recursivement en suivant un ordre logique, et les conditions, a la fin on reussi
    obligatoirement a avoir un resultat

*/


//SYSTEME DE CHECK SI UNE GRILLE DE 4x4 CHIFFRE REMPLIE LA CONDITION//
/*
lecture d'une ligne 
*/
