/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conform_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:47:45 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/16 17:31:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** "match_that_piece" prend en argument :
** 1. le file_descriptor du fichier "[PROTECT]conform_forms"
** 2. la grille contenant la piece dont on souhaite vérifier la conformite
** 3. un buffer de taille 21, present uniquement pour permettre de
**    recuperer la valeur de retour de read
**
** dans le corps de la fonction sont declarees les variables :
** 1. total_read -> permet de stocker la somme des valeurs de retour de read
**                  (ainsi l'etat de l'avancement dans la grille)
** 2. c          -> stock le caractere en cours d'evaluation dans la grille
** 3. i          -> index de parcours des lignes
** 4. j          -> index de parcours des colonnes
**
** - L'algorithme parcoure caractere par caractere la grille contenant la
**   piece dont on doit verifier la conformite.
** - Parallelement, elle lit caractere par caractere la grille du fichier
**   [PROTECT]conform_forms contenant la piece dont on souhaite checker la
**   correspondance avec celle dans "one_piece".
** - Etant donne le pre-traitement de "one_piece", la grille contenant la
**   piece est constituee exclusivement de points et de lettres de l'alphabet,
**   et la piece est placee en haut a gauche de la grille.
** - Ainsi, compte tenu du pre-taitement, il est suffisant de verifier la
**   correspondance entre les points des 2 grilles pour verifier la
**   correspondance entre les 2 pieces.
** - Des lors qu'une divergence est constatee, l'algorithme va lire les
**   caracteres suivants jusqu'au debut de la grille contenant la piece
**   suivante, afin de preparer le prochain appel de la fonction, et renvoyer
**   la valeur '0'.
** - En cas de correspondance, l'algorithme va renvoyer la valeur '1'.
**
** - Notez que l'on ne compare pas les '\n' a la fin de chaque ligne,
**   car c'est rendu obsolete par "fill_line" (dans "main_fillit.c").
*/

int		match_that_piece(int fd, char **one_piece, char *read_buf, int total_r)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (read(fd, &c, 1) != 1)
				error_code("error\n");
			total_r++;
			if (c == '.' && c != *(*(one_piece + i) + j))
			{
				if (read(fd, read_buf, (20 - total_r)) != (20 - total_r))
					error_code("error\n");
				return (0);
			}
		}
		if (read(fd, read_buf, 1) != 1)
			error_code("error\n");
		total_r++;
	}
	return (1);
}

/*
** - "match_a_piece" a pour role de rappeler "match_that_piece" pour
**   chaque grille de [PROTECT]conform_forms, jusqu'a ce qu'une correspondance
**   soit trouvee ou qu'on ait parcouru l'ensemble du fichier repertoriant
**   les grilles valides sans trouver de correspondance.
** - En fait, son foctionnenment repose sur le fait qu'elle est chargee de
**   lire la ligne vide presente entre chaque grille de [PROTECT]conform_forms.
** - Ainsi, le cas d'une piece n'etant pas conforme se traduit par un appel
**   de "match_a_piece" avec la valeur de "read_value" differente de 1,
**   car cela signifie de l'echec de read a lire la ligne vide,
**   soit la fin du fichier [PROTECT]conform_forms.
** - Par ailleurs, elle clot [PROTECT]conform_forms entre chaque piece du
**   fichier d'entree de "fillit" dont on doit verifier la conformite.
*/

int		match_a_piece(int fd, char **one_piece, int read_value, char *read_buf)
{
	if (read_value != 1)
	{
		close(fd);
		return (0);
	}
	else if (match_that_piece(fd, one_piece, read_buf, 0))
	{
		close(fd);
		return (1);
	}
	else
	{
		read_value = read(fd, read_buf, 1);
		return (match_a_piece(fd, one_piece, read_value, read_buf));
	}
}

int		conform_one_piece(char **one_piece, char *read_buf)
{
	int		fd;

	if ((fd = open("[PROTECT]conform_forms", O_RDONLY)) == -1)
		error_code("error\n");
	return (match_a_piece(fd, one_piece, 1, read_buf));
}

int		conform_piece_i(char ***piece_i, char *read_buf)
{
	if (*piece_i == NULL)
	{
		free(read_buf);
		return (1);
	}
	else
	{
		return (conform_one_piece(*piece_i, read_buf) &&\
				conform_piece_i((piece_i + 1), read_buf));
	}
}

int		conform_pieces(char ***pieces)
{
	char	*read_buf;

	if (!(read_buf = (char *)malloc((20 + 1) * sizeof(char))))
		return (0);
	*(read_buf + 20) = '\0';
	return (conform_piece_i((pieces + 0), read_buf));
}
