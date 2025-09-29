package TYCS;

import java.util.List;
import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.Select;

public class Single_Drop_Down {
	public static void main(String[] args) throws InterruptedException {
		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);

		try {

			driver.get("https://www.tutorialspoint.com/selenium/practice/selenium_automation_practice.php");

			Select oSelect = new Select(driver.findElement(By.name("state")));

			oSelect.selectByVisibleText("NCR");
			Thread.sleep(2000);

			oSelect.selectByIndex(2);
			Thread.sleep(2000);

			List<WebElement> oSize = oSelect.getOptions();
			int iListSize = oSize.size();
			System.out.println("No of items: " + iListSize);

			for (int i = 0; i < iListSize; i++) {
				String sValue = oSelect.getOptions().get(i).getText();
				System.out.println(sValue);
				if (sValue.equals("Haryana")) {
					oSelect.selectByIndex(i);
					break;
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.quit();
	}
}
