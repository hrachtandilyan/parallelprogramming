namespace DistanceCalculator.Engines
{
    class DistanceCalculatorFactory
    {
        public enum CalculatorType
        {
            SYNC,
            ASYNC,
            MPI,
            CUDA
        }
        public static AbstractCalculatorEngine GetCalculator(CalculatorType type)
        {
            switch (type)
            {
                case CalculatorType.SYNC:
                    return new SyncronousDistanceCalculator();
                case CalculatorType.ASYNC:
                    return new AsyncronousDistanceCalculator();
                case CalculatorType.MPI:
                    return new MPIDistanceCalculator();
                case CalculatorType.CUDA:
                    return new MPIDistanceCalculator();
            }

            return null;
        }
    }
}
