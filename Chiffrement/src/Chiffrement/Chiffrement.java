package Chiffrement;

import java.io.File;

public class Chiffrement {





    public static void main (String [] args){
        for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);
        }

        if (args.length < 2 )
            return;

        String cle = args[0];
        String nomFichierInput = args[1];
        File file = new File(nomFichierInput);

        return;
    }



}
