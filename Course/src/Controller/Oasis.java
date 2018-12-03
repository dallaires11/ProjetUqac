package Controller;

import Interface.Epreuve;
import Model.Exceptions.CollisionException;
import Model.Exceptions.ObstacleException;
import Model.Exceptions.PisteException;
import Model.Participants.Parzival;

import java.util.Scanner;

public class Oasis {
    private Parzival parzival;
    private Epreuve epreuve;

    public static void main(String[] args) {

        Oasis oasis = new Oasis();
        oasis.debuterEpreuve();
    }

    public Oasis(){

        parzival = new Parzival();
        epreuve = new Course(parzival, 500);
    }

    public void debuterEpreuve(){

        int choix = 1;
        Scanner lectureClavier = new Scanner(System.in);

        try{

            do{
                System.out.println(epreuve.getInformation(parzival));
                menu();
                choix = lectureClavier.nextInt();

                switch(choix){
                    case 1: System.out.print("Piste > ");
                        epreuve.changerPiste(parzival, lectureClavier.nextInt());
                        break;
                    case 2: parzival.accelerer();
                        break;
                    case 3: parzival.ralentir();
                        break;
                }
            }
            while(parzival.enCourse() && !epreuve.estTerminee());
        }
        catch(CollisionException ce){

            System.out.println(ce.getMessage());
            ce.printStackTrace();
        }
        catch(PisteException pe){

            System.out.println(pe.getMessage());
            pe.printStackTrace();
        }
        catch(ObstacleException oe){

            System.out.println(oe.getMessage());
            oe.printStackTrace();
        }
        catch(Exception e){

            System.out.println(e.getMessage());
            e.printStackTrace();
        }

        if (epreuve.getGagnant() == null)
            System.out.println("Fin de l'epreuve!!");
        else
            System.out.println("Le gagnant est " + epreuve.getGagnant());
    }

    private void menu(){

        System.out.println();
        System.out.println("1 - Nouvelle piste...");
        System.out.println("2 - Accelerer");
        System.out.println("3 - Ralentir");
    }
}