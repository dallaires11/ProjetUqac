package Model;
// Generated 2018-11-28 10:58:41 by Hibernate Tools 4.3.1


import java.math.BigDecimal;
import java.util.HashSet;
import java.util.Set;

/**
 * Item generated by hbm2java
 */
public class Item  implements java.io.Serializable {


     private BigDecimal numitem;
     private Film film;
     private BigDecimal qttotal;
     private BigDecimal qtrestante;
     private Set locations = new HashSet(0);

    public Item() {
    }

	
    public Item(BigDecimal numitem) {
        this.numitem = numitem;
    }
    public Item(BigDecimal numitem, Film film, BigDecimal qttotal, BigDecimal qtrestante, Set locations) {
       this.numitem = numitem;
       this.film = film;
       this.qttotal = qttotal;
       this.qtrestante = qtrestante;
       this.locations = locations;
    }
   
    public BigDecimal getNumitem() {
        return this.numitem;
    }
    
    public void setNumitem(BigDecimal numitem) {
        this.numitem = numitem;
    }
    public Film getFilm() {
        return this.film;
    }
    
    public void setFilm(Film film) {
        this.film = film;
    }
    public BigDecimal getQttotal() {
        return this.qttotal;
    }
    
    public void setQttotal(BigDecimal qttotal) {
        this.qttotal = qttotal;
    }
    public BigDecimal getQtrestante() {
        return this.qtrestante;
    }
    
    public void setQtrestante(BigDecimal qtrestante) {
        this.qtrestante = qtrestante;
    }
    public Set getLocations() {
        return this.locations;
    }
    
    public void setLocations(Set locations) {
        this.locations = locations;
    }




}


