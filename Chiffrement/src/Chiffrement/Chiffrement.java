package Chiffrement;

import java.io.*;
import java.util.Random;


public class Chiffrement {

    public static int chiffre (short caractere, int cle) throws Exception
    {

        if (cle>127)
            cle %=127;
        caractere^=cle;
        //System.out.println(i);
        return caractere;
    }

    public static int[] masque(int cle, int longueur){

        int buffer[]= new int[longueur];
        Random randomGenerator = new Random();
        randomGenerator.setSeed(cle);
        for(int i =0; i<longueur; i++){
            buffer[i]=randomGenerator.nextInt();
        }


        return buffer;
    }

    public static <Random> void main (String args[] )throws Exception{
        for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);

        }

        if (args.length < 2 ) {

            return;
        }
        FileReader fr = new FileReader(/*args[1]*/"test.txt");
        int i =0;
        short x = 0;
        short temp = 0;
        int e =0;
        char cast=' ';
        int p = 0;
        while((i=fr.read())!=-1) {
            p++;
        }
        fr.close();
        char buffer[] = new char[p];

        //System.out.print( "tesT"+(char)e);
        FileReader fr2 = new FileReader(args[1]);
        BufferedWriter writer = new BufferedWriter(new FileWriter("test.txt"));
        //int tampon[] = new int[p];
        int tampon[]= masque(Integer.parseInt(args[0]),p);
        p = 0;
        while((i=fr2.read())!=-1) {
            //fonction pour chiffré ici avec chaque caractère (i)

            x= (short)i;
            //System.out.print(x);
            //System.out.print( (char)i);
            e = chiffre(x,tampon[p]);
            //System.out.print( e);
            //System.out.print( i);
            buffer[p]=(char)e;
            writer.write(buffer[p]);
            p++;


        }
        fr2.close();



        writer.close();
        return;
    }
}
