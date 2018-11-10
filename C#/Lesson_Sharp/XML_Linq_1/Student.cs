using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XML_Linq_1
{
    class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
        public int Age { get; set; }


        public static IEnumerable<Student> GetAllStudents()
        {
            return new List<Student>
            {
                new Student {Id=100,Name="Alex", Gender="Male",Age=22 },
                new Student {Id=101,Name="John", Gender="Male",Age=21 },
                new Student {Id=102,Name="Anna", Gender="Female",Age=20},
                new Student {Id=103,Name="Julla", Gender="FeMale",Age=19 },
                new Student {Id=104,Name="Svetlana", Gender="Female",Age=18}
            };
        }
    }
}
