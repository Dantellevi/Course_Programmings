using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.Runtime.Serialization.Formatters.Soap;


namespace Test_Serilizer2_SOAP
{


    [Serializable]
    class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }

    class Program
    {

        static void Main(string[] args)
        {
            Person person = new Person("Tom", 29);
            Person person2 = new Person("Bill", 25);
            Person[] people = new Person[] { person, person2 };

            // создаем объект SoapFormatter
            SoapFormatter formatter = new SoapFormatter();
            //получаем поток
            using (FileStream fs = new FileStream("peaple.soap", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, people);//серилизация
                Console.WriteLine("Серилизация прошла успешно!!");

            }

            using (FileStream fsds = new FileStream("peaple.soap", FileMode.OpenOrCreate))
            {
                Person[] pers = (Person[])formatter.Deserialize(fsds);
                Console.WriteLine("Десерелизация прошла успешно!!");
                foreach (Person p in pers)
                {
                    Console.WriteLine("Имя: {0} --- Возраст: {1}", p.Name, p.Age);
                }
            }

            Console.ReadLine();


        }
    }
}
