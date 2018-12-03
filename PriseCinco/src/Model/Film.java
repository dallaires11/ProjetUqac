package Model;
// Generated 2018-11-28 10:58:41 by Hibernate Tools 4.3.1


import java.math.BigDecimal;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;

/**
 * Film generated by hbm2java
 */
public class Film  implements java.io.Serializable {


     private BigDecimal numfilm;
     private String titre;
     private Date dateparue;
     private String langueoriginale;
     private BigDecimal dureemin;
     private String resume;
     private Set participantfilms = new HashSet(0);
     private Set personnages = new HashSet(0);
     private Set paysproductions = new HashSet(0);
     private Set items = new HashSet(0);
     private Set genrefilms = new HashSet(0);

    public Film() {
    }

	
    public Film(BigDecimal numfilm, String titre, BigDecimal dureemin) {
        this.numfilm = numfilm;
        this.titre = titre;
        this.dureemin = dureemin;
    }
    public Film(BigDecimal numfilm, String titre, Date dateparue, String langueoriginale, BigDecimal dureemin, String resume, Set participantfilms, Set personnages, Set paysproductions, Set items, Set genrefilms) {
       this.numfilm = numfilm;
       this.titre = titre;
       this.dateparue = dateparue;
       this.langueoriginale = langueoriginale;
       this.dureemin = dureemin;
       this.resume = resume;
       this.participantfilms = participantfilms;
       this.personnages = personnages;
       this.paysproductions = paysproductions;
       this.items = items;
       this.genrefilms = genrefilms;
    }
   
    public BigDecimal getNumfilm() {
        return this.numfilm;
    }
    
    public void setNumfilm(BigDecimal numfilm) {
        this.numfilm = numfilm;
    }
    public String getTitre() {
        return this.titre;
    }
    
    public void setTitre(String titre) {
        this.titre = titre;
    }
    public Date getDateparue() {
        return this.dateparue;
    }
    
    public void setDateparue(Date dateparue) {
        this.dateparue = dateparue;
    }
    public String getLangueoriginale() {
        return this.langueoriginale;
    }
    
    public void setLangueoriginale(String langueoriginale) {
        this.langueoriginale = langueoriginale;
    }
    public BigDecimal getDureemin() {
        return this.dureemin;
    }
    
    public void setDureemin(BigDecimal dureemin) {
        this.dureemin = dureemin;
    }
    public String getResume() {
        return this.resume;
    }
    
    public void setResume(String resume) {
        this.resume = resume;
    }
    public Set getParticipantfilms() {
        return this.participantfilms;
    }
    
    public void setParticipantfilms(Set participantfilms) {
        this.participantfilms = participantfilms;
    }
    public Set getPersonnages() {
        return this.personnages;
    }
    
    public void setPersonnages(Set personnages) {
        this.personnages = personnages;
    }
    public Set getPaysproductions() {
        return this.paysproductions;
    }
    
    public void setPaysproductions(Set paysproductions) {
        this.paysproductions = paysproductions;
    }
    public Set getItems() {
        return this.items;
    }
    
    public void setItems(Set items) {
        this.items = items;
    }
    public Set getGenrefilms() {
        return this.genrefilms;
    }
    
    public void setGenrefilms(Set genrefilms) {
        this.genrefilms = genrefilms;
    }




}


