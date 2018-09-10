using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Work_REF
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 5;
            Addplus(ref x);
            Console.WriteLine("x={0}", x);
            int s, p;
            Console.Write("Введите s  и р: ");
            s = int.Parse(Console.ReadLine());
            p = int.Parse(Console.ReadLine());
            int res;
            Sum(s, p, out res);
            Console.WriteLine("Результат :{0}", res);

        }

       static void Addplus(ref int x)
        {
            x++;
        }

        static void Sum(int a,int b, out int res)
        {
            res = a + b;
           
        }
    }
}
