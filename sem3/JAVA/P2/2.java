abstract class bike {
  bike() {
    System.out.println("bike is created");
  }

  abstract void run();

  void GearChanged() {
    System.out.println("Changing Gear");
  }
}

class Honda extends bike {
  public void run() {
    System.out.println("running....");
  }
}

class AbstractTest {
  public static void main(String args[]) {
    Honda obj = new Honda();
    obj.run();
    obj.GearChanged();
  }
}
