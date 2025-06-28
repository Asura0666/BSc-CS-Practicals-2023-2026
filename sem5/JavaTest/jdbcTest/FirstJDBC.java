// java -cp ".;mysql-connector-j-9.3.0.jar" Demo3.java

package jdbcTest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class FirstJDBC {
    @SuppressWarnings({"UseSpecificCatch", "ConvertToTryWithResources"})
    public static void main(String[] args) {
        // Updated connection info
        String url = "jdbc:mysql://localhost:3306/testdb";
        String user = "root";
        String password = "yourpassword"; // same as in docker run

        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Connect to the MySQL container
            Connection con = DriverManager.getConnection(url, user, password);
            Statement st = con.createStatement();

            // Create table
            String createTable = "CREATE TABLE IF NOT EXISTS Login (UserName VARCHAR(50), Password VARCHAR(50))";
            st.executeUpdate(createTable);
            System.out.println("Table Created");

            // Insert records
            st.executeUpdate("INSERT INTO Login VALUES ('Raj','ghf')");
            st.executeUpdate("INSERT INTO Login VALUES ('Harsh','hhh')");
            st.executeUpdate("INSERT INTO Login VALUES ('Ram','gfg')");
            st.executeUpdate("INSERT INTO Login VALUES ('Raju','ggg')");
            st.executeUpdate("INSERT INTO Login VALUES ('Ramu','mmm')");

            System.out.println("Values Inserted");

            st.close();
            con.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
