using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TPL_2_Task
{
    class Program
    {
        static void Main(string[] args)
        {
            var outer = Task.Factory.StartNew(() =>
              {
                  Console.WriteLine("Outer task starting...");
                  var inner = Task.Factory.StartNew(() =>
                    {
                        Console.WriteLine("Inner task starting...");
                        Thread.Sleep(2000);
                        Console.WriteLine("Inner task finished.");
                    });
              });
            outer.Wait(); // ожидаем выполнения внешней задачи
            Console.WriteLine("End of Main");
            Task[] tasks1 = new Task[3]
{
    new Task(() => Console.WriteLine("First Task")),
    new Task(() => Console.WriteLine("Second Task")),
    new Task(() => Console.WriteLine("Third Task"))
};
            // запуск задач в массиве
            foreach (var t in tasks1)
                t.Start();
            Task.WaitAll(tasks1);// ожидаем завершения задач 
            //Либо также можно использовать методы Task.Factory.StartNew или Task.Run и сразу запускать все задачи:
            Task[] tasks2 = new Task[3];
            int j = 1;
            for (int i = 0; i < tasks2.Length; i++)
                tasks2[i] = Task.Factory.StartNew(() => Console.WriteLine($"Task {j++}"));
            Console.ReadLine();
            //Возвращение результатов из задач
            Task<int> task1 = new Task<int>(() => Factorial(5));
            task1.Start();

            Console.WriteLine($"Факториал числа 5 равен {task1.Result}");

            Task<Book> task2 = new Task<Book>(() =>
            {
                return new Book { Title = "Война и мир", Author = "Л. Толстой" };
            });
            task2.Start();

            Book b = task2.Result;
            Console.WriteLine($"Название книги: {b.Title}, автор: {b.Author}");

            Console.ReadLine();
        }


        static int Factorial(int x)
        {
            int result = 1;

            for (int i = 1; i <= x; i++)
            {
                result *= i;
            }

            return result;
        }





    }

    public class Book
    {
        public string Title { get; set; }
        public string Author { get; set; }
    }
}
