package engine;

import engine.impl.NotParallelizedEngine;
import engine.impl.ParallelizedEngine;

/**
 * Created by Admin on 10/25/2016.
 */
public class Main {
    public static void main(String[] args) {
        Generator generator = new Generator();
        generator.generate();
        Distance distance = new Distance();
        //distance.setEngine(new NotParallelizedEngine());
        distance.setEngine(new ParallelizedEngine());
        float[][] query = generator.getQuery();
        float[][] dataset = generator.getDataset();

        /*for (float[] floats : query) {
            for (float aFloat : floats) {
                System.out.print(aFloat + "");
            }
            System.out.println();
        }
        System.out.println();

        for (float[] floats : dataset) {
            for (float aFloat : floats) {
                System.out.print(aFloat + "");
            }
            System.out.println();
        }
        System.out.println();*/

        float[][] result = distance.calculate(query, dataset);

        for (float[] floats : result) {
            for (float aFloat : floats) {
                System.out.print(aFloat + " ");
            }
            System.out.println();
        }
    }
}
