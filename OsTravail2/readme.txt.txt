Nous avons eu beaucoup de probl�me avec le fait qu'il ne fallait pas 
copier les 64 octets de la ram au complet dans notre objet memoire
nous avons donc cr�� un tableau de unsigned char qui garde en m�moire seulement
la partie m�moire de la ram donc lors des commutations nous feson que copier notre 
tableau contenant la partie memoire de la ram dans la ram total 
la fonction loadprogramme load tous la partie des instruction donc gr�ce au Pcounter nous pouvons
continuer le programme ou ce qu'il �tait.
un autre point ou nous avons eu de la difficult� est lors de l�criture du rapport(rapport le programme
�crit chaque instruction qu'il fait) au d�part nous avons essayer de le faire via run de MagBox mais sans succes
nous avons donc cr�� une boucle de 3 qui prend le pcounter du programme actuel et va lire dans la ram linstruction actuel 
puis les deux autres gr�ce � la boucle. 