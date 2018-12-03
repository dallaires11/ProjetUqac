package Controller;

import Model.Personne;
import java.util.List;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class ConnectionSQL {
    private Session uneSession;
    private Transaction uneTransaction;
    private String currentSession;
    
    public String getCurSession(){
        return currentSession;
    }
    
    
    public ConnectionSQL(Session session){
        uneSession = session;
        //uneSession = NewHibernateUtil.getSessionFactory().openSession();
    }
    
    public boolean tryConnection(String pseudo,String mdp){
        uneTransaction = uneSession.beginTransaction();
        //System.out.println(pseudo+" "+mdp);
        List<Personne> lesPersonnes = 
                uneSession.createQuery("from Personne where COURRIEL='"+pseudo+"'").list();
        if(lesPersonnes.size()!=1){
            uneTransaction.rollback();
            return false;
        }
            
        currentSession = lesPersonnes.get(0).getCourriel();
        
        List lesClients =
          uneSession.createQuery("from Client where personid='"+lesPersonnes.get(0).getPersonid()+"' and MDP='"+mdp+"'").list();
        
        System.out.println( lesClients.size() + " clients trouves:" );
        
        uneTransaction.commit();
        if(lesClients.size()==1)
            return true;
        else
            return false;
    }
}
