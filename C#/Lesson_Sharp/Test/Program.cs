using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            string data = "Hello World";

            byte[] inVar = Encoding.ASCII.GetBytes(data);
            StringBuilder sb = new StringBuilder();
            foreach(byte b in inVar)
            {
                sb.Append(b);
                Console.WriteLine("0x{0:X}", b.ToString("X2"));
            }

            string outVAR = sb.ToString();
            Console.WriteLine("Data=0x{0:X} ", outVAR.ToString());
            Console.ReadKey();
        }
    }
}
