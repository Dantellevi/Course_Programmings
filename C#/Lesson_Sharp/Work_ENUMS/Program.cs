using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Work_ENUMS
{
    class Program
    {

        enum Days
        {
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        }

        enum Time: byte
        {
            Morning,
            Afternoon,
            Evening,
            Night
        }



        static void Main(string[] args)
        {
            Time data;
            data = Time.Afternoon;

            Console.WriteLine("Select-{0}", data);
            Console.ReadKey();
        }




    }
}
