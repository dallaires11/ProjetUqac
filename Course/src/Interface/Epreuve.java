package Interface;

import Model.Exceptions.CollisionException;
import Model.Exceptions.ObstacleException;
import Model.Exceptions.PisteException;
import Model.Participant;

public interface Epreuve {
    //<<Property>>public int nbPistes;
    //<<Property>>public Participant gagnant;

    public void avancer(Participant participant);
    public String getInformation(Participant participant);
    public void changerPiste(Participant participant,int nouvellePiste);
    public boolean estTerminee();
    public Participant getGagnant();
    public void setPiste();
}