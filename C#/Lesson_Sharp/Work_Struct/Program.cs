using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Work_Struct
{
    struct Book
    {
        public string name;
        public string author;
        public int year;


        public void Info()
        {
            Console.WriteLine($"Книга '{name}' (автор {author}) была издана в {year} году");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Book book;
            book.name = "Война и мир";
            book.author = "Л.Н.Толстой";
            book.year = 1869;

            book.Info();

            Console.ReadKey();

            Book[] books = new Book[3];
            books[0].name = "Война и мир";
            books[0].author = "Л. Н. Толстой";
            books[0].year = 1869;

            books[1].name = "Преступление и наказание";
            books[1].author = "Ф. М. Достоевский";
            books[1].year = 1866;

            books[2].name = "Отцы и дети";
            books[2].author = "И. С. Тургенев";
            books[2].year = 1862;

            foreach (Book b in books)
            {
                b.Info();
            }
        }
    }
}
