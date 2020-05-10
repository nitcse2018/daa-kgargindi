package com.jetbrains;
import java.util.*;




class Producer extends Thread {

    private  int SIZE = 5;
    private  List<Integer>store = new ArrayList<>();

    @Override
    public void run() {
        try {
            while (true) {
                produce();
            }
        } catch (Exception exp) {
        }
    }

    private synchronized void produce() throws Exception {
        while (store.size() == SIZE) {
            System.out.println("Store limit reached.");
            wait();

        }
        Random rand=new Random();
        int i=rand.nextInt(100);
        store.add(i);
        System.out.println("Producer produced data");
        notify();
    }

    public synchronized Integer consume() throws Exception {
        notify();
        while (store.isEmpty()) {
            wait();
        }
       int data = store.get(0);
        store.remove(data);
        return data;
    }
}

class Consumer extends Thread {

    private Producer producer;

    public Consumer(Producer producer) {
        this.producer = producer;
    }

    @Override
    public void run() {
        try {
            while (true) {
                int data = producer.consume();
                System.out.println("Consumed "  + data);
                Thread.sleep(500);
            }
        } catch (Exception exp) {
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Producer p = new Producer();
        Consumer c = new Consumer(p);
        c.start();
        p.start();

    }
}
