package engine;

import java.util.Random;

/**
 * Created by Admin on 10/25/2016.
 */
public class Generator {
    private float[][] query;
    private float[][] dataset;

    private final int count = 10;
    private final int length = 20;
    private float maxX = 10f;
    private float minX = 1f;

    public void generate() {
        Random random = new Random();
        query = new float[count][length];
        dataset = new float[count][length];

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < length; j++) {
                query[i][j] = random.nextFloat();// * (maxX - minX) + minX;;
                dataset[i][j] = random.nextFloat();// * (maxX - minX) + minX;;
            }
        }
    }

    public float[][] getQuery() {
        return query;
    }

    public float[][] getDataset() {
        return dataset;
    }
}

