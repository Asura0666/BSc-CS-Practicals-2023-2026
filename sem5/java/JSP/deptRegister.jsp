<%@ page import="java.sql.*" %>
<%! 
    Connection con = null;
    Statement st = null;
    PreparedStatement ps = null;
%>
<%
try {
    Class.forName("com.mysql.cj.jdbc.Driver");
    String url="jdbc:mysql://localhost:3306/company?useSSL=false&ServerTimezone=UTC";
    String user="root";
    String password="root";

    con = DriverManager.getConnection(url, user, password);
    con.setAutoCommit(false);

    // Hardcoded department values
    int deptno = 10;
    String deptname = "SALES";
    String location = "NEW YORK";

    String query = "INSERT INTO dept (deptno, deptname, location) VALUES( ?, ?, ?)";
    ps = con.prepareStatement(query);
    ps.setInt(1, deptno);
    ps.setString(2, deptname);
    ps.setString(3, location);
    ps.executeUpdate();
    con.commit();

    st = con.createStatement();
    ResultSet rs = st.executeQuery("SELECT * FROM dept");
%>
<html>
<body>
<h2>Department Details</h2>
<table border="1">
<tr>
<th>Dept No</th>
<th>Dept Name</th>
<th>Location</th>
</tr>
<%
while (rs.next()) {
%>
<tr>
<td><%= rs.getInt("deptno") %></td>
<td><%= rs.getString("deptname") %></td>
<td><%= rs.getString("location") %></td>
</tr>
<%
}
rs.close();
} catch (Exception e) {
    out.println("<p>Error: " + e.getMessage() + "</p>");
}
%>
</table>
</body>
</html>

<%!
    public void jspDestroy() {
        try {
            if (ps != null) ps.close();
            if (st != null) st.close();
            if (con != null) con.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
%>
