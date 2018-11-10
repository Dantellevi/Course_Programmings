using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Stream_Work
{
    class Program
    {
        static void Main(string[] args)
        {
            string Path = @"D:\Ac6\testFile.txt";
            StreamReader rdf = null;
            try
            {
                rdf = new StreamReader(Path,Encoding.Unicode);
                Console.WriteLine("Считанный текст: " + rdf.ReadToEnd());
            }
            catch(Exception e)
            {
                Console.WriteLine("Ошибка: " + e.Message);
            }
            finally
            {
                rdf.Close();
            }

            Console.ReadKey();

            Console.WriteLine("******считываем блоками********");
            try
            {
                rdf = new StreamReader(Path, Encoding.Unicode);
                char[] array = new char[200];
                rdf.Read(array, 0, 200);
                Console.WriteLine( array);
            }
            catch (Exception e)
            {
                Console.WriteLine("Ошибка: " + e.Message);
            }
            finally
            {
                rdf.Close();
            }
            Console.ReadKey();
            string ReadPath = @"D:\Ac6\testFile.txt";
            string WritePath = @"D:\Ac6\test2File.txt";

            StreamReader rd = null;
            StreamWriter wr = null;
            string readBuffer=" ";
            try
            {
                FileInfo fl = new FileInfo(ReadPath);
                if(!fl.Exists)
                {
                    Console.WriteLine("Ошибка файл не найден!!!");
                    return;
                }
                rd = new StreamReader(ReadPath,Encoding.Unicode);
                readBuffer=rd.ReadToEnd();


                wr = new StreamWriter(WritePath, true, Encoding.Unicode);
                string WriteBuffer = " ";
                Console.Write("Введите строку: ");
                WriteBuffer = Console.ReadLine();
                wr.WriteLine(WriteBuffer);


            }
            catch(Exception e)
            {
                Console.WriteLine("Ошибка " + e.Message);
            }
            finally
            {
                rd.Close();
                wr.Close();
            }
        }
    }
}
