import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/sumdirect"})
public class SummationDirectServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<h1>Summation Calculator</h1>");

        int n = 10;   // input directly in code
        int sum = 0;
        
        for(int i = 1; i <= n; i++)
            sum += i;
            
        out.println("<p>Sum from 1 to " + n + " is " + sum + "</p>");
        
    }
}