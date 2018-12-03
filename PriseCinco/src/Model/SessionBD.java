package Model;

public class SessionBD {
    String pseudo,mdp;
    
    public SessionBD(String peudo,String mdp){
        this.pseudo = pseudo;
        this.mdp = mdp;
    }
    
    public String getPseudo(){
        return pseudo;
    }
}
