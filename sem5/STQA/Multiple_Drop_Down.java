package TYCS;

import java.util.List;
import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.Select;

public class Multiple_Drop_Down {
	public static void main(String[] args) throws InterruptedException {
		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);

		try {
			driver.get("https://www.techlistic.com/p/selenium-practice-form.html");

			Select oSelect = new Select(driver.findElement(By.id("selenium_commands")));

			oSelect.selectByIndex(0);
			Thread.sleep(2000);

			oSelect.deselectByIndex(0);

			oSelect.selectByVisibleText("Browser Commands");
			Thread.sleep(2000);

			oSelect.deselectByVisibleText("Browser Commands");

			List<WebElement> oSize = oSelect.getOptions();
			int iListSize = oSize.size();
			System.out.println("No of items: " + iListSize);

			for (int i = 0; i < iListSize; i++) {
				String sValue = oSelect.getOptions().get(i).getText();
				System.out.println(sValue);
				oSelect.selectByIndex(i);
				Thread.sleep(2000);
			}

			oSelect.deselectAll();
		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.quit();
	}
}
