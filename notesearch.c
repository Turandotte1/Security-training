#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define	FILENAME "/var/notes"

/*
	Lecture et affichage des donnees, ecrits SEULEMENT pas l'utilisateur qui
	execute le programme, avec un command-line argument pour afficher seulement
	les donnes qui correspond a la chaine passee en argument
*/

int 	search_user_note(char *note, char *search)
{
	int i;
	int length;
	int match;

	i = 0;
	match = 0;
	length = strlen(search);
	if (length == 0)				//si pas de precision de donnes recherche la fonction renvoie toijours 1
		return (1);
	while (i < strlen(note))
	{
		if (*(note+i) == *(search+i))
			match++;
		else
		{
			if (*(note+i) == *(search + 0))   //si pas de match au debut commencer a comter a partir de cet endroit
				match = 1;
			else
				match = 0;
		}
		i++;
	}
	if (match == length)
			return (1);
	return (0);
}

int 	find_user_note(int fd, int uid) //cherche la note suivante d'utilisateur et retourne
{										// la longeur de la note trouvee
	int 			note_uid = -1;
	int 			length;
	unsigned char	byte;

	while (note_uid != uid)
	{
		if (read(fd, &note_uid, 4) != 4)  //lecture de uid des donnes
			return(-1);
		if (read(fd, &byte, 1) != 1) //lecture de newline
			return(-1);
		byte = length = 0;
		while (byte != '\n')  //pour savoir combien d'octet jusqu'a la fin de la ligne
		{
			if(read(fd, &byte, 1) != 1)
				return(-1);
			length++;
		}
	}
	lseek(fd, length * -1, SEEK_CUR); //remonter file en lisant length byte
	return (length);
}

int 	print_notes(int fd, int uid, char *search) //afficher les donnes d'utilisateur avec UID correpondant																 
{													//a la chaine passe en argument en ligne de commande 
	int 	length;
	char	byte;
	char 	buffer[100];

	byte = 0;
	length = find_user_note(fd, uid);
	if (length == -1)
		return (0);
	read(fd, buffer, length);
	buffer[length] = '\0';
	if(search_user_note(buffer, search))
		printf(buffer);
	return (1);
}

int		main(int ac, char **av)
{
	int 	userid;
	int 	printing;
	int 	fd;
	char	search[100];	

	printing = 1;
	if (ac > 1)
		strcpy(search, av[1]);		//pas de protection de user input!!
	else
		search[0] = '\0';

	userid = getuid();
	fd = open(FILENAME, O_RDONLY);  //open 'notes' seulement pour la lecture
	if (fd == -1)
		fatal("in main --> failed open a file for reading");
	while(printing)
		printing = print_notes(fd, userid, search);
	printf("-----------[ end of note ] -----------\n");
	close(fd);
}