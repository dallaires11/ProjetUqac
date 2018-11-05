CREATE OR REPLACE SEQUENCE ABONNMENT_SEQUENCE;
CREATE OR REPLACE SEQUENCE FORFAIT_SEQUENCE;
CREATE OR REPLACE SEQUENCE FILM_SEQUENCE;
CREATE OR REPLACE SEQUENCE ITEM_SEQUENCE;
CREATE OR REPLACE SEQUENCE LOCATION_SEQUENCE;
CREATE OR REPLACE SEQUENCE NUMCLIENT_SEQUENCE;
CREATE OR REPLACE SEQUENCE NUMEMPLOYE_SEQUENCE;
CREATE OR REPLACE SEQUENCE PARTICIPANT_SEQUENCE;
CREATE OR REPLACE SEQUENCE PERSONNAGE_SEQUENCE;
CREATE OR REPLACE SEQUENCE PERSONNE_SEQUENCE;

create or replace procedure addabonnement (numclient INTEGER,numforfait INTEGER)
is
BEGIN
    insert into abonnement values(abonnement_sequence.nextval,addabonnement.numclient,addabonnement.numforfait,1,sysdate,null);
end;

create or replace procedure addclient(prenom VARCHAR, nom varchar,courriel varchar, mdp varchar,cartecredit INTEGER, 
dateexpiration DATE,adresse varchar,datenaissance date) is
begin
   insert into clientview values (personne_sequence.nextval,addclient.prenom,addclient.nom,addclient.courriel,addclient.mdp,numclient_sequence.nextval,
   addclient.cartecredit,addclient.dateexpiration,addclient.adresse,addclient.datenaissance);
end;

create or replace procedure addemploye(prenom VARCHAR, nom varchar,identifiant INTEGER, mdp varchar,courriel 
varchar,adresse varchar,datenaissance date) is
begin
   insert into employeviewview values (personne_sequence.nextval,numemploye_sequence.nextval,addEmploye.prenom,addEmploye.nom,
   addEmploye.identifiant,addEmploye.mdp,addEmploye.courriel,addEmploye.adresse,addEmploye.datenaissance);
end;

create or replace procedure addfilm (titre varchar,dateparue date, langueoriginal varchar, duremin integer, resum varchar)
is
begin 
    insert into film values(film_sequence.nextval,addfilm.titre,addfilm.dateparue,addfilm.langueoriginal,addfilm.duremin,addfilm.resum);
end;

create or replace procedure addforfait (nblocationmax INTEGER, dureemax INTEGER, prixforfaitparmois INTEGER)
is
BEGIN 
    INSERT INTO forfait values(forfait_sequence.nextval,addforfait.nblocationmax,addforfait.dureemax,addforfait.prixforfaitparmois);
end;

create or replace procedure addGenre(genre VARCHAR, description VARCHAR) is
begin
   insert into genre values (addGenre.genre,addGenre.description);
end;

create or replace procedure addGenreFilm(genre VARCHAR,  numfilm INTEGER) is
begin
   insert into genreFilm values (addGenreFilm.genre,addGenreFilm.numfilm);
end;

create or replace procedure addItem(film INTEGER,qt INTEGER) is
begin
    insert into ITEM (numitem,numfilm,qttotal,qtrestante) VALUES( item_sequence.nextval,addItem.film,addItem.qt,addItem.qt);
end;

create or replace procedure addParticipant (nom VARCHAR,prenom VARCHAR,dateNaissance DATE,lieuNaissance VARCHAR,biographie VARCHAR,typeparticipant VARCHAR)
is
BEGIN
    insert into Participant values(participant_sequence.nextval,addParticipant.nom,addParticipant.prenom,addParticipant.dateNaissance,addParticipant.lieuNaissance,
    addParticipant.biographie,addParticipant.typeparticipant);
end;

create or replace procedure addParticipantFilm (numFilm INTEGER,numParticipant INTEGER)
is
BEGIN
    insert into ParticipantFilm values(addParticipantFilm.numfilm,addParticipantFilm.numParticipant);
end;

create or replace procedure addpays (nom varchar)
is
begin
    insert into pays values(pays_sequence.nextval,addpays.nom);
end;

create or replace procedure addpaysprod(numpays INTEGER, numfilm INTEGER)
is
begin
    insert into paysproduction values(addpaysprod.numpays,addpaysprod.numfilm);
end;

create or replace procedure addpersonnage (numfilm INTEGER, numparticipant INTEGER, nom varchar,description varchar)
is
begin
    insert into personnage values(personnage_sequence.nextval,addpersonnage.numfilm,addpersonnage.numparticipant,addpersonnage.nom,addpersonnage.description);
end;

create or replace procedure addlocation(numitem INTEGER, numabonnement INTEGER)
is
begin
    insert into location values(location_sequence.nextval,addlocation.numitem,addlocation.numabonnement,sysdate,0);
end;

create or replace procedure deleteabonnement(numabonnement INTEGER)
is
begin
 delete from abonnement where numabonnement = deleteabonnement.numabonnement;
end;

create or replace procedure deleteclient (personid INTEGER)
is 
begin
delete from clientview where personid = deleteclient.personid;
end;

create or replace procedure deleteEmploye (personid INTEGER)
is 
begin
delete from employeviewview where personid = deleteemploye.personid;
end;

create or replace procedure deletefilm (numfilm INTEGER)
is
begin
    delete from film where numfilm=deletefilm.numfilm;
end;

create or replace procedure deleteforfait(numforfait INTEGER)
is
BEGIN
    delete from forfait where numforfait =deleteforfait.numforfait;
END;

create or replace procedure deleteGenre (genre VARCHAR)
is 
begin
delete from genreFilm where genre=deleteGenre.genre;
delete from genre where genre=deleteGenre.genre;
end;

create or replace procedure deleteitem (numItem INTEGER)
is 
begin
    delete from item where numitem = deleteitem.numItem;
end;

create or replace procedure deleteParticipant (numParticipant INTEGER)
is 
begin
delete from ParticipantFilm where numparticipant = deleteParticipant.numParticipant;
delete from Participant where numparticipant = deleteParticipant.numParticipant;
end;

create or replace procedure deletepays(numpays INTEGER)
is
begin
    delete from paysproduction where numpays=deletepays.numpays;
    delete from pays where numpays=deletepays.numpays;
end;

create or replace procedure deletepersonnage (numpersonnage INTEGER)
is
begin
    delete from personnage where numpersonnage = deletepersonnage.numpersonnage;
end;

create or replace procedure deletelocation(numlocation INTEGER)
is
begin
    delete from location where numlocation = deletelocation.numlocation;
end;

commit;