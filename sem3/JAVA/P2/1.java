// concept of abstract classes and method 

interface Drawable {
  void Draw();
}

class rectangle implements Drawable {
  public void Draw() {
    System.out.println("Drawing Rectangle");
  }
}

class circle implements Drawable {
  public void Draw() {
    System.out.println("Drawing Circle");
  }
}

class InterfaceTest {
  public static void main(String args[]) {
    Drawable c = new circle();
    c.Draw();
    Drawable r = new rectangle();
    r.Draw();
  }
}
