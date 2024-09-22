// Q4. Write a Program using various swing components to design Java applications to accept a student's resume. (Design Form)

package newpackage;
import javax.swing.JOptionPane;
public class mainform extends javax.swing.JFrame {
    public mainform() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        lblname = new javax.swing.JLabel();
        txtname = new javax.swing.JTextField();
        lblage = new javax.swing.JLabel();
        txtage = new javax.swing.JTextField();
        lblgender = new javax.swing.JLabel();
        rdmale = new javax.swing.JRadioButton();
        rdfemale = new javax.swing.JRadioButton();
        lblsports = new javax.swing.JLabel();
        jComboBox1 = new javax.swing.JComboBox<>();
        lbladdress = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        txtaddress = new javax.swing.JTextArea();
        btnadd = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Student's Resume");
        getContentPane().setLayout(null);

        lblname.setText("Name");
        getContentPane().add(lblname);
        lblname.setBounds(80, 20, 80, 30);
        getContentPane().add(txtname);
        txtname.setBounds(230, 22, 140, 30);

        lblage.setText("Age");
        getContentPane().add(lblage);
        lblage.setBounds(80, 80, 50, 16);
        getContentPane().add(txtage);
        txtage.setBounds(231, 80, 80, 22);

        lblgender.setText("Gender");
        getContentPane().add(lblgender);
        lblgender.setBounds(190, 130, 80, 16);

        buttonGroup1.add(rdmale);
        rdmale.setText("Male");
        getContentPane().add(rdmale);
        rdmale.setBounds(70, 170, 48, 21);

        buttonGroup1.add(rdfemale);
        rdfemale.setText("Female");
        getContentPane().add(rdfemale);
        rdfemale.setBounds(270, 170, 60, 21);

        lblsports.setText("Sports");
        getContentPane().add(lblsports);
        lblsports.setBounds(80, 230, 70, 16);

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Cricket", "Football", "Hockey", "Tennis" }));
        getContentPane().add(jComboBox1);
        jComboBox1.setBounds(230, 230, 110, 22);

        lbladdress.setText("Address");
        getContentPane().add(lbladdress);
        lbladdress.setBounds(80, 280, 80, 16);

        txtaddress.setColumns(20);
        txtaddress.setRows(5);
        jScrollPane1.setViewportView(txtaddress);

        getContentPane().add(jScrollPane1);
        jScrollPane1.setBounds(180, 270, 180, 60);

        btnadd.setText("ADD");
        btnadd.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnaddActionPerformed(evt);
            }
        });
        getContentPane().add(btnadd);
        btnadd.setBounds(180, 360, 72, 23);

        setSize(new java.awt.Dimension(489, 467));
        setLocationRelativeTo(null);
    }                       

    private void btnaddActionPerformed(java.awt.event.ActionEvent evt) {                                       
        String msg="";
    if(txtname.getText().trim().isEmpty()==false){
        msg=msg+"Name: "+txtname.getText()+"\n";
    }
    if(txtage.getText().trim().isEmpty()==false){
        msg=msg+"Age: "+txtage.getText()+"\n";
    }
    if(rdmale.isSelected()){
        msg=msg+"Gender: "+rdmale.getText()+"\n";
    }
    else if(rdfemale.isSelected()){
        msg=msg+"Gender: "+rdfemale.getText()+"\n";
    }
    
    msg=msg+"Sports: "+jComboBox1.getSelectedItem().toString()+"\n";
    
    if(txtaddress.getText().trim().isEmpty()==false){
        msg=msg+"Address: "+txtaddress.getText()+"\n";
    }
    
    
    
        
        JOptionPane.showMessageDialog(this, msg);
    }                                      

    public static void main(String args[]) {

        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(mainform.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(mainform.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(mainform.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(mainform.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
            java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mainform().setVisible(true);
            }
        });
    }

    private javax.swing.JButton btnadd;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lbladdress;
    private javax.swing.JLabel lblage;
    private javax.swing.JLabel lblgender;
    private javax.swing.JLabel lblname;
    private javax.swing.JLabel lblsports;
    private javax.swing.JRadioButton rdfemale;
    private javax.swing.JRadioButton rdmale;
    private javax.swing.JTextArea txtaddress;
    private javax.swing.JTextField txtage;
    private javax.swing.JTextField txtname;
}
