using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace XML_Linq_1
{
    class Program
    {
        static void Main(string[] args)
        {
            /*---------------------------------Создание XML документа-----------------------------------------*/
            //var xmlDoc = new XDocument(new XDeclaration("1.0","utf-8","yes"),new XElement("Students",Student.GetAllStudents().Select(item=>
            //new XElement("Student", new XAttribute("Id", item.Id),
            //        new XElement("Name", item.Name),
            //        new XElement("Gender", item.Gender),
            //        new XElement("Age", item.Age)))));



            //xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc1.xml"));
            /*---------------------------------Чтение XML документа-----------------------------------------*/

            //var std =
            //    from student in
            //        XDocument.Load(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml")).Descendants("Student")
            //    where student.Element("Gender").Value == "Male"
            //    select new Student
            //    {
            //        Id=(int)student.Attribute("Id"),
            //        Name=student.Element("Name").Value.ToString(),
            //        Gender = student.Element("Gender").Value.ToString(),
            //        Age=(int)student.Element("Age")
            //    };



            //foreach(var student in std)
            //{
            //    Console.WriteLine("Имя :{0}\n Возраст: {1}", student.Name, student.Age);
            //    Console.WriteLine("------------------------");
            //}

            /*==============================Редактирование XML========================================*/
            //var xmlDoc = XDocument.Load(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            ////Обращаемся к корневому элементу, добавляем новый элемент
            //xmlDoc.Element("Students").Add(new XElement("Student",new XAttribute("Id",105),new XElement("Name","Dante"),
            //    new XElement("Gender","Male"),
            //    new XElement("Age",24)));
            //xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            ////Добавление в начало
            //xmlDoc.Element("Students").AddFirst(new XElement("Student", new XAttribute("Id", 99), new XElement("Name", "Sparda"),
            //   new XElement("Gender", "Male"),
            //   new XElement("Age", 24)));
            //xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));


            ////выборка и нахождение 104 элемента добавление перед ним нового элемента
            //xmlDoc.Element("Students").Elements("Student").Where(x => x.Attribute("Id").Value == "104").FirstOrDefault().AddBeforeSelf(

            //    new XElement("Student", new XAttribute("Id", 98), new XElement("Name", "Alfa"),
            //   new XElement("Gender", "Male"),
            //   new XElement("Age", 24))

            //    );
            //xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));

            //-------------------------Удаление-----------------------------
            //var xmlDoc = XDocument.Load(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            //xmlDoc.Element("Students").Elements("Student").Where(x => x.Attribute("Id").Value == "98").FirstOrDefault().Remove();
            //xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            //--------------------------Редактирование свойства элемента ID=104-----------------
            var xmlDoc = XDocument.Load(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            xmlDoc.Element("Students").Elements("Student").Where(x => x.Attribute("Id").Value == "104").FirstOrDefault().SetElementValue("Gender", "Male");
            xmlDoc.Save(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml"));
            Console.ReadKey();
        }
    }
}
