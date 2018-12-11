package Controller;

import Interface.Epreuve;
import Model.Exceptions.CollisionException;
import Model.Exceptions.ObstacleException;
import Model.Exceptions.PisteException;
import Model.ParticipantFactory;
import Model.Participants.Parzival;

import java.awt.event.KeyEvent;
import java.util.Scanner;

import static java.lang.Thread.sleep;

public class Oasis{
    private Parzival parzival;
    private Epreuve epreuve;
    private Scanner sc;
    private boolean manuel;
    private int choix;

    public Oasis(Epreuve epreuve,Parzival parzival,Scanner sc){
        this.parzival = parzival;
        this.epreuve = epreuve;
        this.sc = sc;
        manuel = false;
    }

    private void actionParzival(){
        switch (choix){
            case 1:
                parzival.accelerer();
                break;
            case 2:
                parzival.ralentir();
                break;
            case 3:
                epreuve.changerPiste(parzival,parzival.getCurrentPiste()-1);
                break;
            case 4:
                epreuve.changerPiste(parzival,parzival.getCurrentPiste()+1);
                break;
            default:
                break;
        }
    }

    private void menuParzival(){
        System.out.println("Choix");
        System.out.println("-Acceler (1)\n-Ralentir (2)\n-Changer piste haut (3)\n-Changer piste bas (4)");
        choix = sc.nextInt();

        actionParzival();
    }

    public void debuterEpreuve(){
        do{
            if(manuel){
                menuParzival();
            }

            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } while(parzival.enCourse() && !epreuve.estTerminee());
    }

    public void setManuel(char choix){
        if(choix=='Y' || choix=='y')
            manuel = true;
        else
            manuel = false;
    }
}