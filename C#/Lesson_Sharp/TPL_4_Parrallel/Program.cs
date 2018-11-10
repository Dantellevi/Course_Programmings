using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace TPL_4_Parrallel
{
    class Program
    {
        static void Main(string[] args)
        {
            Parallel.Invoke(Display,
        () => {
            Console.WriteLine("Выполняется задача {0}", Task.CurrentId);
            Thread.Sleep(3000);
        },
        () => Factorial(5));

            Console.ReadLine();

            Parallel.For(1, 10, Factorial);
            Console.ReadLine();
            ParallelLoopResult result = Parallel.ForEach<int>(new List<int>() { 1, 3, 5, 8 }, Factorial);
            Console.ReadLine();
        }

        static void Display()
        {
            Console.WriteLine("Выполняется задача {0}", Task.CurrentId);
            Thread.Sleep(3000);
        }

        static void Factorial(int x)
        {
            int result = 1;

            for (int i = 1; i <= x; i++)
            {
                result *= i;
            }
            Console.WriteLine("Выполняется задача {0}", Task.CurrentId);
            Thread.Sleep(3000);
            Console.WriteLine("Результат {0}", result);
        }
    }
}
