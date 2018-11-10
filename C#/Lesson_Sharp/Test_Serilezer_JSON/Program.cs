using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Json;
using System.Runtime.Serialization;


namespace Test_Serilezer_JSON
{

    [DataContract]
    public class Person
    {
        [DataMember]
        public string Name { get; set; }
        [DataMember]
        public int Age { get; set; }

        public Person(string name, int year)
        {
            Name = name;
            Age = year;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // объект для сериализации
            Person person1 = new Person("Tom", 29);
            Person person2 = new Person("Bill", 25);
            Person[] people = new Person[] { person1, person2 };


            DataContractJsonSerializer jst = new DataContractJsonSerializer(typeof(Person[]));

            //серилизация
            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                jst.WriteObject(fs, people);
            }
            //десерилизация
            using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
            {
                Person[] newpeople = (Person[])jst.ReadObject(fs);

                foreach (Person p in newpeople)
                {
                    Console.WriteLine("Имя: {0} --- Возраст: {1}", p.Name, p.Age);
                }
            }

            Console.ReadLine();


        }
    }
}
