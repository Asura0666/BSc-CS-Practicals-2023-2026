// Q8. Construct a GUI using JAVA Swings to accept details of a record of a given table and submit it to the database using JDBC technology on the click of a button.


package javaapplication20;

import java.sql.*;
import javax.swing.JOptionPane;

public class mainform extends javax.swing.JFrame {

    public mainform() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        txtid = new javax.swing.JTextField();
        txtname = new javax.swing.JTextField();
        txtage = new javax.swing.JTextField();
        txtaddress = new javax.swing.JTextField();
        btninsert = new javax.swing.JButton();
        btndelete = new javax.swing.JButton();
        btnupdate = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        jLabel1.setText("Studid");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(50, 20, 90, 30);

        jLabel2.setText("Name");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(50, 70, 90, 30);

        jLabel3.setText("Age");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(50, 180, 90, 30);

        jLabel4.setText("Address");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(50, 120, 90, 30);
        getContentPane().add(txtid);
        txtid.setBounds(220, 20, 130, 22);
        getContentPane().add(txtname);
        txtname.setBounds(220, 70, 130, 22);
        getContentPane().add(txtage);
        txtage.setBounds(220, 180, 130, 22);
        getContentPane().add(txtaddress);
        txtaddress.setBounds(220, 120, 130, 22);

        btninsert.setText("Insert");
        btninsert.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btninsertActionPerformed(evt);
            }
        });
        getContentPane().add(btninsert);
        btninsert.setBounds(50, 260, 100, 40);

        btndelete.setText("Delete");
        btndelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btndeleteActionPerformed(evt);
            }
        });
        getContentPane().add(btndelete);
        btndelete.setBounds(210, 260, 100, 40);

        btnupdate.setText("Update");
        btnupdate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnupdateActionPerformed(evt);
            }
        });
        getContentPane().add(btnupdate);
        btnupdate.setBounds(380, 260, 100, 40);

        setSize(new java.awt.Dimension(600, 428));
        setLocationRelativeTo(null);
    }// </editor-fold>                        

    private void btninsertActionPerformed(java.awt.event.ActionEvent evt) {                                          
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="insert into Student values(?,?,?,?)";
            PreparedStatement ps=con.prepareStatement(query);
            
            
            String id=txtid.getText();
            String name=txtname.getText();
            String address=txtaddress.getText();
            String age=txtage.getText();
            
            ps.setString(1,id);
            ps.setString(2,name);
            ps.setString(3,address);
            ps.setString(4,age);
            
            int rs=ps.executeUpdate();
            if(rs>0){
                JOptionPane.showMessageDialog(this,"Data Inserted");
            }
            
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }                                         

    private void btndeleteActionPerformed(java.awt.event.ActionEvent evt) {                                          
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="delete from student where studid=?";
            PreparedStatement ps=con.prepareStatement(query);
            
            String id=txtid.getText();
            
            ps.setString(1, id);
            
            int rs=ps.executeUpdate();
            if(rs>0){
                JOptionPane.showMessageDialog(this,"Data Deleted");
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }                                         

    private void btnupdateActionPerformed(java.awt.event.ActionEvent evt) {                                          
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String db="jdbc:mysql://localhost:3306/batch";
            String username="root";
            String password="123456";
            Connection con=DriverManager.getConnection(db,username,password);
            
            String query="update Student set name=?,address=?,age=? where studid=?";
            PreparedStatement ps=con.prepareStatement(query);
            
            String id=txtid.getText();
            String name=txtname.getText();
            String address=txtaddress.getText();
            String age=txtage.getText();
            
            ps.setString(1, name);
            ps.setString(2, address);
            ps.setString(3, age);
            ps.setString(4, id);
            
            int rs=ps.executeUpdate();
            
            if(rs>0){
                JOptionPane.showMessageDialog(this,"Data Updated");
            }

            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }                                         


    public static void main(String args[]) {
        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainform().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton btndelete;
    private javax.swing.JButton btninsert;
    private javax.swing.JButton btnupdate;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JTextField txtaddress;
    private javax.swing.JTextField txtage;
    private javax.swing.JTextField txtid;
    private javax.swing.JTextField txtname;
    // End of variables declaration                   
}
