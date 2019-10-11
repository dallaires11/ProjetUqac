package Masque;

import java.io.File;
import java.util.Random;

public class Masque {



    public static void main (String [] args){

        int buffer[]= new int[Integer.parseInt (args[1])];
        Random randomGenerator = new Random();
        randomGenerator.setSeed(Integer.parseInt(args[0]));
        for(int i =0; i<Integer.parseInt (args[1]); i++){
            buffer[i]=randomGenerator.nextInt();
            System.out.print(buffer[i]);
        }

        return;
    }


}
