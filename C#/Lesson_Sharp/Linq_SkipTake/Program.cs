using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq_SkipTake
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = { -3, -2, -1, 0, 1, 2, 3 };
            var result = numbers.Take(3);

            foreach (int i in result)
                Console.WriteLine(i);

            string[] teams = { "Бавария", "Боруссия", "Реал Мадрид", "Манчестер Сити", "ПСЖ", "Барселона" };
            foreach (var t in teams.TakeWhile(x => x.StartsWith("Б")))
                Console.WriteLine(t);
        }
    }
}
