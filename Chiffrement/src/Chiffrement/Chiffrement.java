package Chiffrement;

import java.io.*;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;
import java.util.Vector;


public class Chiffrement  {

    public static int masque (short i, int j) throws Exception
    {

        if (j>127)
            j %=127;
        i^=j;
        //System.out.println(i);
        return i;
    }



    public static void main (String args[])throws Exception{
        /*for(int i=0;i< args.length;i++)
        {
            System.out.println(args[i]);
        }*/

        if (args.length < 2 )
            return;

        String cle = args[0];
        String nomFichierInput = args[1];
        //System.out.println(nomFichierInput);
        File file = new File(nomFichierInput);
        System.out.println(file);
        FileReader fr = new FileReader(file);
        /*short test =0;
        short i[] = new short[255];
        while(test<255) {
            i[test]=masque(test, 1);
            for(short j =0; j<test; j++){
                if (i[j]==i[test]) {
                    System.out.print("erreur");
                }
            }
            test++;
        }*/
        int i =0;
        short x = 0;
        short temp = 0;
        int e =0;
        char cast=' ';
        //Vector<Character> buffer = new Vector<Character>();

        int p = 0;
        while((i=fr.read())!=-1) {
            p++;
        }
        fr.close();
        FileReader fr2 = new FileReader(file);
        char buffer[] = new char[p];
        p = 0;
        //System.out.println(buffer.length);
        BufferedWriter writer = new BufferedWriter(new FileWriter("test.txt"));
        while((i=fr2.read())!=-1) {
            //fonction pour chiffré ici avec chaque caractère (i)
            x= (short)i;
            //System.out.print(x);
            //System.out.print( (char)i);
            e = masque(x,Integer.parseInt(args[0]));
            //System.out.print( e);
            //System.out.print( i);
            buffer[p]=(char)e;
            writer.write(buffer[p]);
            p++;
            //System.out.print( (char)e);
        }
        fr2.close();
        writer.close();
        return;
    }
}
