using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace Test_Serilizer1
{
    class Program
    {
        static void Main(string[] args)
        {
            /****************Работа с одиночным объектом*******************/
            Person person = new Person("TOM", 29);
            Console.WriteLine("Объект создан!!!");

            //// создаем объект BinaryFormatter
            BinaryFormatter bin = new BinaryFormatter();
            //получаем поток , куда будем записывать сериализовать объекты
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                bin.Serialize(fs, person);
                Console.WriteLine("Объект сериализован!!!!");
            }

            // десериализация из файла people.dat
            using (FileStream fs = new FileStream("people.dat", FileMode.OpenOrCreate))
            {
                Person newPerson = (Person)bin.Deserialize(fs);

                Console.WriteLine("Объект десериализован");
                Console.WriteLine("Имя: {0} --- Возраст: {1}", newPerson.Name, newPerson.Year);
            }
            /**************************************************************/
            Console.WriteLine("||||||||||||||||||||||||||||||||||||||||||||||");
            Person person1 = new Person("Tom", 29);
            Person person2 = new Person("Bill", 25);
            // массив для сериализации
            Person[] people = new Person[] { person1, person2 };

            BinaryFormatter formatter = new BinaryFormatter();

            using (FileStream stream = new FileStream("PEOPLES.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(stream, people);
                Console.WriteLine("Объект сериализован");

            }

            // десериализация
            using (FileStream fsss = new FileStream("PEOPLES.dat", FileMode.OpenOrCreate))
            {
                Person[] deserilizePeople = (Person[])formatter.Deserialize(fsss);

                foreach (Person p in deserilizePeople)
                {
                    Console.WriteLine("Имя: {0} --- Возраст: {1}", p.Name, p.Year);
                }
            }

            Console.ReadLine();

        }
    }

    [Serializable]
    class Person
    {
        public string Name { get; set; }
        public int Year { get; set; }
        public Person(string _Name,int _Year)
        {
            this.Name = _Name;
            this.Year = _Year;
        }

    }
}
