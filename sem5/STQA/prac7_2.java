package TYCS;

import java.util.Set;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class prac7_2 {
	public static void main(String[] args) {
		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();
		driver.get("https://instagram.com");

		try {
			Set<String> allWH = driver.getWindowHandles();
			int count = allWH.size();
			System.out.println(count);

			for (String wh : allWH) {
				driver.switchTo().window(wh);
				String title = driver.getTitle();
				System.out.println(title);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.close();
	}
}
