package troll;

import java.awt.Dimension;
import java.awt.Robot;
import java.awt.Toolkit;
import java.util.Random;

public class Troll {
  public static void main(String[] args) throws Exception {
    Random random = new Random();
    Robot r = new Robot();
    Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
    int width = d.width;
    int height = d.height;
    long start = System.currentTimeMillis();
    r.mouseMove(0, height);
    r.mousePress(1024);
    r.mouseRelease(1024);
    Thread.sleep(200L);
    r.mouseMove(0, (int)(height * 0.9D));
    r.mousePress(1024);
    r.mouseRelease(1024);
    Thread.sleep(200L);
    r.mouseMove(50, (int)(height * 0.8D));
    r.mousePress(1024);
    r.mouseRelease(1024);
    Thread.sleep(200L);
    r.mousePress(1024);
    r.mouseRelease(1024);
    Thread.sleep(200L);
    r.mousePress(1024);
    r.mouseRelease(1024);
    Thread.sleep(200L);
    r.mousePress(1024);
    r.mouseRelease(1024);
  }
}
