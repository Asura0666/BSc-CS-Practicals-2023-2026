import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/timedirect"})
public class TimeConversionServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<h1>Time Conversion</h1>");

        int minutes = 125;   // input directly in code
        int hours = minutes / 60;
        int remainingMinutes = minutes % 60;
            
        out.println("<p>" + minutes + " minutes = " + hours + " hours and " + remainingMinutes + " minutes</p>");
    }
}