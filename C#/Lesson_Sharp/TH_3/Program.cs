using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace TH_3
{

    class Counter
    {
        public int x;
        public int y;
        public Counter()
        {

        }

        public Counter(int _x,int _y)
        {
            x = _x;
            y = _y;
        }


        public void Count()
        {
            for (int i = 1; i < 9; i++)
            {
               
                Console.WriteLine("четвертый поток:");
                Console.WriteLine(i * this.x *this.y);
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            int number=4;
            Thread th = new Thread(new ParameterizedThreadStart(Count));
            th.Start(number);
            for (int i = 1; i < 9; i++)
            {
                Console.WriteLine("Главный поток:");
                Console.WriteLine(i * i);
                Thread.Sleep(300);
            }
            //=====================================
            Console.WriteLine("====================================");
            Counter cn = new Counter();
            cn.x = 1;
            cn.y = 2;
            Thread myTr = new Thread(new ParameterizedThreadStart(CnT));
            myTr.Start(cn);
            for (int i = 1; i < 9; i++)
            {
                Console.WriteLine("Главный поток:");
                Console.WriteLine(i * i);
                Thread.Sleep(300);
            }
            Console.WriteLine("====================================");
            Counter cеn = new Counter();
            cn.x = 1;
            cn.y = 2;
            Thread myTread = new Thread(new ThreadStart(cеn.Count));
            myTread.Start();
            for (int i = 1; i < 9; i++)
            {
                Console.WriteLine("Главный поток:");
                Console.WriteLine(i * i);
                Thread.Sleep(300);
            }
            Console.ReadKey();

        }

        public static void CnT(object c)
        {
            for (int i = 1; i < 9; i++)
            {
                Counter cn = (Counter)c;

                Console.WriteLine("Третий поток:");
                Console.WriteLine(i * cn.x * cn.y);
            }
        }

        public static void Count(object n)
        {
            for (int i = 1; i < 9; i++)
            {
                int sn = (int)n;

                Console.WriteLine("Второй поток:");
                Console.WriteLine(i * sn);
                Thread.Sleep(400);
            }
        }
    }
}
