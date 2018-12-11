package Model;

import Interface.Epreuve;

public class Participant extends Thread{
    private int vitesse,noParticipant,dureePause;
    private String icone;
    private int piste,position;
    private boolean enCourse,easterEgg;
    private final int noParticipantCompteur=0;
    private Epreuve epreuve;

    protected Participant(int vitesse,String icone){
        this.vitesse=vitesse;
        this.icone=icone;
        enCourse = true;
        easterEgg = false;
    }

    public void setDepart(Epreuve epreuve,int piste,int delai){
        this.epreuve=epreuve;
        this.piste=piste;
        dureePause=delai;
    }


    public void setPosition(int position) {
        this.position = position;
    }

    public int getCurrentPiste(){
        return  piste;
    }

    public int getPosition(){
        return position;
    }

    public String getInformation(){
        return "Partcipant "+icone;
    }

    protected void setVitesse(int nouvelleVitesse){
        if(nouvelleVitesse>=0)
            vitesse = nouvelleVitesse;
    }

    public int getVitesse(){
        return vitesse;
    }

    public void run(){
        while(enCourse()){
            System.out.println(this);
            epreuve.avancer(this);
            try {
                sleep(dureePause);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public boolean enCourse(){
        return enCourse;
    }

    public void finCourse(){
        enCourse = false;
    }

    public void passageSecret(){
        easterEgg = true;
    }

    public boolean trouverEasterEgg(){
        return easterEgg;
    }

    public void setPiste(int nouvellePiste){
        piste = nouvellePiste;
    }

    @Override
    public String toString(){
        return getInformation()+"  - Case: "+position+" Piste: "+piste;
    }
}
