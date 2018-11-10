using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collection_1
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList obj = new ArrayList() { 1, 2, "string" };

            object j = 45.6;
            obj.Add(j);

            foreach (object o in obj)
            {
                Console.WriteLine(o);
            }

            List<string> countries = new List<string>() { "Россия", "США", "Великобритания", "Китай" };
            countries.Add("Франция");
            countries.RemoveAt(1); // удаление второго элемента
            foreach (string s in countries)
            {
                Console.WriteLine(s);
            }

            Console.ReadLine();
        }
    }
}
