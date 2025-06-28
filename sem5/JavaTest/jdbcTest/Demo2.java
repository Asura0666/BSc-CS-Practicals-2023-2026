package jdbcTest;

import java.sql.*;

public class Demo2 {

  public static void main(String[] args) {

    String url = "jdbc:mysql://localhost:3306/testdb";
    String user = "root";
    String password = "yourpassword";

    try {
      Class.forName("com.mysql.cj.jdbc.Driver");

      Connection con = DriverManager.getConnection(url, user, password);
      Statement st = con.createStatement();

      ResultSet sel = st.executeQuery("SELECT * FROM Login");

      System.out.println("Fetched Records:");
      while (sel.next()) {
        String name = sel.getString(1);
        String pass = sel.getString(2);

        System.out.println("User: " + name + ", Password: " + pass);
      }

      sel.close();
      st.close();
      con.close();

    } catch (Exception e) {
      System.out.println("Error: " + e.getMessage());
    }

  }
}