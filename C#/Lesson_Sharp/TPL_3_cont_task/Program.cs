using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace TPL_3_cont_task
{
    class Program
    {
        static void Main(string[] args)
        {
            Task task1 = new Task(() => {
                Console.WriteLine("Id задачи: {0}", Task.CurrentId);
            });

            // задача продолжения
            Task task2 = task1.ContinueWith(Display);
            Task task3 = task1.ContinueWith((Task t) =>
            {
                Console.WriteLine("Id задачи: {0}", Task.CurrentId);
            });

            Task task4 = task2.ContinueWith((Task t) =>
            {
                Console.WriteLine("Id задачи: {0}", Task.CurrentId);
            });
            task1.Start();

            // ждем окончания второй задачи
            task2.Wait();
            Console.WriteLine("Выполняется работа метода Main");
            Console.ReadLine();
        }
        static void Display(Task t)
        {
            Console.WriteLine("Id задачи: {0}", Task.CurrentId);
            Console.WriteLine("Id предыдущей задачи: {0}", t.Id);
            Thread.Sleep(3000);
        }
    }
}
