Nous avons eu beaucoup de problême avec le fait qu'il ne fallait pas 
copier les 64 octets de la ram au complet dans notre objet memoire
nous avons donc créé un tableau de unsigned char qui garde en mémoire seulement
la partie mémoire de la ram donc lors des commutations nous feson que copier notre 
tableau contenant la partie memoire de la ram dans la ram total 
la fonction loadprogramme load tous la partie des instruction donc grâce au Pcounter nous pouvons
continuer le programme ou ce qu'il était.
un autre point ou nous avons eu de la difficulté est lors de lécriture du rapport(rapport le programme
écrit chaque instruction qu'il fait) au départ nous avons essayer de le faire via run de MagBox mais sans succes
nous avons donc créé une boucle de 3 qui prend le pcounter du programme actuel et va lire dans la ram linstruction actuel 
puis les deux autres grâce à la boucle. 