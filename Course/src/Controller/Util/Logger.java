package Controller.Util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Logger {
    private BufferedWriter bf;

    public Logger(){
        try {
            bf = new BufferedWriter(new FileWriter(new File("src/Ressource/raceLog.log")));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void raceEvent(String log) {
        try {
            bf.write(log+"\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void closeLog(){
        try {
            bf.write("Thank you for playing");
            bf.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
