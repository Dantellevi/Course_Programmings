using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace BinWork
{

    struct State
    {
        public string name;
        public string capital;
        public int area;
        public double people;

        public State(string n, string c, int a, double p)
        {
            name = n;
            capital = c;
            people = p;
            area = a;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            State[] states = new State[2];
            states[0] = new State("Германия", "Берлин", 357168, 80.8);
            states[1] = new State("Франция", "Париж", 640679, 64.7);

            string Path = @"D:\Ac6\testBinFile.dat";
            BinaryWriter binW = null;
            BinaryReader reader = null;

            try
            {
                binW = new BinaryWriter(File.Open(Path, FileMode.OpenOrCreate));
                foreach(State s in states)
                {
                    binW.Write(s.name);
                    binW.Write(s.capital);
                    binW.Write(s.area);
                    binW.Write(s.people);
                }

                Console.WriteLine("Структура записана");


            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                binW.Close();
                
            }

            try
            {
               
                Console.WriteLine("Структура считывается..............");

                reader = new BinaryReader(File.Open(Path, FileMode.Open));

                //пока не достигнут конец 
                //считываем каждое значение из файла
                while (reader.PeekChar() > -1)
                {
                    string name = reader.ReadString();
                    string capital = reader.ReadString();
                    int area = reader.ReadInt32();
                    double population = reader.ReadDouble();
                    Console.WriteLine("Страна: {0}  столица: {1}  площадь {2} кв. км   численность населения: {3} млн. чел.",
                        name, capital, area, population);
                }


            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                
                reader.Close();
            }





            Console.ReadKey();

        }
    }
}
