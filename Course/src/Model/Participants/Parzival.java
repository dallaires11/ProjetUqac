package Model.Participants;

import Model.Participant;

public class Parzival extends Participant {
    public Parzival(){
        super(5, "DeLorean");
    }

    public void accelerer(){

        setVitesse(getVitesse() + 1);
    }

    public void ralentir(){

        setVitesse(getVitesse() - 1);
    }
}
