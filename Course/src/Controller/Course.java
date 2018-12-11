package Controller;

import Controller.Util.Logger;
import Interface.Epreuve;
import Interface.Inscription;
import Model.Exceptions.CollisionException;
import Model.Exceptions.ObstacleException;
import Model.Exceptions.PisteException;
import Model.Obstacle.Obstacle;
import Model.Participant;
import Model.Participants.Parzival;

import java.util.Random;

public class Course implements Inscription, Epreuve {
    private final int DISTANCE_COURSE = 100;
    private  final  int NOMBRE_PISTE = 4;
    private int delai;
    private boolean start,terminee,manuel;
    private Participant gagnant;
    private Logger logger;

    private Object[][] piste = new Object[DISTANCE_COURSE][NOMBRE_PISTE];

    public Course(Participant joueur,int delai,Logger logger){
        this.delai = delai;
        ajouterParticipant(joueur);
        setPiste();
        start = false;
        terminee =false;
        manuel = false;
        this.logger = logger;

        //piste[12][0] =  new Obstacle();
        //piste[23][0] = new ParticipantA();
    }

    public void ajouterParticipant(Participant participant){
        for (int x=0;x<NOMBRE_PISTE;x++){
            if(piste[0][x]==null) {
                piste[0][x] = participant;
                participant.setDepart(this,x,delai);
                //signalDepart();
                if(start)
                    participant.start();
                return;
            }
        }
        //Quand la piste est pleine pour la première fois
        if(!start){
            signalDepart();
        }
        System.out.println("Pas de piste disponible pour "+participant.getInformation());
    }

    private void signalDepart(){
        start=true;
        for (int x = 0;x< NOMBRE_PISTE;x++){
            if(piste[0][x] instanceof Participant)
                ((Participant) piste[0][x]).start();
        }
    }

    public synchronized void avancer(Participant participant){
        if(!terminee){
            //System.out.println("J'avance");
            try {
                gererCollision(participant);

                piste[participant.getPosition()][participant.getCurrentPiste()] = null;
                participant.setPosition(participant.getPosition()+participant.getVitesse());
                if(participant.getPosition()>=DISTANCE_COURSE)
                    piste[99][participant.getCurrentPiste()] = participant;
                else
                    piste[participant.getPosition()][participant.getCurrentPiste()] = participant;
            }catch (CollisionException ce){
                System.out.println(ce.getMessage());
                if(participant instanceof Parzival)
                    terminee = true;
                participant.finCourse();
            } catch (ObstacleException oe){
                System.out.println(oe.getMessage());
                if(participant instanceof Parzival)
                    terminee = true;
                participant.finCourse();
            }
        }else
            participant.finCourse();
    }

    private boolean gererCollisionObstacle(){
        Random generator = new Random();
        int alive = generator.nextInt(10)+1;
        if(alive>=7)
            return true;
        else
            return false;
    }

    private void gererCollision(int nouvellePiste,Participant participant) throws CollisionException, ObstacleException {
        gererCollisionEntite(0,participant,nouvellePiste);
    }

