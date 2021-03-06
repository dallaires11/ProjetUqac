package Model;
// Generated 2018-11-28 10:58:41 by Hibernate Tools 4.3.1


import java.math.BigDecimal;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;

/**
 * Client generated by hbm2java
 */
public class Client  implements java.io.Serializable {


     private BigDecimal numclient;
     private Personne personne;
     private String mdp;
     private BigDecimal cartecredit;
     private Date dateexpiration;
     private Set abonnements = new HashSet(0);

    public Client() {
    }

	
    public Client(BigDecimal numclient, String mdp, BigDecimal cartecredit) {
        this.numclient = numclient;
        this.mdp = mdp;
        this.cartecredit = cartecredit;
    }
    public Client(BigDecimal numclient, Personne personne, String mdp, BigDecimal cartecredit, Date dateexpiration, Set abonnements) {
       this.numclient = numclient;
       this.personne = personne;
       this.mdp = mdp;
       this.cartecredit = cartecredit;
       this.dateexpiration = dateexpiration;
       this.abonnements = abonnements;
    }
   
    public BigDecimal getNumclient() {
        return this.numclient;
    }
    
    public void setNumclient(BigDecimal numclient) {
        this.numclient = numclient;
    }
    public Personne getPersonne() {
        return this.personne;
    }
    
    public void setPersonne(Personne personne) {
        this.personne = personne;
    }
    public String getMdp() {
        return this.mdp;
    }
    
    public void setMdp(String mdp) {
        this.mdp = mdp;
    }
    public BigDecimal getCartecredit() {
        return this.cartecredit;
    }
    
    public void setCartecredit(BigDecimal cartecredit) {
        this.cartecredit = cartecredit;
    }
    public Date getDateexpiration() {
        return this.dateexpiration;
    }
    
    public void setDateexpiration(Date dateexpiration) {
        this.dateexpiration = dateexpiration;
    }
    public Set getAbonnements() {
        return this.abonnements;
    }
    
    public void setAbonnements(Set abonnements) {
        this.abonnements = abonnements;
    }




}


