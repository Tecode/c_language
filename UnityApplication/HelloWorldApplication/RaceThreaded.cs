using System;
using System.Diagnostics;

namespace HelloWorldApplication
{
    public class RaceThreaded
    {
        private int _value = 2;

        // 线程竞争态问题
        public void Run(object data)
        {
            while (true)
            {
                _value++;
                if (_value == 2)
                {
                    Console.WriteLine("进程出现了竞争问题");
                    break;
                }

                _value = 2;
            }
        }
        
        // 解决争用问题
        public void RunRace(object data)
        {
            var race = data as RaceThreaded;
            Debug.Assert(race != null, nameof(race) + " != null");
            lock (race)
            {
                race.Run(race);
            }
        }
    }
}