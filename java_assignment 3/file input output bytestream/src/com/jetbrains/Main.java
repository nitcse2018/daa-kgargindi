package com.jetbrains;
import java.io.*;


public class Main {

    public static void main(String[] args) throws IOException{
        try {
            FileInputStream source_f=new FileInputStream("input.txt");

            FileOutputStream dest_f=new FileOutputStream("output.txt");

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