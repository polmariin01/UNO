# UNO
Projecte de FO, grup 13

Integrants del grup:
	- Gil Boleda i Feliu
	- Eudald Brils Creus
	- Pol Marin Gargallo

Implementacions del programa:
	- Pots tirar una carta quan el numero i/o el color de la carta que vols tirar es igual al de la carta del mazo de descartes.
	- Cartes especials:
	    	- R (Canvi de sentit)
	    	- S (Saltar torn)
	    	- W (Canvi de color)
	    	- +2 (El seguent jugador roba 2)
	    	- W+4 (El seguent jugador roba 4, i canvies el color)
	- Nomes es pot tirar el W+4 quan no es pot tirar res mes.
	- Jugues amb robots (minim de 3 jugadors, maxim de 5).
	- Modo de comprovacion (si esta activat pots veure totes les cartes dels jugadors i del mazo de robar).
Noves:
	- Quan queden menys de 5 cartes al mazo d'on s'agafen les cartes, automaticament s'agafen totes les cartes del mazo de descartes, es 
	  barrejen i s'afegeixen al mazo de robar, com faries en una partida amb amics.
	- Si algu tira un +2 o un W+4, si pots tirar un W+4 o un +2 (del color corresponent si s-ha tirat previament un W+4) el tires i 
	  s'acumulen les cartes fins que algu no pot tirar cap +2 o W+4. Quan aixo passa, el jugador que no ha pogut tirar-ne cap s'emporta 
	  totes les cartes acumulades. (Era algo que trobavem a faltar en l'UNO)
