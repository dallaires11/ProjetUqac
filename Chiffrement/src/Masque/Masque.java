package Masque;

import java.io.File;

public class Masque {

    public static double genererMasque(double cle,int rappel){
        System.out.println (cle);
        double masque =  ((Math.pow(cle,5)))%7919;

        if(rappel<10)
            masque = genererMasque(masque,++rappel);

        return masque;
    }

    public static void main (String [] args){
        for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);
        }

        if (args.length < 2 )
            return;
        String cleString  = args[0];
        String longueurString = args[1];

        try{
            double cle = Double.parseDouble(cleString);
            int longueur = Integer.parseInt(longueurString);
            double masque = genererMasque(cle,0);

        }catch (NumberFormatException e){
            System.out.println("Erreur - Veuillez entrer des parametres valides");
        }

        //File file = new File("Masque.txt");

        return;
    }


}