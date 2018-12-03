package Controller;

import Model.Film;
import Model.Genre;
import Model.Genrefilm;
import Model.Participant;
import Model.Participantfilm;
import Model.Pays;
import Model.Paysproduction;
import Model.Personnage;
import java.util.ArrayList;
import java.util.List;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class RechercheSQL {
    private Session uneSession;
    private Transaction uneTransaction;
    
    public RechercheSQL(Session session){
        uneSession=session;
    }
    
    private String requeteParticipant(List<Participant> lesParticipants){
        if(lesParticipants.size()==0)
            return " and 1=2";
        String requete4 = " and NUMFILM in (";
        String requete5 = " (";
        Participant unParticipant;
        
        for(int x=0;x<lesParticipants.size();x++){
            if(x!=0)
                requete5+=",";
            unParticipant = (Participant)lesParticipants.get(x);
            requete5+="'"+unParticipant.getNumparticipant()+"'";
        }
        requete5+=")";
        
        Participantfilm unParticpantFilm;
        List<Participantfilm> lesParticipantsFilms = 
                uneSession.createQuery("from Participantfilm where NUMPARTICIPANT in "+requete5+"").list();
        for(int x=0;x<lesParticipantsFilms.size();x++){
            if(x!=0)
                requete4+=",";
            unParticpantFilm = (Participantfilm)lesParticipantsFilms.get(x);
            requete4+="'"+unParticpantFilm.getFilm().getNumfilm()+"'";
        }
        requete4+=")";

        if(lesParticipantsFilms.size()==0)
            requete4 = " and 1=2";
        return requete4;
    }
    
    public List<String> effectuerRecherche(String titre,String anneeMin,String anneeMax,String pays,String langue, 
            String genre,String realisateurPre,String realisateurFam,String acteurPre,String acteurFam){
        uneTransaction = uneSession.beginTransaction();
        System.out.println(titre+" "+anneeMin+" "+anneeMax+" "+pays+" "+genre+" "+langue);
        Film unFilm;
        
        String requete = "from Film where 1=1";
        if(titre!= null && !titre.trim().isEmpty())
            requete+=" and TITRE LIKE '%"+titre+"%'";
        if(anneeMin != null && !anneeMin.trim().isEmpty())
            requete+=" and DATEPARUE>='"+anneeMin+"'";
        if(anneeMax != null && !anneeMax.trim().isEmpty())
            requete+=" and DATEPARUE<='"+anneeMax+"'";
        if(pays!= null && !pays.trim().isEmpty()){
            String requete2 = " and NUMFILM in (";
            List<Pays> lesPays = 
                    uneSession.createQuery("from Pays where NOM = '"+pays+"'").list();
            if(lesPays.size()==0){
                requete2 = " and 1=2";
            }else{
                Paysproduction unPaysProd;
                List<Paysproduction> lesPaysProds = 
                    uneSession.createQuery("from Paysproduction where NUMPAYS = '"+lesPays.get(0).getNumpays()+"'").list();
            

                for(int x=0;x<lesPaysProds.size();x++){
                    if(x!=0)
                        requete2+=",";
                    unPaysProd = (Paysproduction)lesPaysProds.get(x);
                    requete2+="'"+unPaysProd.getFilm().getNumfilm()+"'";
                }
                requete2+=")";
            
                if(lesPaysProds.size()==0)
                    requete2 = " and 1=2";
            }
            requete+=requete2;
        }
        if(genre!= null && !genre.trim().isEmpty()){
            String requete3 = " and NUMFILM in (";
            List<Genre> lesGenres = 
                    uneSession.createQuery("from Genre where GENRE = '"+genre+"'").list();
            if(lesGenres.size()==0){
                requete3 = " and 1=2";
            }else{
                Genrefilm unGenreFilm;
                List<Genrefilm> lesGenresFilms = 
                        uneSession.createQuery("from Genrefilm where NUMGENRE = '"+lesGenres.get(0).getNumgenre()+"'").list();

                for(int x=0;x<lesGenresFilms.size();x++){
                    if(x!=0)
                        requete3+=",";
                    unGenreFilm = (Genrefilm)lesGenresFilms.get(x);
                    requete3+="'"+unGenreFilm.getFilm().getNumfilm()+"'";
                }
                requete3+=")";

                if(lesGenresFilms.size()==0)
                    requete3 = " and 1=2";
            }
            requete+=requete3;
        }
        if(langue!= null && !langue.trim().isEmpty())
            requete+=" and LANGUEORIGINALE LIKE '%"+langue+"%'";
        if(realisateurPre!= null && !realisateurPre.trim().isEmpty()){
            List<Participant> lesParticipants = 
                    uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Realisateur' and PRENOM = '"+realisateurPre+"'").list();
            requete+=requeteParticipant(lesParticipants);
        }
        if(realisateurFam!= null && !realisateurFam.trim().isEmpty()){
            List<Participant> lesParticipants = 
                    uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Realisateur' and NOM = '"+realisateurFam+"'").list();
            requete+=requeteParticipant(lesParticipants);
        }
        if(acteurPre!= null && !acteurPre.trim().isEmpty()){
            List<Participant> lesParticipants = 
                    uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Acteur' and PRENOM = '"+acteurPre+"'").list();
            requete+=requeteParticipant(lesParticipants);
        }
        if(acteurFam!= null && !acteurFam.trim().isEmpty()){
            List<Participant> lesParticipants = 
                    uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Acteur' and NOM = '"+acteurFam+"'").list();
            requete+=requeteParticipant(lesParticipants);
        }

        List<Film> lesFilm =
          uneSession.createQuery(""+requete).list();
        
        List<String> lesTitres = new ArrayList<String>();
        for(int x=0;x<lesFilm.size();x++){
                unFilm = (Film)lesFilm.get(x);
                lesTitres.add(unFilm.getTitre());
        }
        
        System.out.println( lesFilm.size() + " films trouves:" );
        
        uneTransaction.commit();
        
        return lesTitres;    
    }
    
    public Film getInfo(String titre){
        uneTransaction = uneSession.beginTransaction();
        System.out.println(titre);
        Film unFilm;

        List<Film> lesFilm =
          uneSession.createQuery("from Film where TITRE = '"+titre+"'").list();
        
        List<String> lesFilms = new ArrayList<String>();
        unFilm = (Film)lesFilm.get(0);
        
        System.out.println( lesFilm.size() + " films trouves:" );
        
        uneTransaction.commit();
        
        return unFilm;    
    }
    
    public String getInfoPays(Film unFilm){
        String result = "";
        List<Paysproduction> lesPaysProd =
                uneSession.createQuery("from Paysproduction where NUMFILM = '"+unFilm.getNumfilm()+"'").list();
        String ensemble = " ";
        Paysproduction unPaysProd;
        for(int x=0;x<lesPaysProd.size();x++){
            if(x!=0)
                ensemble+=",";
            unPaysProd = (Paysproduction)lesPaysProd.get(x);
            ensemble+= unPaysProd.getPays().getNumpays();
        }
        
        List<Pays> lesPays = 
                uneSession.createQuery("from Pays where NUMPAYS IN ("+ensemble+")").list();
        
        Pays unPays;
        for(int x=0;x<lesPays.size();x++){
            if(x!=0)
                result+=",";
            unPays = (Pays)lesPays.get(x);
            result+= unPays.getNom();
        }
        
        return result;
    }
    
    public String getInfoGenre(Film unFilm){
        String result = "";
        List<Genrefilm> lesGenresFilm =
                uneSession.createQuery("from Genrefilm where NUMFILM = '"+unFilm.getNumfilm()+"'").list();
        String ensemble = " ";
        Genrefilm unGenreFilm;
        for(int x=0;x<lesGenresFilm.size();x++){
            if(x!=0)
                ensemble+=",";
            unGenreFilm = (Genrefilm)lesGenresFilm.get(x);
            ensemble+= unGenreFilm.getGenre().getNumgenre();
        }
        
        List<Genre> lesGenres = 
                uneSession.createQuery("from Genre where NUMGENRE IN ("+ensemble+")").list();
        
        Genre unGenre;
        for(int x=0;x<lesGenres.size();x++){
            if(x!=0)
                result+=",";
            unGenre = (Genre)lesGenres.get(x);
            result+= unGenre.getGenre();
        }
        
        return result;
    }
    
    private String getInfoPersonnage(Film unFilm,Participant acteur){
        String result = "";
        List<Personnage> lesPersonnages = 
                uneSession.createQuery("from Personnage where NUMFILM = '"+unFilm.getNumfilm()+"' and NUMPARTICIPANT "
                        + "= '"+acteur.getNumparticipant()+"'").list();
        Personnage unPersonnage;
        if(lesPersonnages.size()==0)
            return "Erreur - Acteur clandestin";
        
        for(int x=0;x<lesPersonnages.size();x++){
            if(x!=0)
                result+=",";
            unPersonnage = (Personnage)lesPersonnages.get(x);
            result+= unPersonnage.getNom();
        }
        
        
        return result;
    }
    
    public String getInfoActeurs(Film unFilm){
        String result = "";
        List<Participantfilm> lesParticipantsFilm =
                uneSession.createQuery("from Participantfilm where NUMFILM = '"+unFilm.getNumfilm()+"'").list();
        String ensemble = " ";
        Participantfilm unParticipantFilm;
        for(int x=0;x<lesParticipantsFilm.size();x++){
            if(x!=0)
                ensemble+=",";
            unParticipantFilm = (Participantfilm)lesParticipantsFilm.get(x);
            ensemble+= unParticipantFilm.getParticipant().getNumparticipant();
        }
        
        List<Participant> lesParticipants = 
                uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Acteur' and NUMPARTICIPANT IN ("+ensemble+")").list();
        Participant unParticipant;
        for(int x=0;x<lesParticipants.size();x++){
            if(x!=0)
                result+=",";
            unParticipant = (Participant)lesParticipants.get(x);
            result+= unParticipant.getPrenom()+" "+unParticipant.getNom();
            result+= " ("+getInfoPersonnage(unFilm,unParticipant)+")";
        }
        
        return result;
    }
    
    public String getInfoRealisateur(Film unFilm){
        String result = "";
        List<Participantfilm> lesParticipantsFilm =
                uneSession.createQuery("from Participantfilm where NUMFILM = '"+unFilm.getNumfilm()+"'").list();
        String ensemble = " ";
        Participantfilm unParticipantFilm;
        for(int x=0;x<lesParticipantsFilm.size();x++){
            if(x!=0)
                ensemble+=",";
            unParticipantFilm = (Participantfilm)lesParticipantsFilm.get(x);
            ensemble+= unParticipantFilm.getParticipant().getNumparticipant();
        }
        
        List<Participant> lesParticipants = 
                uneSession.createQuery("from Participant where TYPEPARTICIPANT = 'Realisateur' and NUMPARTICIPANT IN ("+ensemble+")").list();
        
        Participant unParticipant;
        for(int x=0;x<lesParticipants.size();x++){
            if(x!=0)
                result+=",";
            unParticipant = (Participant)lesParticipants.get(x);
            result+= unParticipant.getPrenom()+" "+unParticipant.getNom();
        }
        
        return result;
    }
}
