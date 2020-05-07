package com.jetbrains;
import java.io.*;


public class Main {

    public static void main(String[] args) throws IOException{
        try {
            FileReader source_f=new FileReader("input.txt");

            FileWriter dest_f=new FileWriter("output.txt");

            int ch = source_f.read();
            while(ch!=-1)
            {
                dest_f.write(ch);
                ch = source_f.read();
            }
            source_f.close();
            dest_f.close();
        }
        catch(Exception e){
            System.out.print(e);
        }



    }

}