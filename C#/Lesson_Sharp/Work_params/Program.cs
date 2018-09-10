using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Work_params
{
    class Program
    {
        static void Main(string[] args)
        {
            int res;
            int[] mass = new int[25];
            Random rand = new Random();
            for(int i=0;i<mass.Length;i++)
            {
                mass[i] = rand.Next(10,1024);
            }
            Addition(out res, mass);
            Console.WriteLine("Результат: {0}", res);
            Console.ReadKey();
        }



        static void Addition(out int res,params int[] el)
        {
            res = 0;

            for(int i=0;i<el.Length;i++)
            {
                res += el[i];
            }
        }
    }
}
