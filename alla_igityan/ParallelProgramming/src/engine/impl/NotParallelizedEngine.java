package engine.impl;

import engine.Engine;

import java.util.ArrayList;

/**
 * Created by Admin on 10/24/2016.
 */
public class NotParallelizedEngine implements Engine {
    @Override
    public float[][] calculate(float[][] queryVectors, float[][] datasetVectors) {
        float[][] result = new float[queryVectors.length][datasetVectors.length];
        for (int i = 0; i < queryVectors.length; ++i) {
            for (int j = 0; j < datasetVectors.length; ++j) {
                float dist = 0;
                for (int k = 0; k < queryVectors[i].length; ++k) {
                    float delta = queryVectors[i][k] - datasetVectors[j][k];
                    dist += delta * delta;
                }
                result[i][j] = dist;
            }
        }
        return result;
    }
}
