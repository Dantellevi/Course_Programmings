using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace ASYNC_2
{
    class Program
    {
        public delegate int DisplayHandler(int k);
        static void Main(string[] args)
        {
            DisplayHandler handler = new DisplayHandler(Display);

            IAsyncResult resultObj = handler.BeginInvoke(10, new AsyncCallback(AsyncCompleted), "Асинхронные вызовы");

            Console.WriteLine("Продолжается работа метода Main");

            int res = handler.EndInvoke(resultObj);

            Console.WriteLine("Результат: {0}", res);

            Console.ReadLine();
        }


        static int Display(int k)
        {
            Console.WriteLine("Начинается работа метода Display....");

            int result = 0;
            for (int i = 1; i < 10; i++)
            {
                result += k * i;
            }
            Thread.Sleep(3000);
            Console.WriteLine("Завершается работа метода Display....");
            return result;
        }

        static void AsyncCompleted(IAsyncResult resObj)
        {
            string mes = (string)resObj.AsyncState;
            Console.WriteLine(mes);
            Console.WriteLine("Работа асинхронного делегата завершена");
        }
    }
}
