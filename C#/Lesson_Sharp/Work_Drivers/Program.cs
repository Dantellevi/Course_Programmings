using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Work_Drivers
{
    class Program
    {
        static void Main(string[] args)
        {
            DriveInfo[] drivers = DriveInfo.GetDrives(); //получаем список дисков
    
            try
            {
                foreach (DriveInfo d in drivers)
                {
                    if(d.IsReady)
                    {
                        Console.WriteLine("Имя диска:{0}", d.Name);
                        Console.WriteLine("Тип диска:{0}", d.DriveType);
                        Console.WriteLine("Общий размер диска:{0}", d.TotalFreeSpace);
                        Console.WriteLine("Свободный размер диска:{0}", d.AvailableFreeSpace);
                        Console.WriteLine("------------------------------------------------------");
                    }
                    else if(!d.IsReady)
                    {
                        Console.WriteLine("Извините устройство {0} не готово!!!",d.Name);
                    }
                    
                }
            }

            catch(Exception exs)
            {
                Console.WriteLine("Ошибка:" + exs.Message);
            }
           


            Console.ReadKey();
        }
    }
}
