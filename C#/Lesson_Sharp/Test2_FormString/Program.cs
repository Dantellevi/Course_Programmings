using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test2_FormString
{
    class Program
    {
        static void Main(string[] args)
        {

            fun1();
            func2();
            func3();
            func4();


        }
       static void fun1()
        {
            double number = 23.7;
            string result = String.Format("{0:C}", number);
            Console.WriteLine(result); // $ 23.7
            string result2 = String.Format("{0:C2}", number);
            Console.WriteLine(result2); // $ 23.70
        }

        static void func2()
        {
            int number1 = 23;
            string result3 = String.Format("{0:d}", number1);
            Console.WriteLine(result3); // 23
            string result4 = String.Format("{0:d4}", number1);
            Console.WriteLine(result4); // 0023
        }

        static void func3()
        {
            int number = 23;
            string result = String.Format("{0:f}", number);
            Console.WriteLine(result); // 23,00

            double number2 = 45.08;
            string result2 = String.Format("{0:f4}", number2);
            Console.WriteLine(result2); // 45,0800

            double number3 = 25.07;
            string result3 = String.Format("{0:f1}", number3);
            Console.WriteLine(result2); // 25,1
        }


        static void func4()
        {
            decimal number = 0.15345m;
            Console.WriteLine("{0:P1}", number);// 15.3%
        }

        static void func5()
        {
            long number = 19876543210;
            string result = String.Format("{0:+# (###) ###-##-##}", number);
            Console.WriteLine(result); // +1 (987) 654-32-10
        }


        static void func6()
        {
            Console.WriteLine("Интерполяция строк!!!");
            int x = 8;
            int y = 7;
            string result = $"{x} + {y} = {x + y}";
            Console.WriteLine(result); // 8 + 7 = 15
            long number = 19876543210;
            Console.WriteLine($"{number:+# ### ### ## ##}"); // +1 987 654 32 10
        }
    }

    
}
