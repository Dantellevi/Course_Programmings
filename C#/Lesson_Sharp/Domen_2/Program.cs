using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;


namespace Domen_2
{
    class Program
    {
        static void Main(string[] args)
        {
            AppDomain dimain = AppDomain.CurrentDomain;
            Console.WriteLine("Name :{0}", dimain.FriendlyName);
            Console.WriteLine("Base Directory: {0}", dimain.BaseDirectory);
            Console.WriteLine();

            Assembly[] assemblies = dimain.GetAssemblies();
            foreach (Assembly asm in assemblies)
                Console.WriteLine(asm.GetName().Name);

            Console.Read();




            AppDomain secondaryDomain = AppDomain.CreateDomain("Secondary domain");
            // событие загрузки сборки
            secondaryDomain.AssemblyLoad += SecondaryDomain_AssemblyLoad; ;
            // событие выгрузки домена
            secondaryDomain.DomainUnload += SecondaryDomain_DomainUnload; ;


            Console.WriteLine("Домен: {0}", secondaryDomain.FriendlyName);
            secondaryDomain.Load(new AssemblyName("System.Data"));
            Assembly[] assembliess = secondaryDomain.GetAssemblies();
            foreach (Assembly asm in assembliess)
                Console.WriteLine(asm.GetName().Name);
            // выгрузка домена
            AppDomain.Unload(secondaryDomain);
            Console.Read();


        }

        private static void SecondaryDomain_DomainUnload(object sender, EventArgs e)
        {
            Console.WriteLine("Домен выгружен из процесса");
        }

        private static void SecondaryDomain_AssemblyLoad(object sender, AssemblyLoadEventArgs args)
        {
            Console.WriteLine("Сборка загружена");
        }
    }
}
