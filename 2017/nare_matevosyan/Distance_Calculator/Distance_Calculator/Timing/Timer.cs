using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Distance_Calculator.Timing
{
    class Timer
    {
        private Stopwatch timer;

        public void Start()
        {
            timer = Stopwatch.StartNew();
        }

        public long Stop()
        {
            timer.Stop();
            return timer.ElapsedMilliseconds;
        }
    }
}
