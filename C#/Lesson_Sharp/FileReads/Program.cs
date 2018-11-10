using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileReads
{
    class Program
    {
        static void Main(string[] args)
        {
            string Path = @"D:\Ac6\testFile.txt";
            Console.WriteLine("Введите строку:");
            string Text = Console.ReadLine();
            //запись в файл
            using (FileStream fstream = new FileStream(Path,FileMode.OpenOrCreate))
            {
                byte[] array = System.Text.Encoding.Unicode.GetBytes(Text);
                fstream.Write(array, 0, array.Length);
                Console.WriteLine("Текст записал в файл");

            }

            //запись в файл
            using (FileStream fstream = new FileStream(Path, FileMode.OpenOrCreate))
            {
                byte[] ar = new byte[fstream.Length];
                fstream.Read(ar, 0, ar.Length);
                string txt = Encoding.Unicode.GetString(ar);
                Console.WriteLine("Текст считан с  файл: "+txt);

            }

            /*   Использовать код ниже
             * 
             * FileStream fstream = null;
try
{
    fstream = new FileStream(@"D:\note3.dat", FileMode.OpenOrCreate);
    // операции с потоком
}
catch(Exception ex)
{
 
}
finally
{
    if (fstream != null)
        fstream.Close();
}
             * 
             * 
             * */



            Console.ReadKey();

        }
    }
}
