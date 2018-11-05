/*Ajout Client*/
exec addClient('Samuel', 'Dallaire','test@gmail.com', '12222313','1111222233334444', '2020-08-02','404 des champs','1980-01-01');
exec addClient('Steven', 'Duquette','test2@gmail.com', '12222313','1111222233334444', '2020-08-02','404 des champs','1980-01-01');
exec addClient('Carl', 'Lafreniere','test3@gmail.com', '12222313','1111222233334444', '2020-08-02','404 des champs','1980-01-01');
exec addClient('Laila', 'Doublon','test4@gmail.com', '12222313','1111222233334444', '2020-08-02','404 des champs','1980-01-01');
exec addClient('Kyle', 'Liss','test5@gmail.com', '12222313','1111222233334444', '2020-08-02','404 des champs','1980-01-01');
/*Ajout employe*/
exec addEmploye('Eric', 'Lavoie','88888888', '12345678910','test6@gmail.com','56 chemin de la riviere','2006-01-01');
exec addEmploye('Deric', 'Lavoie','88877888', '12345678910','test7@gmail.com','56 chemin de la riviere','2006-01-01');
/*Ajout film*/
exec addFilm('Le premier des descendant','2007-01-23','fr',120,'Un excellent film');
exec addFilm('La revanche','2008-01-23','fr',120,'Un excellent film');
exec addFilm('La trilogie','2009-01-23','fr',120,'Un excellent film');
exec addFilm('Le quatrieme fils','2010-01-23','fr',120,'Un excellent film');
exec addFilm('Le cinquième element','2011-01-23','fr',120,'Un excellent film');
/*Ajout realisateur*/
exec addParticipant('Tel Torro','Guillemo','1971-01-01','Mexique','Excellent realisateur','Realisateur');
/*Ajout acteur*/
exec addParticipant('Ford','Harisson','1971-01-01','USA','Excellent realisateur','Acteur');
exec addParticipant('Pitt','Brad','1971-01-01','USA','Excellent realisateur','Acteur');
exec addParticipant('Jolie','Angelina','1971-01-01','USA','Excellent realisateur','Acteur');
exec addParticipant('Mheyer','Seth','1971-01-01','Canada','Excellent realisateur','Acteur');

/*liaison realisateur*/
exec addParticipantFilm(1,1);
exec addParticipantFilm(2,1);
exec addParticipantFilm(3,1);
exec addParticipantFilm(4,1);
exec addParticipantFilm(5,1);
/*liaison acteur 1*/
exec addParticipantFilm(1,2);
exec addParticipantFilm(2,3);
exec addParticipantFilm(3,4);
exec addParticipantFilm(4,5);
exec addParticipantFilm(5,2);
/*liaison acteur 2*/
exec addParticipantFilm(1,3);
exec addParticipantFilm(2,4);
exec addParticipantFilm(3,5);
exec addParticipantFilm(4,2);
exec addParticipantFilm(5,4);

commit;