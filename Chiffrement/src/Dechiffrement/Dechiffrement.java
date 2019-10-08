package Dechiffrement;

import java.io.*;


public class Dechiffrement {

    public static void main (String args[] )throws Exception{
        for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);
        }

        if (args.length < 2 )
            return;

        String cle = args[0];
        String nomFichierOutput = args[1];
        File file = new File(nomFichierOutput);
        System.out.println(file);
        FileReader fr = new FileReader(file);
        int i = 0;
        while((i=fr.read())!=-1)
            // fonction pour déchifré ici avec chaque caractère (i)
            System.out.print((char)i);
        fr.close();
        return;
    }
}

