class Student {
  int rollno;
  String name;
  static String clg_name = "IIT";

  static void change() {
    clg_name = "Kirti";
  }

  Student(int r, String n) {
    rollno = r;
    name = n;
  }

  void display() {
    System.out.println(rollno + " " + name + " " + clg_name);
  }

  public static void main(String args[]) {
    Student.change();
    Student s1 = new Student(111, "Sakshi");
    Student s2 = new Student(222, "Urvi");

    s1.display();
    s2.display();

  }
}
