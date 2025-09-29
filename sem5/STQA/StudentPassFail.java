package TYCS;

import java.io.*;

import org.testng.annotations.*;

import jxl.Sheet;
import jxl.Workbook;
import jxl.write.*;
import jxl.write.WritableSheet;

public class StudentPassFail {

	@BeforeClass
	public static void setup() {
		System.out.println("Starting StudentPassFail test...");
	}

	@Test
	public void testImportExport() throws Exception {
		// Input file
		FileInputStream fi = new FileInputStream("C:\\Users\\ASUS\\Downloads\\Book1.xls");
		Workbook w = Workbook.getWorkbook(fi);
		Sheet s = w.getSheet(0);

		// Output file
		FileOutputStream fo = new FileOutputStream("C:\\Users\\ASUS\\Downloads\\Book1res.xls");
		WritableWorkbook wwb = Workbook.createWorkbook(fo);
		WritableSheet ws = wwb.createSheet("result", 0);

		// Copy original data
		for (int i = 0; i < s.getRows(); i++) {
			for (int j = 0; j < s.getColumns(); j++) {
				String value = s.getCell(j, i).getContents();
				Label cell = new Label(j, i, value);
				ws.addCell(cell);
			}
		}

		// Add header "Result" in column 6 (index starts at 0)
		Label header = new Label(6, 0, "Result");
		ws.addCell(header);

		// Add Pass/Fail results
		for (int i = 1; i < s.getRows(); i++) {
			boolean fail = false;

			for (int j = 2; j < s.getColumns(); j++) {
				int marks = Integer.parseInt(s.getCell(j, i).getContents());
				if (marks < 35) {
					fail = true; // if any subject is below 35, student fails
					break; // no need to check further subjects
				}
			}

			Label result = new Label(6, i, fail ? "Fail" : "Pass");
			ws.addCell(result);
		}

		// Write and close
		wwb.write();
		wwb.close();
		fi.close();
		fo.close();
	}
}
