using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace TH_4_Sinch
{
    class Program
    {
        static int x = 0;
        static object locker = new object();
        static void Main(string[] args)
        {
            for(int i=0;i<5;i++)
            {
                Thread myTread = new Thread(Count);
                myTread.Name = "Поток " + i.ToString();
                myTread.Start();
            }
            Console.ReadLine();
        }

        static void Count()
        {
            x = 1;
            lock(locker)
            {
                for (int i = 1; i < 9; i++)
                {
                    Console.WriteLine("{0}: {1}", Thread.CurrentThread.Name, x);
                    x++;
                    Thread.Sleep(100);
                }
            }
           
        }
    }
}
