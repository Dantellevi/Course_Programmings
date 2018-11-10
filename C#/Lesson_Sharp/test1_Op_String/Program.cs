using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test1_Op_String
{
    class Program
    {
        static void Main(string[] args)
        {
            string s1 = "hello";
            string s2 = "world";

            int result = String.Compare(s1, s2);
            if (result < 0)
            {
                Console.WriteLine("Строка s1 перед строкой s2");
            }
            else if (result > 0)
            {
                Console.WriteLine("Строка s1 стоит после строки s2");
            }
            else
            {
                Console.WriteLine("Строки s1 и s2 идентичны");
            }
            // результатом будет "Строка s1 перед строкой s2"


            string s3 = "hello world";
            char ch = 'o';
            int indexOfChar = s3.IndexOf(ch); // равно 4
            Console.WriteLine(indexOfChar);

            string subString = "wor";
            int indexOfSubstring = s3.IndexOf(subString); // равно 6
            Console.WriteLine(indexOfSubstring);


            string path = @"C:\SomeDir";

            string[] files = Directory.GetFiles(path);

            for (int i = 0; i < files.Length; i++)
            {
                if (files[i].EndsWith(".exe"))
                    File.Delete(files[i]);
            }

            string text = "И поэтому все так произошло";

            string[] words = text.Split(new char[] { ' ' });

            foreach (string s in words)
            {
                Console.WriteLine(s);
            }

            string[] wordss = text.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            string texxt = " hello world ";

            texxt = texxt.Trim(); // результат "hello world"
            texxt = texxt.Trim(new char[] { 'd', 'h' }); // результат "ello worl"



            string textt = "Хороший день";
            // обрезаем начиная с третьего символа
            textt = textt.Substring(2);
            // результат "роший день"
            Console.WriteLine(textt);
            // обрезаем сначала до последних двух символов
            textt = textt.Substring(0, text.Length - 2);
            // результат "роший де"
            Console.WriteLine(textt);


            string text2 = "Хороший день";
            // индекс последнего символа
            int ind = text2.Length - 1;
            // вырезаем последний символ
            text2 = text2.Remove(ind);
            Console.WriteLine(text2);

            // вырезаем первые два символа
            text2 = text2.Remove(0, 2);

            string text3 = "хороший день";

            text3 = text3.Replace("хороший", "плохой");
            Console.WriteLine(text3);

            text3 = text3.Replace("о", "");
            Console.WriteLine(text3);


            string hello = "Hello world!";

            Console.WriteLine(hello.ToLower()); // hello world!
            Console.WriteLine(hello.ToUpper()); // HELLO WORLD!

        }
    }
}
