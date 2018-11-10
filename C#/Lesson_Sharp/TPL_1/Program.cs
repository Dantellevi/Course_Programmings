using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TPL_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Task task1 = new Task(() => Console.WriteLine("Task1 is executed"));
            //task1.Start();

            //Task task2 = Task.Factory.StartNew(() => Console.WriteLine("Task2 is executed"));

            //Task task3 = Task.Run(() => Console.WriteLine("Task3 is executed"));
            Task task = new Task(Display);
            task.Start();
            task.Wait();
            Console.WriteLine("Завершение метода Main");
            Console.ReadLine();
        }
        static void Display()
        {
            Console.WriteLine("Начало работы метода Display");

            Console.WriteLine("Завершение работы метода Display");
        }
    }
}
