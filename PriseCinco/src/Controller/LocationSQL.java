package Controller;

import Model.Abonnement;
import Model.Client;
import Model.Film;
import Model.Forfait;
import Model.Item;
import Model.Location;
import Model.Personne;
import java.math.BigDecimal;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Date;
import java.util.List;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class LocationSQL {
    Session uneSession;
    
    public LocationSQL(Session session){
        uneSession=session;
    }
    
    public boolean steal(Film film,String nom){
        Transaction uneTransaction = uneSession.beginTransaction();


        if(film == null){
            uneTransaction.commit();
            return false;
        }
        
        List<Item> lesItems =
          uneSession.createQuery("from Item where NUMFILM = '"+film.getNumfilm()+"' and QTRESTANTE>0").list();
        
        if(lesItems.size()==0){
            uneTransaction.commit();
            return false;
        }

        
         
         List<Personne> lesPersonnes = 
                uneSession.createQuery("from Personne where COURRIEL='"+nom+"'").list();
        if(lesPersonnes.size()!=1){
            uneTransaction.commit();
            return false;
        }

        List<Client> lesClients = 
                uneSession.createQuery("from Client where PERSONID = '"+lesPersonnes.get(0).getPersonid()+"'").list();

        if(lesClients.size()==0){
            uneTransaction.commit();
            return false;
        }

        List<Abonnement> lesAbonnement = 
                uneSession.createQuery("from Abonnement where NUMCLIENT = '"+lesClients.get(0).getNumclient()+"'").list();
        if(lesAbonnement.size()==0){
            uneTransaction.commit();
            return false;
        }

        
        List<Forfait> lesForfaits =
                uneSession.createQuery("from Forfait where NUMFORFAIT = '"+lesAbonnement.get(0).getForfait().getNumforfait()+"'").list();
        if(lesForfaits.size()!=1){
            uneTransaction.commit();
            return false;
        }
        
        
        boolean numLocNull = false;
        List<Location> lesLocations = 
                uneSession.createQuery("from Location where NUMABONNEMENT = '"+lesAbonnement.get(0).getNumabonnemnt()+"'").list();
        if(lesForfaits.get(0).getNblocationmax().intValue()<=lesLocations.size()){
            uneTransaction.commit();
            return false;
        }
        
        List<Location> lesLocations2 = 
                uneSession.createQuery("from Location ORDER BY NUMLOCATION DESC").list();
        
        if(lesLocations2.size()==0){
            numLocNull=true;
        }

        Location uneLocation = new Location();
        uneLocation.setAbonnement(lesAbonnement.get(0));
        
        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");
        Date date;
        try{
            date = format.parse(LocalDate.now().toString());
        }catch(Exception e){
            uneTransaction.rollback();
            return false;
        }       
        
        if(numLocNull){
            uneLocation.setNumlocation(new BigDecimal(1));
        }
        else{
            int test = lesLocations2.get(0).getNumlocation().intValue() +1;
            uneLocation.setNumlocation(new BigDecimal(test));
        }
        uneLocation.setDatedebut(date);
        uneLocation.setItem(lesItems.get(0));
        uneLocation.setFraisretard(BigDecimal.ZERO);
        uneSession.save(uneLocation);
        
        uneTransaction.commit();
        
        return true;    
    }
}
