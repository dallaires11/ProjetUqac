package Model;
// Generated 2018-11-28 10:58:41 by Hibernate Tools 4.3.1


import java.math.BigDecimal;

/**
 * ParticipantfilmId generated by hbm2java
 */
public class ParticipantfilmId  implements java.io.Serializable {


     private BigDecimal numfilm;
     private BigDecimal numparticipant;

    public ParticipantfilmId() {
    }

    public ParticipantfilmId(BigDecimal numfilm, BigDecimal numparticipant) {
       this.numfilm = numfilm;
       this.numparticipant = numparticipant;
    }
   
    public BigDecimal getNumfilm() {
        return this.numfilm;
    }
    
    public void setNumfilm(BigDecimal numfilm) {
        this.numfilm = numfilm;
    }
    public BigDecimal getNumparticipant() {
        return this.numparticipant;
    }
    
    public void setNumparticipant(BigDecimal numparticipant) {
        this.numparticipant = numparticipant;
    }


   public boolean equals(Object other) {
         if ( (this == other ) ) return true;
		 if ( (other == null ) ) return false;
		 if ( !(other instanceof ParticipantfilmId) ) return false;
		 ParticipantfilmId castOther = ( ParticipantfilmId ) other; 
         
		 return ( (this.getNumfilm()==castOther.getNumfilm()) || ( this.getNumfilm()!=null && castOther.getNumfilm()!=null && this.getNumfilm().equals(castOther.getNumfilm()) ) )
 && ( (this.getNumparticipant()==castOther.getNumparticipant()) || ( this.getNumparticipant()!=null && castOther.getNumparticipant()!=null && this.getNumparticipant().equals(castOther.getNumparticipant()) ) );
   }
   
   public int hashCode() {
         int result = 17;
         
         result = 37 * result + ( getNumfilm() == null ? 0 : this.getNumfilm().hashCode() );
         result = 37 * result + ( getNumparticipant() == null ? 0 : this.getNumparticipant().hashCode() );
         return result;
   }   


}


