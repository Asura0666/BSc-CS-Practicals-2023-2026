package jdbcTest;

import java.sql.*;

public class Demo3 {
  public static void main(String[] args) {
    String url = "jdbc:mysql://localhost:3306/testdb";
    String user = "root";
    String password = "yourpassword";

    try {
      Class.forName("com.mysql.cj.jdbc.Driver");

      Connection con = DriverManager.getConnection(url, user, password);
      Statement st = con.createStatement();

      ResultSet rs = st.executeQuery("SELECT * FROM Login");
      ResultSetMetaData rsmd = rs.getMetaData();

      System.out.println("Displaying Values...");

      for (int i = 1; i <= rsmd.getColumnCount(); i++) {
        System.out.print(rsmd.getColumnName(i) + "\t");
      }

      System.out.println("\n");

      while (rs.next()) {
        System.out.println(rs.getString(1) + "\t" + rs.getString(2));
      }

      rs.close();
      st.close();
      con.close();

    } catch (Exception e) {
      System.out.println("Error: " + e.getMessage());
    }
  }
}
