/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:33:45 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/13 22:03:59 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

/*
	je veux convertir un nombre N d'une base B1 en en nombre en base B2 le tout ecrit en charactere

		je dois savoir combien de chiffres j'ai besoin pour ecrire le nombre de B2
		j ai besoin de 4 chiffre d une base 2 pour en faire un d une base 16. surrement car 2/\4 = 16. mais comment faire l'inverse ?
			est ce que je fais une boucle de 2 * lui meme x nombre de fois,
				et une fois que le resultat >= 16,
				je retourne x qui sera un nombre de chiffre suffisante pour ecrire un chiffre en b1
				-> en b2 ?
			i = 1
			resultat = strlen(b1)
			while (result < strlen(b2))
			{
				result *= base
				i++
			}
				la je vais avoir besoin de 1 x nombre en b1 pour faire en b2

			sinon
			nbr_b1 /= nbr_b2
			while (nbr_b1 > 0 )
			{
				nbr_b1 /= nombre_b2
			}
*/