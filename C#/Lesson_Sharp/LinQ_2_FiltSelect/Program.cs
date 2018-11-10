using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinQ_2_FiltSelect
{
    class Program
    {
        static void Main(string[] args)
        {
            List<User> users = new List<User>
{
    new User {Name="Том", Age=23, Languages = new List<string> {"английский", "немецкий" }},
    new User {Name="Боб", Age=27, Languages = new List<string> {"английский", "французский" }},
    new User {Name="Джон", Age=29, Languages = new List<string> {"английский", "испанский" }},
    new User {Name="Элис", Age=24, Languages = new List<string> {"испанский", "немецкий" }}
};

            var selectedUsers = from user in users
                                where user.Age > 25
                                select user;

            //var selectedUsers = users.Where(u=> u.Age > 25);
            foreach (User user in selectedUsers)
                Console.WriteLine("{0} - {1}", user.Name, user.Age);

            //Сложные фильтры
            var selectedUsers_ = from user in users
                                from lang in user.Languages
                                where user.Age < 28
                                where lang == "английский"
                                select user;

            /*
             * Метод SelectMany() в качестве первого параметра принимает последовательность,
             *  которую надо проецировать, а в качестве второго параметра - функцию преобразования,
             *   которая применяется к каждому элементу. На выходе она возвращает 8 пар "пользователь - язык"
             *   (new { User = u, Lang = l }), к которым потом применяетс фильтр с помощью Where.
             * var selectedUsers = users.SelectMany(u => u.Languages,
                            (u, l) => new { User = u, Lang = l })
                          .Where(u => u.Lang == "английский" && u.User.Age < 28)
                          .Select(u=>u.User);

             * 
             * 
             * */

            //Проекция
            List<User> users_ = new List<User>();
            users_.Add(new User { Name = "Sam", Age = 43 });
            users_.Add(new User { Name = "Tom", Age = 33 });

            var names = from u in users_ select u.Name;

            foreach (string n in names)
                Console.WriteLine(n);

            /*
             * var items = from u in users 
            select new
            { 
                FirstName = u.Name, 
                DateOfBirth = DateTime.Now.Year - u.Age 
            };
 
foreach (var n in items)
    Console.WriteLine("{0} - {1}", n.FirstName, n.DateOfBirth);
             * 
             * */

            //Переменые в запросах и оператор let
            List<User> userss = new List<User>()
{
    new User { Name = "Sam", Age = 43 },
    new User { Name = "Tom", Age = 33 }
};

            var people = from u in userss
                         let name = "Mr. " + u.Name
                         select new
                         {
                             Name = name,
                             Age = u.Age
                         };

            //Выборка из нескольких источников
            List<User> Uusers = new List<User>()
{
    new User { Name = "Sam", Age = 43 },
    new User { Name = "Tom", Age = 33 }
};
            List<Phone> phones = new List<Phone>()
{
    new Phone {Name="Lumia 630", Company="Microsoft" },
    new Phone {Name="iPhone 6", Company="Apple"},
};

            var ppeople = from user in users
                         from phone in phones
                         select new { Name = user.Name, Phone = phone.Name };

            foreach (var p in ppeople)
                Console.WriteLine("{0} - {1}", p.Name, p.Phone);

        }
    }
    class Phone
    {
        public string Name { get; set; }
        public string Company { get; set; }
    }

    class User
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public List<string> Languages { get; set; }
        public User()
        {
            Languages = new List<string>();
        }
    }
}
