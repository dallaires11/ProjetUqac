/*Suppression d'un employe*/
create or replace TRIGGER deleteEmployeViewv
INSTEAD OF DELETE ON employeviewview
FOR EACH ROW
BEGIN
    delete from employe where personid=:OLD.personid;
    delete from personne where personid=:OLD.personid;
END;
/*Suppression d'un client*/
create or replace TRIGGER deleteClientView
INSTEAD OF DELETE ON clientview
FOR EACH ROW
BEGIN
    delete from client where personid=:OLD.personid;
    delete from personne where personid=:OLD.personid;
END;
/*Ajout d'un employe*/
create or replace TRIGGER insertEmployeView
INSTEAD OF INSERT ON employeviewview 
    FOR EACH ROW
DECLARE 
ageClient NUMBER;
BEGIN
    INSERT INTO personne values (:NEW.personid,:NEW.nom,:NEW.prenom,:NEW.courriel,:NEW.adresse,:NEW.datenaissance);
    INSERT INTO employe values (:NEW.numemploye,:NEW.personid,:NEW.identifiant,:NEW.mdp);
END;
/*Ajout d'un client qui s'assure qu'il a 18 ans*/
create or replace TRIGGER verificationAgeClient
INSTEAD OF INSERT ON clientview 
    FOR EACH ROW
DECLARE 
ageClient NUMBER;
BEGIN
SELECT MONTHS_BETWEEN(SYSDATE,:NEW.datenaissance)/12 INTO ageClient FROM DUAL;
DBMS_OUTPUT.PUT_LINE(ageClient);
    IF (ageClient < 18) THEN
        RAISE_APPLICATION_ERROR(-20000,'L age du client  doit être suppérieur a 17.');
    ELSE 
        INSERT INTO personne values (:NEW.personid,:NEW.nom,:NEW.prenom,:NEW.courriel,:NEW.adresse,:NEW.datenaissance);
        INSERT INTO client values (:NEW.numclient,:NEW.personid,:NEW.mdp,:NEW.cartecredit,:NEW.dateexpiration);
    END IF;
END;
/*Ajout d'un instance parent client qui verifit la date d'expiration de la carte de credit*/
create or replace TRIGGER verificationDateCC
BEFORE INSERT ON client
    FOR EACH ROW
DECLARE 
testTest NUMBER;
BEGIN
DBMS_OUTPUT.PUT_LINE(testTest);

SELECT MONTHS_BETWEEN(SYSDATE,:NEW.dateExpiration)/12 INTO testTest FROM DUAL;

    IF (testTest > 0) THEN
        RAISE_APPLICATION_ERROR(-20000,'la date d expiration n est pas valide');
    END IF;
END;
/*Suppression d'un item qui s'assure qu'aucun item est toujours en circulation*/
create or replace TRIGGER verificationDeleteItem
BEFORE DELETE ON item
FOR EACH ROW
BEGIN
    IF (:old.qttotal != :old.qtrestante)then

        RAISE_APPLICATION_ERROR(-20000,'Impossible a supprimer ,car encore des item en circulation');
    END IF;
END;
/*Ajout d'un instance parent personne qui s'assure que le foramt mail est ok*/
create or replace TRIGGER verificationMail
BEFORE INSERT ON personne
    FOR EACH ROW
DECLARE 
ageClient NUMBER;
BEGIN
    IF(NOT(REGEXP_LIKE (:NEW.courriel, '^[A-Za-z]+[A-Za-z0-9.]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$'))) THEN
        RAISE_APPLICATION_ERROR(-20000,'Format mail invalde');

    END IF;
END;

commit;