package TYCS;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class LaunchChrome {
    public static WebDriver driver;

    public static void main(String[] args) {
        System.out.println("Launching Chrome...");

        System.setProperty("webdriver.chrome.driver", "C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

        driver = new ChromeDriver();

        driver.navigate().to("http://google.com");

        // ✅ Optional: maximize window
        driver.manage().window().maximize();

        // ✅ Close after some time (for demo)
        try {
            Thread.sleep(5000); // wait 5 seconds
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        driver.quit(); // close browser
    }
}