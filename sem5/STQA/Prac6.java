package TYCS;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

import org.testng.annotations.*;

import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;

//Write & test a program to select the number of students who have scored more than 60 in \
//any one subject (or all subjects) using TestNG.

public class Prac6 {
	@BeforeClass
	public static void setup() {
		System.out.println("Setup completed.");
	}

	@Test
	public void generateSubjectWiseSortedFiles() throws IOException, BiffException, WriteException {
		String inputPath = "C:\\Users\\ASUS\\Downloads\\Book1.xls";
		String outputDir = "C:\\Users\\ASUS\\Downloads\\Book1.xls_Result";

		File inputFile = new File(inputPath);
		if (!inputFile.exists()) {
			System.err.println("Input file does not exist: " + inputPath);
			return;
		}

		File outDir = new File(outputDir);
		if (!outDir.exists()) {
			outDir.mkdirs();
		}

		FileInputStream fi = new FileInputStream(inputFile);
		Workbook workbook = Workbook.getWorkbook(fi);
		Sheet sheet = workbook.getSheet(0);

		int rows = sheet.getRows();
		int cols = sheet.getColumns();

		// Iterate over each subject column (starting from index 2)
		for (int subjCol = 2; subjCol < cols; subjCol++) {
			String subjectName = sheet.getCell(subjCol, 0).getContents();

			List<StudentScore> studentScores = new ArrayList<>();

			for (int i = 1; i < rows; i++) {
				String rollNo = sheet.getCell(0, i).getContents(); // Roll No
				String name = sheet.getCell(1, i).getContents(); // Name
				String markStr = sheet.getCell(subjCol, i).getContents(); // Marks

				try {
					int mark = Integer.parseInt(markStr);

					// ✅ Only include students with 60 or more marks
					if (mark >= 60) {
						studentScores.add(new StudentScore(rollNo, name, mark));
					}

				} catch (NumberFormatException e) {
					// Skip invalid marks
				}
			}

			// Skip file creation if no students passed in this subject
			if (studentScores.isEmpty()) {
				System.out.println("No qualifying students for subject: " + subjectName);
				continue;
			}

			// Sort by marks descending
			studentScores.sort((a, b) -> Integer.compare(b.marks, a.marks));

			String subjectFilePath = outputDir + subjectName.replaceAll("[^a-zA-Z0-9]", "_") + ".xls";
			WritableWorkbook subjectWorkbook = Workbook.createWorkbook(new File(subjectFilePath));
			WritableSheet subjectSheet = subjectWorkbook.createSheet(subjectName, 0);

			subjectSheet.addCell(new Label(0, 0, "Roll No"));
			subjectSheet.addCell(new Label(1, 0, "Name"));
			subjectSheet.addCell(new Label(2, 0, "Marks"));

			for (int i = 0; i < studentScores.size(); i++) {
				StudentScore ss = studentScores.get(i);
				subjectSheet.addCell(new Label(0, i + 1, ss.rollNo));
				subjectSheet.addCell(new Label(1, i + 1, ss.name));
				subjectSheet.addCell(new Label(2, i + 1, String.valueOf(ss.marks)));
			}

			subjectWorkbook.write();
			subjectWorkbook.close();
			System.out.println("Created file: " + subjectFilePath);
		}

		workbook.close();
		fi.close();
		System.out.println("All subject-wise files generated.");
	}

	static class StudentScore {
		String rollNo;
		String name;
		int marks;

		StudentScore(String rollNo, String name, int marks) {
			this.rollNo = rollNo;
			this.name = name;
			this.marks = marks;
		}
	}

}
