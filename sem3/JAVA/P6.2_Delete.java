//Delete

package delete;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.*;

public class Delete {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="delete from Student where studid=?";
            PreparedStatement ps=con.prepareStatement(query);
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            
            do{
            System.out.println("Enter studid:");
            String id=br.readLine();
            ps.setString(1, id);
            
            int rs=ps.executeUpdate();
            if(rs>0){
                System.out.println("deleted successfully");
            }
            
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

