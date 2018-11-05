CREATE TABLE Personne 
(personid INTEGER PRIMARY KEY,
nom VARCHAR(25) NOT NULL,
prenom VARCHAR(20) NOT NULL,
courriel VARCHAR(30) UNIQUE NOT NULL,
adresse VARCHAR(50) NOT NULL,
dateNaissance DATE NOT NULL
);

CREATE TABLE Participant
(numParticipant INTEGER,
CONSTRAINT t1 PRIMARY KEY(numParticipant),
nom VARCHAR(25) NOT NULL,
prenom VARCHAR(20),
dateNaissance DATE,
lieuNaissance VARCHAR(20),
biographie VARCHAR(200),
typeParticipant VARCHAR2(15),
CONSTRAINT enumType CHECK( typeParticipant IN ('Acteur','Realisateur',NULL) )
);

CREATE TABLE FORFAIT
(numForfait INTEGER PRIMARY KEY,
prixForfaitParMois NUMBER(3,2),
nbLocationMax INTEGER,
dureeMax INTEGER
);

CREATE TABLE FILM
(numFilm INTEGER PRIMARY KEY,
titre VARCHAR(35) UNIQUE NOT NULL,
dateParue DATE,
langueOriginale VARCHAR(10),
dureeMin INTEGER NOT NULL,
CONSTRAINT dureeReel CHECK(dureeMin>0),
resume VARCHAR(250)
);

CREATE TABLE ITEM
(numItem INTEGER PRIMARY KEY,
numFilm INTEGER,
FOREIGN KEY (numFilm) REFERENCES Film(numFilm),
qtTotal INTEGER,
qtRestante INTEGER
);

CREATE TABLE LOCATION
(numLocation INTEGER PRIMArY KEY,
numItem INTEGER,
FOREIGN KEY (numItem) REFERENCES Item(numItem),
dateDebut DATE,
fraisRetard NUMBER(3,2)
);

CREATE TABLE GENRE
(genre VARCHAR(10) UNIQUE NOT NULL,
description VARCHAR(30)
);

CREATE TABLE Pays
(numPays INTEGER PRIMARY KEY,
nom VARCHAR(15) UNIQUE NOT NULL
);

CREATE TABLE PERSONNAGE
(numPERSONNAGE INTEGER PRIMARY KEY,
numFilm INTEGER,
FOREIGN KEY (numfilm) REFERENCES Film(numFilm),
numParticipant INTEGER,
FOREIGN KEY (numParticipant) REFERENCES Participant(numParticipant),
nom VARCHAR(25) NOT NULL,
descriptionPerso VARCHAR(50)
);

CREATE TABLE PARTICIPANTFILM
(numFilm INTEGER,
FOREIGN KEY (numFilm) REFERENCES Film(numFilm),
numParticipant INTEGER,
FOREIGN KEY (numParticipant) REFERENCES Participant(numParticipant)
);

CREATE TABLE GENREFILM
(genre VARCHAR(10),
FOREIGN KEY (genre) REFERENCES Genre(genre),
numFilm INTEGER,
FOREIGN KEY (numFilm) REFERENCES Film(numFilm)
);

CREATE TABLE PAYSPRODUCTION
(numPays INTEGER,
FOREIGN KEY (numPays) REFERENCES Pays(numPays),
numFilm INTEGER,
FOREIGN KEY (numFilm) REFERENCES Film(numFilm)
);

CREATE TABLE Employe
(numEmploye INTEGER PRIMARY KEY,
CONSTRAINT checkIdNumEmp CHECK (numEmploye<100000000),
identifiant INTEGER UNIQUE NOT NULL,
mdp VARCHAR(25) NOT NULL
);

CREATE TABLE Client
(numClient INTEGER PRIMARY KEY,
personid INTEGER,
FOREIGN KEY (personid) REFERENCES Personne(personid),
mdp VARCHAR(25) NOT NULL,
CONSTRAINT checkValidMdp CHECK (LENGTH('mdp')>=5),
carteCredit INTEGER NOT NULL,
CONSTRAINT checkValidCredit CHECK (carteCredit>999999999999999 AND carteCredit<10000000000000000),
dateExpiration DATE
/*CONSTRAINT creditExpire CHECK(SONOFABITCH< dateExpiration)
CONSTRAINT assezVieux CHECK((TRUNC(sysdate,'year')-TRUNC(,'year'))>=18)
SELECT (sysdate - date1)/365 FROM dual*/
) ;

CREATE TABLE ABONNEMENT
(numAbonnemnt INTEGER PRIMARY KEY,
numClient INTEGER,
FOREIGN KEY (numClient) REFERENCES Client(numClient),
numForfait INTEGER,
FOREIGN KEY (numForfait) REFERENCES Forfait(numForfait),
actif NUMBER(1) not null,
CONSTRAINT bool CHECK(actif=0 OR actif=1),
dateDebut date,
dateFin date
);
