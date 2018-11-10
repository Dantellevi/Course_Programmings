using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace Work_Catalogs
{
    class Program
    {

        /// <summary>
        /// Метод создания каталога по указанному пути
        /// </summary>
        /// <param name="path"></param>
        /// <param name="SomePath"></param>
        void CreateCatalog(string path,string SomePath)
        {
            //string path = @"C:\SomeDir";
            //string subpath = @"program\avalon";
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }
            dirInfo.CreateSubdirectory(SomePath);
        }


        /// <summary>
        /// Метод получения информации о каталоге
        /// </summary>
        /// <param name="path"></param>
        void GetCatalogInfo(string path)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(path);

            Console.WriteLine("Название каталога: {0}", dirInfo.Name);
            Console.WriteLine("Полное название каталога: {0}", dirInfo.FullName);
            Console.WriteLine("Время создания каталога: {0}", dirInfo.CreationTime);
            Console.WriteLine("Корневой каталог: {0}", dirInfo.Root);
        }


        void DeleteCatalog(string Path)
        {

            try
            {
                DirectoryInfo dir = new DirectoryInfo(Path);
                dir.Delete(true);

            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }


        void GetInfoFile(string Path)
        {
            FileInfo fl = new FileInfo(Path);
            if(fl.Exists)
            {

            }
            else
            {
                Console.WriteLine("Имя файла: {0}", fl.Name);
                Console.WriteLine("Время создания: {0}", fl.CreationTime);
                Console.WriteLine("Размер: {0}", fl.Length);
            }
        }

        void DeleteFile(string Path)
        {
            FileInfo file = new FileInfo(Path);
            try
            {
                if(file.Exists)
                {
                    file.Delete();
                }
            }
            catch
            {

            }
        }



       void SetDirectoryFile(string path,string newpath)
        {
            FileInfo fileInf = new FileInfo(path);
            if (fileInf.Exists)
            {
                fileInf.MoveTo(newpath);
                // альтернатива с помощью класса File
                // File.Move(path, newPath);
            }
        }

        void CopyToFile(string path, string newpath)
        {
            FileInfo fileInf = new FileInfo(path);
            if (fileInf.Exists)
            {
                fileInf.CopyTo(newpath, true);
                // альтернатива с помощью класса File
                // File.Copy(path, newPath, true);
            }
        }

        static void Main(string[] args)
        {
            string dirNaame = Console.ReadLine();
            if(Directory.Exists(dirNaame))
            {
                string[] direct = Directory.GetDirectories(dirNaame);
                foreach(var b in direct)
                {
                    Console.WriteLine("Каталог:{0}", b);
                }
                Console.WriteLine();
                Console.WriteLine("Файлы:");
                string[] files = Directory.GetFiles(dirNaame);
                foreach (string s in files)
                {
                    Console.WriteLine(s);
                }

                //перемещение
                string oldPath = @"C:\SomeFolder";
                string newPath = @"C:\SomeDir";
                DirectoryInfo dirInfo = new DirectoryInfo(oldPath);
                if (dirInfo.Exists && Directory.Exists(newPath) == false)
                {
                    dirInfo.MoveTo(newPath);
                }
            }
            else
            {
                Console.WriteLine("Не существует такого каталога !!!");
            }
        }
    }
}
