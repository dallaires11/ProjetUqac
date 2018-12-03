package Model;

import Interface.Inscription;

public class ParticipantFactory {
    private final int INTERVALLE_MAX=2000;
    private boolean finEpreuve;
    private int delai;
    private Inscription inscription;

    public ParticipantFactory(Inscription inscription,int delai){
        this.inscription = inscription;
        this.delai = delai;
    }

    public void run(){

    }

    private Participant ajouterParticipant(){
        return null;
    }
}
