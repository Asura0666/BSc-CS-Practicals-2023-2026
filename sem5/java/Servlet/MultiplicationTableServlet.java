import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/multable"})
public class MultiplicationTableServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<h1>Multiplication Table</h1>");

        int n = 7;   // input directly in code
        
        out.println("<h2>Multiplication Table for " + n + "</h2>");
        for(int i = 1; i <= 10; i++) {
            int result = n * i;
            out.println("<p>" + n + " * " + i + " = " + result + "</p>");
        }
    }
}