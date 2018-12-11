package Model;

import Interface.Inscription;
import Model.Participants.*;

public class ParticipantFactory extends Thread{
    private boolean finEpreuve;
    private int delai;
    private Inscription inscription;

    public ParticipantFactory(Inscription inscription,int delai){
        this.inscription = inscription;
        this.delai = delai;
    }

    public void run(){
        while(!inscription.estTerminee()){
            inscription.ajouterParticipant(ajouterParticipant());
            try {
                sleep(delai);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private Participant ajouterParticipant(){
        int type  =(int) (Math.random()*5);
        Participant monParticipant;

        switch (type){
            case 0:
                monParticipant = new ParticipantA();
                break;
            case 1:
                monParticipant = new ParticipantB();
                break;
            case 2:
                monParticipant = new ParticipantC();
                break;
            case 3:
                monParticipant = new ParticipantD();
                break;
            default:
                monParticipant = new ParticipantE();
                break;
        }
        return monParticipant;
    }
}
