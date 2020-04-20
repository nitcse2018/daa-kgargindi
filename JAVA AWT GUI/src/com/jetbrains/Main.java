package com.jetbrains;

import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        my_frame f = new my_frame();
        f.setVisible(true);
        f.setSize(500, 500);
        f.setLocation(100, 100);
    }
}

class my_frame extends Frame {

    my_frame() {
        super("Resume Builder Personal");
        String[] labels = {"First Name", "Last Name", "City", "Zip Code", "Country", "Phone", "Email"};

        Label[] myLabels = new Label[7];
        TextField[] myTexts = new TextField[7];

        for (int i = 0; i < myLabels.length; i++) {
            myLabels[i] = new Label(labels[i]);
            myTexts[i] = new TextField(20);
        }


        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        Button b = new Button("NEXT");

        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                try {
                    FileWriter myWriter = new FileWriter("file.txt");
                    for (int i = 0; i < myTexts.length; i++) {
                        myWriter.write(myLabels[i].getText() + ":  " + myTexts[i].getText() + "\r");

                    }

                    myWriter.close();
                    System.out.println("Successfully wrote to the file.");
                } catch (IOException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
                dispose();
                my_frame_2 f2 = new my_frame_2();
                f2.setVisible(true);
                f2.setSize(500, 500);
                f2.setLocation(100, 100);
            }
        });
        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(2, 2, 2, 2);
        c.anchor = GridBagConstraints.NORTHWEST;
        int t;
        for (t = 0; t < myLabels.length; t++) {
            c.gridx = 1;
            c.gridy = t;
            add(myLabels[t], c);

            c.gridx = 2;
            c.gridy = t;
            add(myTexts[t], c);
        }
        c.gridx = 1;
        c.gridy = t;
        add(b, c);
    }
}

class my_frame_2 extends Frame {

    my_frame_2() {
        super("Resume Builder Qualification");
        String[] labels = {"Institute", "Highest Qualification", "Field of Study", "Place of Study"};

        Label[] myLabels = new Label[4];
        TextField t1 = new TextField(20);
        TextField t2 = new TextField(20);
        Choice pick = new Choice();
        Choice pick2 = new Choice();


        for (int i = 0; i < myLabels.length; i++) {
            myLabels[i] = new Label(labels[i]);
        }


        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        Button b = new Button("NEXT");

        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                try {
                    FileWriter myWriter = new FileWriter("file.txt",true);

                    myWriter.write(myLabels[0].getText() + ":  " + t1.getText() + "\r");
                    myWriter.write(myLabels[1].getText() + ":  " + pick.getSelectedItem() + "\r");
                    myWriter.write(myLabels[2].getText() + ":  " + pick2.getSelectedItem() + "\r");
                    myWriter.write(myLabels[3].getText() + ":  " + t2.getText() + "\r");



                    myWriter.close();
                    System.out.println("Successfully wrote to the file.");
                } catch (IOException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
                my_frame_3 f3 = new my_frame_3();
                f3.setVisible(true);
                f3.setSize(500, 500);
                f3.setLocation(100, 100);
                dispose();

            }
        });
        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(2, 2, 0, 0);
        c.anchor = GridBagConstraints.NORTHWEST;

        int t;
        for (t = 0; t < myLabels.length; t++) {
            c.gridx = 1;
            c.gridy = t;
            add(myLabels[t], c);
        }
        c.gridx = 3;
        c.gridy = 0;

        add(t1, c);
        c.gridx = 3;
        c.gridy = 1;

        pick.add("None");
        pick.add("Elementary");
        pick.add("Secondary");
        pick.add("Senior-Secondary");
        pick.add("Diploma");
        pick.add("Graduation");
        pick.add("Post-Graduation");
        add(pick, c);
        c.gridx = 3;
        c.gridy = 2;

        pick2.add("None");
        pick2.add("Science");
        pick2.add("Maths");
        pick2.add("Arts");
        pick2.add("Engineering");
        pick2.add("Medicine");
        pick2.add("Law");
        pick2.add("Commerce");
        add(pick2, c);
        c.gridx = 3;
        c.gridy = 3;

        add(t2, c);
        c.gridx = 2;
        c.gridy = 4;
        add(b, c);

    }


}

class my_frame_3 extends Frame {

    my_frame_3() {
        super("Resume Builder Skill Level");
        String[] labels = {"Experience(yrs)", "Skill-Level", "Skill-Level", "Hobby"};

        Label[] myLabels = new Label[4];
        TextField t1 = new TextField("eg: Python3",20);
        TextField t2 = new TextField("eg: Professional Communication",20);
        TextField t3= new TextField("eg: Surfing",20);
        Choice pick = new Choice();
        Choice pick2 = new Choice();
        Choice pick3 = new Choice();


        for (int i = 0; i < myLabels.length; i++) {
            myLabels[i] = new Label(labels[i]);
        }


        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        Button b = new Button("SUBMIT");

        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                try {
                    FileWriter myWriter = new FileWriter("file.txt",true);

                    myWriter.write(myLabels[0].getText() + ":  " + pick.getSelectedItem() + "\r");
                    myWriter.write(myLabels[1].getText() + ":  " + t1.getText()+"   "+pick2.getSelectedItem() + "\r");
                    myWriter.write(myLabels[2].getText() + ":  " + t2.getText()+"   "+pick3.getSelectedItem() + "\r");
                    myWriter.write(myLabels[3].getText() + ":  " + t3.getText() + "\r");



                    myWriter.close();
                    System.out.println("Successfully wrote to the file.");
                } catch (IOException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
                dispose();

            }
        });
        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(2, 2, 0, 0);
        c.anchor = GridBagConstraints.NORTHWEST;
        int t;
        for (t = 0; t < myLabels.length; t++) {
            c.gridx = 1;
            c.gridy = t;
            add(myLabels[t], c);
        }
        c.gridx = 2;
        c.gridy = 0;
        pick.add("Fresher");
        pick.add("0-1");
        pick.add("1-5");
        pick.add("5+");
        add(pick, c);
        c.gridx = 2;
        c.gridy = 1;
        add(t1,c);
        c.gridx = 3;
        c.gridy = 1;

        pick2.add("★");
        pick2.add("★★");
        pick2.add("★★★");
        pick2.add("★★★★");
        pick2.add("★★★★★");
        add(pick2, c);
        c.gridx = 2;
        c.gridy = 2;
        add(t2,c);
        c.gridx = 3;
        c.gridy = 2;

        pick3.add("★");
        pick3.add("★★");
        pick3.add("★★★");
        pick3.add("★★★★");
        pick3.add("★★★★★");
        add(pick3, c);
        c.gridx = 2;
        c.gridy = 3;
        add(t3,c);
        c.gridx = 2;
        c.gridy = 4;
        add(b, c);
    }
}



