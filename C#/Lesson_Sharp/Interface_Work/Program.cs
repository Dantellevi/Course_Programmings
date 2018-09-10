using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface_Work
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }



    public interface Person
    {
        string GetName();
        void SetName(string SName);
        DateTime Tmin(); 
        
    }
}
