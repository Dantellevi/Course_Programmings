using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Virtual_Work
{
    class Program
    {
        static void Main(string[] args)
        {
            Person p1 = new Person("Bill", "Gates");
            p1.Display(); // вызов метода Display из класса Person

            Employee p2 = new Employee("Tom", "Smith", "Microsoft");
            p2.Display(); // вызов метода Display из класса Perso
        }
    }

    class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public Person(string firstName, string lastName)
        {
            FirstName = firstName;
            LastName = lastName;
        }
        public virtual void Display()
        {
            Console.WriteLine($"{FirstName} {LastName}");
        }
    }
    class Employee : Person
    {
        public string Company { get; set; }
        public Employee(string firstName, string lastName, string company)
            : base(firstName, lastName)
        {
            Company = company;
        }
    }
}
