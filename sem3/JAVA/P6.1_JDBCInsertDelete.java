// Q6. Write a JDBC program to insert/delete records into a given table.


//Insert

package insert;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.*;

public class Insert {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="insert into Student values(?,?,?,?);";
            PreparedStatement ps=con.prepareStatement(query);
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            
            do{
                System.out.println("Enter studid:");
                String id=br.readLine();
                System.out.println("Enter name:");
                String name=br.readLine();
                System.out.println("Enter address:");
                String address=br.readLine();
                System.out.println("Enter age:");
                String age=br.readLine();
                
                ps.setString(1, id);
                ps.setString(2, name);
                ps.setString(3, address);
                ps.setString(4, age);
                
                int rs=ps.executeUpdate();
                System.out.println(rs+"records affected");
                
                System.out.println("Do you want to continue: y/n");
                String s=br.readLine();
                if(s.startsWith("n")){
                    break;
                }
                
            }while(true);
            
       
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}

