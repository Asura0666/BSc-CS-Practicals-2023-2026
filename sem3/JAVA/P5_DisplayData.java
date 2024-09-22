// Q5. Write a JDBC program that displays the data of a given table.

package select;
import java.sql.*;

public class Select {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="select * from student;";
            Statement stmt=con.createStatement();
            ResultSet rs=stmt.executeQuery(query);
            
            while(rs.next()){
                String id=rs.getString("studid");
                String name=rs.getString("name");
                String address=rs.getString("address");
                String age=rs.getString("age");
                
                System.out.println(id+" "+name+" "+address+" "+age);
            }
           
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}