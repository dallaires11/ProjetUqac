package Chiffrement;

import java.io.*;

public class Chiffrement {





    public static void main (String args[])throws Exception{
        for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);
        }

        if (args.length < 2 )
            return;

        String cle = args[0];
        String nomFichierInput = args[1];
        System.out.println(nomFichierInput);
        File file = new File(nomFichierInput);
        System.out.println(file);
        FileReader fr = new FileReader(file);
        int i = 0;
        while((i=fr.read())!=-1)
            //fonction pour chiffré ici avec chaque caractère (i)
            System.out.print((char)i);
        fr.close();




        return;
    }



}
