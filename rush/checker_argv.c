#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_3_5	(char a, char b)//check si une combinaison est entre 3 et 5
{
	if ((a + b) < 3 || (a + b) > 5)
		return 0;
	return 1;
}

int	is_argument_good_format(char *str, int *tab_arg)//check si la string passée en argument est dans le format demandé
{
	int i = 0;

	while (str[i] != '\0')// Compte le nombre de char dans la string
	{
		i++;
	}
	if (i != 31)// si il n y a pas exactement 16 chiffres et 15 espaces dans l'argument
		return 0;
	i = 0;
	while(i < 30)
	{
		if ((str[i] < '1' || str[i] > '4') && str[i] != ' ')//on check si 1 char sur 2 est bien entre 1 et 4
		{
			return 2;
		}
		i++;
		if(str[i] != ' ')// on check si un char sur deux est bien un espace
			return 3;
		i++;
	}
	if (str[i] < '1' || str[i] > '4')//on check le dernier char
		return 4;
	i = 0;
	while (i < 31)//on convertit la string en tab_arg de int
	{
		if (str[i] >= '1' && str[i] <= '4')
			tab_arg[i/2] = str[i] - 48;//on convertit le char en sa version int, et l'affecte dans tab
		else
			return 5;
		i++;
		if (str[i] != ' ' && str[i] != '\0')
			return 6;
		i++;
	}
	
	//on check si toutes les paires( en haut/bas d'une colonne, gauche droite d'une ligne) stocké dans tab_arg font entre 3 et 5
	if(is_3_5(tab_arg[0], tab_arg[4]) && is_3_5(tab_arg[0], tab_arg[4]) && is_3_5(tab_arg[0], tab_arg[4]) && is_3_5(tab_arg[0], tab_arg[4]) 
	&& is_3_5(tab_arg[8], tab_arg[12]) && is_3_5(tab_arg[9], tab_arg[13]) && is_3_5(tab_arg[10], tab_arg[14]) && is_3_5(tab_arg[11], tab_arg[15]))
		return 1;
	else
		return 7;
}

// int	main(void)
// {
// 	char* str = "1 1 1 1 4 4 4 4 1 1 1 1 4 4 4 4";//string de test
// 	int tab_arg[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// 	printf("retour : %i\n", is_argument_good_format(str, tab_arg));
// 	char error_message;
// 	for(int i = 0; i < 16; i++)
// 	{
// 		printf("%i",tab_arg[i]);
// 	}
// 	return 0;
// }

//SYSTEME DE CHECK UP POUR LES ENTREES//
/* il faut verifier si il y a le bon nombre d'argument quand on lance le programme (exemple pour "./a.out argument1 argument2" il y a 3 argument. Le nom du programme, puis ergument1 et argument2, qui seront stocke dans le tableau de string argv[][])
    il faut creer un int main avec argc argv
    il faut verifier si il y a le bon nombre d'argument qui doit etre 2
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
