using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fist_Parallel
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, };
            var factorials = from n in numbers.AsParallel()
                             select Factorial(n);
            foreach (var n in factorials)
                Console.WriteLine(n);
            Console.ReadLine();

            int[] numberss = new int[] { -2, -1, 0, 1, 2, 4, 3, 5, 6, 7, 8, };
            (from n in numberss.AsParallel()
             where n > 0
             select Factorial(n))
             .ForAll(n => Console.WriteLine(n));
            //==================================Упорядовачивание элементов=====================
            var factorialsl = from n in numbers.AsParallel().AsOrdered()
                             where n > 0
                             select Factorial(n);



        }


        static int Factorial(int x)
        {
            int result = 1;

            for (int i = 1; i <= x; i++)
            {
                result *= i;
            }
            Console.WriteLine("Факториал числа {0} равен {1}", x, result);
            return result;
        }
    }
}