    private void gererCollisionEntite(int deplacement,Participant participant,int pisteCur) throws CollisionException, ObstacleException {
        int positionIni = participant.getPosition();
        if(deplacement>=0) {
            for(int x=0;x<=deplacement;x++){
                if(positionIni+x<DISTANCE_COURSE) {
                    if (piste[positionIni+x][pisteCur] != null&&piste[positionIni+x][pisteCur] != participant){
                        if (piste[positionIni+x][pisteCur] instanceof Obstacle){
                            if(gererCollisionObstacle()){
                                participant.setPosition(positionIni+x);//Pour voir case exact de l'accident n'affecte pas le tableau
                                piste[positionIni][pisteCur] = null;
                                logger.raceEvent(participant+" collision avec obstacle");
                                throw new ObstacleException();
                            }
                        }
                        else{
                            participant.setPosition(positionIni+x);//Pour voir case exact de l'accident n'affecte pas le tableau
                            logger.raceEvent(participant+" collision avec "+(piste[positionIni+x][pisteCur]));
                            piste[positionIni][pisteCur] = null;
                            if(!(piste[positionIni+x][pisteCur] instanceof Parzival)|!manuel){
                                ((Participant)piste[positionIni+x][pisteCur]) .finCourse();
                                piste[positionIni+x][pisteCur] = new Obstacle();
                            }
                            throw new CollisionException();
                        }
                    }
                }
            }
        }
        //NE PAS OUBLIER LE MOUVEMENT PHYSIQYE DANS LE TABLEAU
        else if (deplacement<0){
            for(int x=0;x>=deplacement;x--){
                if(positionIni+x>=0) {
                    if (piste[positionIni+x][pisteCur] != null &&piste[positionIni+x][pisteCur] != participant){
                        if (piste[positionIni+x][pisteCur] instanceof Obstacle)
                            if(gererCollisionObstacle()){
                                participant.setPosition(positionIni+x);//Pour voir case exact de l'accident n'affecte pas le tableau
                                piste[positionIni][pisteCur] = null;
                                logger.raceEvent(participant+" collision avec obstacle");
                                throw new ObstacleException();
                            }
                            else{
                                participant.setPosition(positionIni+x);//Pour voir case exact de l'accident n'affecte pas le tableau
                                logger.raceEvent(participant+" collision avec "+(piste[positionIni+x][pisteCur]));
                                piste[positionIni][pisteCur] = null;
                                ((Participant)piste[positionIni+x][pisteCur]) .finCourse();
                                piste[positionIni+x][pisteCur] = new Obstacle();
                                throw new CollisionException();
                            }
                    }
                }
            }
        }
    }

    private void gererCollision(Participant participant) throws CollisionException, ObstacleException {
        int newPosition = participant.getPosition()+participant.getVitesse();
        if(!participant.trouverEasterEgg())
            gererCollisionEntite(newPosition-participant.getPosition(),participant,participant.getCurrentPiste());
        if (newPosition<0){
            participant.passageSecret();
        }else if(newPosition>=DISTANCE_COURSE){
            gagnant = participant;
            participant.finCourse();
            terminee = true;
        }
    }

    public String getInformation(Participant participant){
        return " ";
    }

    public void changerPiste(Participant participant,int nouvellePiste) {
        try{
            if(nouvellePiste<0||nouvellePiste>=NOMBRE_PISTE)
                throw new PisteException();
            gererCollision(nouvellePiste,participant);

            piste[participant.getPosition()][participant.getCurrentPiste()] = null;
            participant.setPiste(nouvellePiste);
            piste[participant.getPosition()][participant.getCurrentPiste()] = participant;
        } catch (PisteException pe) {
                System.out.println(pe.getMessage());
                terminee = true;
                participant.finCourse();
        } catch (CollisionException ce){
                System.out.println(ce.getMessage());
                terminee = true;
                participant.finCourse();
        } catch (ObstacleException oe){
                System.out.println(oe.getMessage());
                terminee = true;
                participant.finCourse();
        }
    }

    public Participant getGagnant(){
        return gagnant;
    }

    public boolean estTerminee(){
        return terminee;
    }

    public void setPiste(){
        setObstacle();
    }

    private void setObstacle(){
        int lastObstacle = 15;
        for(int y = 0;y<NOMBRE_PISTE;y++){
            lastObstacle += (int) (Math.random() * 9+9);
            for(int x = 0;x<DISTANCE_COURSE;x++){
                if(x==lastObstacle){
                    piste[x][y] = new Obstacle();
                    lastObstacle += (int) (Math.random() * 9) +9;
                }
            }
            lastObstacle = 15;
        }
    }

    public void setManuel(char choix){
        if(choix == 'Y' || choix == 'y')
            manuel = true;
        else
            manuel = false;
    }

    @Override
    public String toString(){
        return " ";
    }
}