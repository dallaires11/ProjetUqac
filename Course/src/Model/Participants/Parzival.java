package Model.Participants;

import Model.Participant;

public class Parzival extends Participant {
    public Parzival(){
        super(0, "DeLorean");
        System.out.println("New Parzival");
    }

    public void accelerer(){

        setVitesse(getVitesse() + 1);
    }

    public void ralentir(){
        setVitesse(getVitesse() - 1);
    }
}
