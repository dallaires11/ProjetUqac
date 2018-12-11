import Controller.Course;
import Controller.Oasis;
import Controller.Util.Logger;
import Model.ParticipantFactory;
import Model.Participants.Parzival;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        Logger logger= new Logger();
        Parzival parzival = new Parzival();
        Course course = new Course(parzival, 500,logger);
        Oasis oasis = new Oasis(course,parzival,sc);
        ParticipantFactory participantFactory = new ParticipantFactory(course,1000);

        System.out.println("Incaner Parzival?(Y/N)");
        char manuel = sc.next().charAt(0);
        course.setManuel(manuel);
        oasis.setManuel(manuel);
        participantFactory.start();
        oasis.debuterEpreuve();
        System.out.println("FIN DU JEU");

        try {
            participantFactory.join();
            parzival.join();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        if (course.getGagnant() == null)
            logger.raceEvent("Mort du personnage principal");
        else
            logger.raceEvent("Le gagnant est " + course.getGagnant());
        logger.closeLog();

            //Ajouter onkeyEvent et arreter Quand Dolerean se fait frapper
    }
}
