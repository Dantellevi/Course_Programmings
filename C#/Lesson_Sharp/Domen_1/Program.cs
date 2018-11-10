using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace Domen_1
{
    class Program
    {
        static void Main(string[] args)
        {
            foreach(Process pr in Process.GetProcesses())
            {
                Console.WriteLine("Процесс имя:" + pr.ProcessName);
            }

            Console.ReadKey();

            Process proc = Process.GetProcessesByName("devenv")[0];
            ProcessThreadCollection processThreads = proc.Threads;

            foreach (ProcessThread thread in processThreads)
            {
                Console.WriteLine("ThreadId: {0}  StartTime: {1}",
                    thread.Id, thread.StartTime);
            }


            Console.ReadKey();
            //запуск нового процесса
            ProcessStartInfo procInfo = new ProcessStartInfo();
            // исполняемый файл программы - браузер хром
            procInfo.FileName = "C://Program Files//Google//Chrome//Application//chrome.exe";
            // аргументы запуска - адрес интернет-ресурса
            procInfo.Arguments = "http://google.com";
            Process.Start(procInfo);

        }
    }
}
