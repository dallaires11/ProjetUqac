package Model;

import Interface.Epreuve;

public class Participant {
    private int vitesse,noParticipant,dureePause;
    private String icone;
    //<<Property>> private int piste,position;
    private boolean enCourse;
    private final int noParticipantCompteur=0;
    private Epreuve epreuve;

    protected Participant(int vitesse,String icone){
        this.vitesse=vitesse;
        this.icone=icone;
    }

    private void setDureePause(){
        dureePause=0;
    }

    public void setDepart(Epreuve epreuve,int piste){

    }

    public String getInformation(){
        return "";
    }

    protected void setVitesse(int nouvelleVitesse){
        vitesse = nouvelleVitesse;
    }

    protected int getVitesse(){
        return vitesse;
    }

    public void run(){

    }

    public boolean enCourse(){
        return enCourse;
    }

    public void finCourse(){
        enCourse = false;
    }

    @Override
    public String toString(){
        return " ";
    }
}
