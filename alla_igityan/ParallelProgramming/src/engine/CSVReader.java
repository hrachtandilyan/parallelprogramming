package engine;

/**
 * Created by Admin on 10/25/2016.
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class CSVReader {
    public void read() {
        String csvFile = "C:\\Users\\Admin\\Desktop\\matrix.csv";
        String line = "";
        String cvsSplitBy = ",";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] numbers = line.split(cvsSplitBy);
                float[] num = new float[numbers.length];
                for (int i = 0; i < numbers.length; ++i) {
                    num[i] = Float.parseFloat(numbers[i]);
                    System.out.println(num[i]);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}