using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace XML_Convert_CSV
{
    class Program
    {
        static void Main(string[] args)
        {
            var builder = new StringBuilder();
            var delimeter = ",";
            XDocument.Load(Path.Combine(Environment.CurrentDirectory, "xmlDoc.xml")).Descendants("Student").ToList().ForEach(element=>builder.Append(element.Attribute("Id").Value+delimeter+
                element.Element("Name").Value+delimeter+
                element.Element("Gender").Value+delimeter+
                element.Element("Age").Value+"\r\n "));

            using (var str = new FileStream(Path.Combine(Environment.CurrentDirectory,
                "result.csv"), FileMode.OpenOrCreate))
            {
                using (var wr = new StreamWriter(str))
                {
                    wr.WriteLine(builder.ToString());
                    wr.Close();
                }

                str.Close();
            }
            Console.ReadKey();

        }
    }
}
