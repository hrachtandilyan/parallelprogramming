package engine.impl;

import engine.Engine;

import java.util.ArrayList;

/**
 * Created by Admin on 10/25/2016.
 */
public class ParallelizedEngine implements Engine {
    private Thread[][] threads;

    @Override
    public float[][] calculate(float[][] queryVectors, float[][] datasetVectors) {
        threads = new Thread[queryVectors.length][datasetVectors.length];

        float[][] result = new float[queryVectors.length][datasetVectors.length];

        for (int i = 0; i < queryVectors.length; ++i) {
            for (int j = 0; j < datasetVectors.length; ++j) {
                threads[i][j] = new Thread(new CalculateWithThreads(queryVectors[i], datasetVectors[j], result, i,j));
                threads[i][j].start();
                try {
                    threads[i][j].join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        return result;
    }

    class CalculateWithThreads implements Runnable {
        private float[] query;
        private float[] data;
        private float[][] result;
        private int i;
        private int j;

        public CalculateWithThreads(float[] data, float[] query, float[][] result, int i, int j) {
            this.data = data;
            this.query = query;
            this.result = result;
            this.i = i;
            this.j = j;
        }

        @Override
        public void run() {
            float dist = 0;
            for (int k = 0; k < query.length; ++k) {
                float delta = query[k] - data[k];
                dist += delta * delta;
            }
            synchronized (result) {
                result[i][j] = dist;
            }
        }
    }
}
