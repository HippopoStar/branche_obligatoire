# branche\_obligatoire
La branche commune en attendant de pouvoir choisir un cursus

[Sujet Libft](https://cdn.intra.42.fr/pdf/pdf/1332/libft.fr.pdf)  
('ft\_split' a mettre a jour avec 1 seul appel a 'malloc')  
('get\_next\_line' a ameliorer)  

__GIT__  

Supprimer un depot GitHub :  
'Repositories' -\> Se rendre dans le repertoire concerne -\> Onglet 'Settings'  
Faire revenir un fichier a l'etat d'un commit en arriere (commit le changement automatiquement) :  
`git checkout master~1 <file>`  

__Reglages terminal__  

Polices d'ecriture pour le terminal :  
	Andale Mono  
	Arial Unicode MS  
	Avenir  
	Avenir Next  
	Cochin  
	Courier  
	Courier New (+) - small  
	Geneva (+) - tall  
	Georgia (+) - tall  
	Gill Sans  
	Helvetica Neue  
	Hoefler Text  
	Lucida Grande (+) - tall  
	Menio (+) - small  
	Microsoft Sans Serif (+) - tall  
	Monaco (Default)  
	Optima (+) - tall  
	Palatino  
	PT Mono (+) - small  
	Skia  
	STIXGeneral  
	Tahoma (+) - tall  
	Times  
	Trebuchet MS (+) - tall  
	Verdana (+) - tall  
	Apple Symbols (+) - small  

Couleur arriere-plan :  
	255 255 191=127+64  

Couleur caracteres :  
	95=63+32 95=63+32 127  

Curseur :  
	[✓] Underline [ ] Vertical bar [ ] Box

Preferences/Profiles/Text/Text\_Rendering : Draw\_bold\_text\_in\_bold\_font [ ]  
Preferences/Profiles/Window/Settings\_for\_New\_Windows :  Columns [84] Rows [50]  

__Reglages Vim__ :  

~/.vimrc :
```
	" use 4 spaces for tabs
	set tabstop=4
	set softtabstop=4
	set shiftwidth=4
```

```
	" View
	" set cursorline
	set number
	set mouse=a
	set colorcolumn=80
```

```
	" The color theme
	" colorsscheme maui
```

Plugin header :  
	cat /usr/share/vim/vim80/plugin/stdheader.vim  
	<https://www.vim.org/docs.php>  
	<http://vimdoc.sourceforge.net/>  
	<http://vimdoc.sourceforge.net/htmldoc/usr_toc.html>  
	<http://vimdoc.sourceforge.net/htmldoc/usr_41.html#script>  

__Commandes utiles__ :  

- [Tutoriel : Des couleurs dans la console (Linux)](http://sdz.tdct.org/sdz/des-couleurs-dans-la-console-linux.html)  
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
	- Avec 'top' :  
	`top -p $(ps aux | awk '/my_program_name/ { print $0 }' | awk '!/awk/ { print $2 }')`
	- Avec 'ps' :  
	`ps aux | awk 'NR == 1 { print $0 } ; /lem-in/ && !/awk/ { print $0 }'`
- commande pour afficher l'etat d'un fichier a l'issue de l'etape pre-processeur :  
	`cpp <mon_fichier>.c`
- telecharger un fichier depuis un URL  
	`curl -o <output_file> <URL>`


__Makefile(s)__ :  

pour compiler avec les flags 'sanitize', ajouter :  

```
	CFLAGS +=	-01 -g -fsanitize=adress \
			-fno-omit-frame-pointer \
			-fsanitize-adress-use-after-scope
```

pour ajouter la regle 'analyser' :  

```
	analyzer:
		gcc -fsyntax-only $(CFLAGS) $(CPPFLAGS) $(SRC)
		gcc --analyze $(CFLAGS) $(CPPFLAGS) $(SRC)
	[...]
	.PHONY: [...] analyzer
```

creer une librairie a partir de fichiers objets et d'une autre librairie :  
		`libtool -static -o $(NAME) $(OBJS) ./libft/libft.a`  
		`ranlib -f $(NAME)`  

