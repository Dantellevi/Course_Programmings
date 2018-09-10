using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Work_Recursia
{
    class Program
    {
        static void Main(string[] args)
        {
            int res = Factorial(2);
            Console.WriteLine("Результат: {0}", res);
            Console.ReadKey();

        }


        static int Factorial(int x)
        {
            if(x==0)
            {
                return 1;
            }
            else
            {
                return x * Factorial(x - 1);
            }
        }
    }
}
