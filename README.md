# branche\_obligatoire
La branche commune en attendant de pouvoir choisir un cursus

Commandes utiles :
- savoir les appels de fonction de la librairie standard : `nm -u <binaire>`
- verifier l'absence d'operateurs en fin de ligne  
	`grep -R -e '|$' -e '&$' -e ':$' -e '+$' -e '\-$' -e '\*$' -e '/$' -e '%$' -e '=$' ./* | grep -v -e '/\*' -e '\*\*' -e '\*/'`
- installer un programme : `brew install program_name`
- verifier l'absence de fuites memoire :
	- valgrind `valgrind --leak-check=full ./program_name arg1 arg2 ...` (fonctionnement similaire a `time`)
	- leaks
		- Ajouter un `while (1);` a la fin de la fonction 'main'
		- Dans une 1ere fenetre : `./program_name arg1 arg2 ...`
		- Dans une 2nd fenetre : `ps aux | grep 'program_name' && leaks 'program_name'`

