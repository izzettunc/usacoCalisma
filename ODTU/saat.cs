using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {

            Int32 n, i;
            Decimal l, t;
            Decimal[] v = new Decimal[100001];


            String temp = Console.ReadLine();
            l = Convert.ToDecimal(Convert.ToInt32(temp.Split(' ')[0]));
            n = Convert.ToInt32(temp.Split(' ')[1]);
            for (i = 0; i < n; i++)
            {
                temp = Console.ReadLine();
                v[i] = Math.Abs(Convert.ToDecimal(Convert.ToInt32(temp)));
            }
            temp = Console.ReadLine();
            t = Convert.ToDecimal(Convert.ToInt32(temp));
            Decimal p = 1;
            for (i = 0; i < n; i++)
            {
                if (v[i] != 0)
                    p *= 1 - (v[i] * t) / l;
            }
            Console.WriteLine(1 - p);

        }
    }
}