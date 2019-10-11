package Dechiffrement;

import java.io.*;


public class Dechiffrement {

    public static int masque (short i, int j) throws Exception
    {

        if (j>127)
            j %=127;
        i^=j;
        //System.out.println(i);
        return i;
    }

    public static void main (String args[] )throws Exception{
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
        p = 0;
        //System.out.print( "tesT"+(char)e);
        FileReader fr2 = new FileReader(args[1]);
        BufferedWriter writer = new BufferedWriter(new FileWriter("test2.txt"));
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
        }
        fr2.close();
        writer.close();
        return;
    }
}

