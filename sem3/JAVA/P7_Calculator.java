// Q7. Construct a Simple Calculator using the JAVA Swings with minimum functionality.

package calculator;
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
        txtnumber1 = new javax.swing.JTextField();
        txtnumber2 = new javax.swing.JTextField();
        btnadd = new javax.swing.JButton();
        btnsub = new javax.swing.JButton();
        btnmul = new javax.swing.JButton();
        btndiv = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Simple Calculator");
        getContentPane().setLayout(null);

        jLabel1.setText("Number 1");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(52, 25, 100, 16);

        jLabel2.setText("Number 2");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(52, 72, 100, 16);
        getContentPane().add(txtnumber1);
        txtnumber1.setBounds(231, 20, 120, 22);
        getContentPane().add(txtnumber2);
        txtnumber2.setBounds(231, 70, 120, 22);

        btnadd.setText("ADD");
        btnadd.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnaddActionPerformed(evt);
            }
        });
        getContentPane().add(btnadd);
        btnadd.setBounds(50, 140, 100, 50);

        btnsub.setText("SUB");
        btnsub.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnsubActionPerformed(evt);
            }
        });
        getContentPane().add(btnsub);
        btnsub.setBounds(50, 210, 100, 50);

        btnmul.setText("MUL");
        btnmul.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnmulActionPerformed(evt);
            }
        });
        getContentPane().add(btnmul);
        btnmul.setBounds(250, 140, 110, 50);

        btndiv.setText("DIV");
        btndiv.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btndivActionPerformed(evt);
            }
        });
        getContentPane().add(btndiv);
        btndiv.setBounds(250, 210, 110, 50);

        setSize(new java.awt.Dimension(542, 380));
        setLocationRelativeTo(null);
    }// </editor-fold>                        

    private void btnaddActionPerformed(java.awt.event.ActionEvent evt) {                                       
        String num1=txtnumber1.getText();
        String num2=txtnumber2.getText();
        
        int a=Integer.parseInt(num1);
        int b=Integer.parseInt(num2);
        int c=a+b;
        
        JOptionPane.showMessageDialog(this,"Add: "+c);
        
    }                                      

    private void btnsubActionPerformed(java.awt.event.ActionEvent evt) {                                       
        String num1=txtnumber1.getText();
        String num2=txtnumber2.getText();
        
        int a=Integer.parseInt(num1);
        int b=Integer.parseInt(num2);
        int c=a-b;
        
        JOptionPane.showMessageDialog(this,"Sub: "+ c);
        
    }                                      

    private void btnmulActionPerformed(java.awt.event.ActionEvent evt) {                                       
        String num1=txtnumber1.getText();
        String num2=txtnumber2.getText();
        
        int a=Integer.parseInt(num1);
        int b=Integer.parseInt(num2);
        
        int c=a*b;
        JOptionPane.showMessageDialog(this,"Mul: "+c);
    }                                      

    private void btndivActionPerformed(java.awt.event.ActionEvent evt) {                                       
        String num1=txtnumber1.getText();
        String num2=txtnumber2.getText();
        
        int a=Integer.parseInt(num1);
        int b=Integer.parseInt(num2);
        
        int c=a/b;
        JOptionPane.showMessageDialog(this,"Div: "+c);
        
    }                                      

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainform().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton btnadd;
    private javax.swing.JButton btndiv;
    private javax.swing.JButton btnmul;
    private javax.swing.JButton btnsub;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField txtnumber1;
    private javax.swing.JTextField txtnumber2;
    // End of variables declaration                   
}
