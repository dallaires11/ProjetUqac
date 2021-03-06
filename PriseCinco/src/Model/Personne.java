package Model;
// Generated 2018-11-28 10:58:41 by Hibernate Tools 4.3.1


import java.math.BigDecimal;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;

/**
 * Personne generated by hbm2java
 */
public class Personne  implements java.io.Serializable {


     private BigDecimal personid;
     private String nom;
     private String prenom;
     private String courriel;
     private String adresse;
     private Date datenaissance;
     private Set employes = new HashSet(0);
     private Set clients = new HashSet(0);

    public Personne() {
    }

	
    public Personne(BigDecimal personid, String nom, String prenom, String courriel, String adresse, Date datenaissance) {
        this.personid = personid;
        this.nom = nom;
        this.prenom = prenom;
        this.courriel = courriel;
        this.adresse = adresse;
        this.datenaissance = datenaissance;
    }
    public Personne(BigDecimal personid, String nom, String prenom, String courriel, String adresse, Date datenaissance, Set employes, Set clients) {
       this.personid = personid;
       this.nom = nom;
       this.prenom = prenom;
       this.courriel = courriel;
       this.adresse = adresse;
       this.datenaissance = datenaissance;
       this.employes = employes;
       this.clients = clients;
    }
   
    public BigDecimal getPersonid() {
        return this.personid;
    }
    
    public void setPersonid(BigDecimal personid) {
        this.personid = personid;
    }
    public String getNom() {
        return this.nom;
    }
    
    public void setNom(String nom) {
        this.nom = nom;
    }
    public String getPrenom() {
        return this.prenom;
    }
    
    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }
    public String getCourriel() {
        return this.courriel;
    }
    
    public void setCourriel(String courriel) {
        this.courriel = courriel;
    }
    public String getAdresse() {
        return this.adresse;
    }
    
    public void setAdresse(String adresse) {
        this.adresse = adresse;
    }
    public Date getDatenaissance() {
        return this.datenaissance;
    }
    
    public void setDatenaissance(Date datenaissance) {
        this.datenaissance = datenaissance;
    }
    public Set getEmployes() {
        return this.employes;
    }
    
    public void setEmployes(Set employes) {
        this.employes = employes;
    }
    public Set getClients() {
        return this.clients;
    }
    
    public void setClients(Set clients) {
        this.clients = clients;
    }




}


