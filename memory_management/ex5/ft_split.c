/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:06:32 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/13 22:53:35 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_seperation(char c, char *separation)
{
    int i;

    i = 0;
    while(separation[i])
    {
        if (c == separation[i])
            return (1);
        i++;
    }
    return (0);
}
int word_count(char *phrase, char *separateur)
{
    int i;
    int words;

    i = 0;
    words = 0;
    while(phrase[i])
    {
        if (i != 0 && is_seperation(phrase[i], separateur) && !(is_seperation(phrase[i - 1], separateur))
        || ((phrase[i + 1] == '\0') && !(is_seperation(phrase[i], separateur)))) 
        {
            words++;
            i++;
        }
        else
            i++;
    }
    return words;
}

char **ft_split(char *str, char *charset)
{
    
}

int main(void)
{
    char *phrase = "caca prout zizi   s ";
    char separateurs[3] = {' ', '\n', '\0'};
    char b;
    b = ' ';
    printf("%i", is_seperation(b, separateurs));
    printf("%i", word_count(phrase, separateurs));
    return 0;
}

/*
fonction is separateur (char c , char* seperateurs)
    je dois prendre un charactere c
    je dois le comparer un a un a tous les character de la chaine separateur
    si le character est egal a un separateur , return 1
    apres avoir parcourru toute la chaine, je return 0 car le charactere ne correspondait a aucun char separateur

    creer compteur de lettre dans le mot actuel
    creer compteur de mot 
    je dois parcourir une premiere fois la string pour compter le nombre de mot 
        je compare le caractere actuel pour voir si c est un separateur
            si oui ET que le precedent n'etait pas un separateur ou qu on est a la fin de la string
                compteur de mot ++
                i++
            si non oui que le char precedent est un separateur
                i++
        i est le nombre de mot dans la string
    
    je cree un tableau de tableau de taille i, donc je fait tableau[][] = malloc(i * sizeof(char*))
    creer un compteur de nombre de mot 
    creer un compteur de nombre de lettre dans le mot actuel
    comteur i pour parcourir la string 
    je dois parcourir la chaine str charactere par charactere
        je dois regarder si le character actuel est un character separateur 
            si oui je dois creer un char mot* malloc de la taille du mot jusqu a present
*/