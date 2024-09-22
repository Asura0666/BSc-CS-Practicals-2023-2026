// Q9. Construct a simple Login using the JAVA Swings with minimum functionality.

package login;
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
        txtuser = new javax.swing.JTextField();
        txtpass = new javax.swing.JTextField();
        btnlogin = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Login");
        getContentPane().setLayout(null);

        jLabel1.setText("Username");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(39, 28, 80, 16);

        jLabel2.setText("Password");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(39, 76, 80, 16);
        getContentPane().add(txtuser);
        txtuser.setBounds(179, 25, 140, 22);
        getContentPane().add(txtpass);
        txtpass.setBounds(179, 73, 140, 22);

        btnlogin.setText("Login");
        btnlogin.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnloginActionPerformed(evt);
            }
        });
        getContentPane().add(btnlogin);
        btnlogin.setBounds(130, 160, 110, 40);

        setSize(new java.awt.Dimension(414, 307));
        setLocationRelativeTo(null);
    }// </editor-fold>                        

    private void btnloginActionPerformed(java.awt.event.ActionEvent evt) {                                         
        String user=txtuser.getText();
        String pass=txtpass.getText();
        
        if(user.equals("kirti")&&pass.equals("123456")){
            JOptionPane.showMessageDialog(rootPane,"Successfull");
        }
        else{
            JOptionPane.showMessageDialog(rootPane,"Unsuccessfull");
        }
        
        txtuser.setText("");
        txtpass.setText("");
        
    }                                        

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainform().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton btnlogin;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField txtpass;
    private javax.swing.JTextField txtuser;
    // End of variables declaration                   
}
