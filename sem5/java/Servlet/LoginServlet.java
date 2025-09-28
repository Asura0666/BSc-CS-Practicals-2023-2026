import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/login"})
public class LoginServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // Hardcoded credentials
        String username = "admin";
        String password = "root";
        
        // Check if credentials match
        if (username.equals("admin") && password.equals("root")) {
            out.println("<h1>Hello</h1>");
        } else {
            out.println("<h1>Login failed</h1>");
        }
    }
}