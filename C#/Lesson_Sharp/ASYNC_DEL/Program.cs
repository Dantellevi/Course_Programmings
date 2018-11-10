using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace ASYNC_DEL
{
    class Program
    {
        public delegate int DisplayHandler();
        static void Main(string[] args)
        {
            DisplayHandler Disp = new DisplayHandler(Display);
            IAsyncResult resultObj = Disp.BeginInvoke(null, null);//запуск асинхронного метода

            Console.WriteLine("Продолжается работа метода Main");//работает в главной функции
            int result = Disp.EndInvoke(resultObj);// ожидаем завершение асинх. метода
            Console.WriteLine("Результат равен {0}", result);

            Console.ReadLine();
        }


        static int Display()
        {
            Console.WriteLine("Начинается работа метода Display....");

            int result = 0;
            for (int i = 1; i < 10; i++)
            {
                result += i * i;
            }
            Thread.Sleep(3000);
            Console.WriteLine("Завершается работа метода Display....");
            return result;
        }
    }
}
