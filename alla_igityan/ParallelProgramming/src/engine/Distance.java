package engine;

import java.util.ArrayList;

/**
 * Created by Admin on 10/25/2016.
 */
public class Distance {
    private Engine engine;

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    public float[][] calculate(float[][] queryVectors, float[][] datasetVectors) {
        return engine.calculate(queryVectors, datasetVectors);
    }
}
