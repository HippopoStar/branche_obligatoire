# branche\_obligatoire
La branche commune en attendant de pouvoir choisir un cursus

[Sujet Libft](https://cdn.intra.42.fr/pdf/pdf/1332/libft.fr.pdf)  

Commandes utiles :
- savoir les appels de fonction de la librairie standard :  
	`nm -u <binaire>`
- verifier l'absence d'operateurs en fin de ligne  
	`grep -nR -e '|$' -e '&$' -e ':$' -e '+$' -e '\-$' -e '\*$' -e '/$' -e '%$' -e '=$' ./* | grep -v -e '/\*' -e '\*\*' -e '\*/'`  
	(tel quel on ignore les lignes contenant le motif '**',  
	ce qui permet d'ignorer les commentaires, mais a l'inconvenient facheux  
	d'ignorer egalement les lignes contenant des motifs tels que '(char **)malloc([...]'  
	L'inconvenient vient du fait qu'on ne peut ajouter le meta-caractere '^'  
	pour specifier qu'il ne faut ignorer que les lignes comprenant ce motif  
	en debut de ligne car l'option '-R' dans le premier appel de 'grep'  
	y place le nom du fichier)
- installer un programme :  
	`brew install <program_name>`
- verifier l'absence de fuites memoire :
	- valgrind  
	`valgrind --leak-check=full <./program_name arg1 arg2 ...> [< file_to_send_in_program_entry]`
	- leaks
		- Ajouter un `while (1);` a la fin de la fonction 'main'
		- Dans une 1ere fenetre : `./program_name arg1 arg2 ...`
		- Dans une 2nd fenetre : `ps aux | grep 'program_name' && leaks 'program_name'`
- monitorer l'activite d'un programme :  
	`top -p $(ps aux | awk '/my_program_name/ { print $0 }' | awk '!/awk/ { print $2 }')`
- commande pour afficher l'etat d'un fichier a l'issue de l'etape pre-processeur :  
	`cpp <mon_fichier>.c`
