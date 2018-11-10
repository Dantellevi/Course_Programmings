using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq_Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = { 3, 12, 4, 10, 34, 20, 55, -66, 77, 88, 4 };
            IEnumerable<int> sortedNumbers = numbers.OrderBy(i => i);

            List<User> users = new List<User>()
{
    new User { Name = "Tom", Age = 33 },
    new User { Name = "Bob", Age = 30 },
    new User { Name = "Tom", Age = 21 },
    new User { Name = "Sam", Age = 43 }
};
            var sortedUsers = users.OrderBy(u => u.Name);



            //сложная сортировка
            var result = users.OrderBy(u => u.Name).ThenBy(u => u.Age).ThenBy(u => u.Name.Length);
        }
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
