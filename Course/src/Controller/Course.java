package Controller;

import Interface.Epreuve;
import Interface.Inscription;
import Model.Exceptions.CollisionException;
import Model.Participant;

public class Course implements Inscription, Epreuve {
    public final int DISTANCE_COURSE = 100;
    public  final  int NOMBRE_PISTE = 4;

    //<<Property>> private Participant gagnant = null;

    public Course(Participant joueur,int delai){

    }

    public void ajouterObstacles(){

    }

    public void ajouterParticipant(Participant participant){

    }

    public void avancer(Participant participant){

    }

    private void gererCollision(int piste,int position,Participant participant){

    }

    public String getInformation(Participant participant){
        return " ";
    }

    private void appendIndicateurs(StringBuffer sb,int positionActuelle,int distance){

    }

    private void appendPiste(StringBuffer sb,int piste,int positionActuelle,int distance){

    }

    public void changerPiste(Participant participant,int nouvellePiste){

    }

    public int getNombresPistes(){
        return  NOMBRE_PISTE;
    }

    public boolean estTerminee(){
        return false;
    }

    @Override
    public String toString(){
        return " ";
    }
}