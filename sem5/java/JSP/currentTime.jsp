<%@page language="java" contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"%>
<%@page import="java.util.Date"%>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>JSP Current Time</title>
</head>
<body>
    <h1>Current Server Time</h1>
    <p>
        <%
            Date currentTime=new Date();
        %>
        <%=currentTime%>
    </p>
</body>
</html>