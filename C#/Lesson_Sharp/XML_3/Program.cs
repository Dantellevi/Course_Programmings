using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace XML_3
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument xDoc = new XmlDocument();
            xDoc.Load("users.xml");
            XmlElement xRoot = xDoc.DocumentElement;

            //Выведем на консоль значения атрибутов name у элементов user:
            XmlNodeList childnodes = xRoot.SelectNodes("user");
            foreach (XmlNode n in childnodes)
                Console.WriteLine(n.SelectSingleNode("@name").Value);

            XmlNode childnode = xRoot.SelectSingleNode("user[@name='Bill Gates']");
            if (childnode != null)
                Console.WriteLine(childnode.OuterXml);
        }
    }
}
