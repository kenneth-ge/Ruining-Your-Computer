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
    while (System.currentTimeMillis() - start < 10000L) {
      r.mouseMove(random.nextInt(width), random.nextInt(height));
      Thread.sleep(15L);
    } 
  }
}
