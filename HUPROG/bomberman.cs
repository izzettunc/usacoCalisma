using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bomberman4
{
    class Program
    {
        struct node
        {
            public int i, j, k;
            public node(int i, int j, int k)
            {
                this.i = i;
                this.j = j;
                this.k = k;
            }
        }
        static void Main(string[] args)
        {
            int n, m, si, sj, ei, ej;
            string girdi = Console.ReadLine();
            string[] sp = girdi.Split(' ');
            n = Convert.ToInt32(sp[0]);
            m = Convert.ToInt32(sp[1]);
            si = Convert.ToInt32(sp[2]);
            sj = Convert.ToInt32(sp[3]);
            ei = Convert.ToInt32(sp[4]);
            ej = Convert.ToInt32(sp[5]);

            int[,] w = new int[n, n];
            int[,,] solve = new int[n, n, m + 1];

            int i, j, k;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    for (k = 0; k <= m; k++)
                        solve[i, j, k] = -1;
            char temp;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp = (char)Console.Read();
                    if (temp == '.')
                    {
                        w[i, j] = 0;
                    }
                    else if (temp == 'x')
                    {
                        w[i, j] = 1;
                    }
                    else
                    {
                        j--;
                    }
                }
            }

            Queue<node> q = new Queue<node>();

            q.Enqueue(new node(si, sj, 0));

            int[,] dir =
            {
                {-1,0 },
                {0,+1 },
                {+1,0 },
                {0,-1 }
            };
            solve[si, sj, 0] = 0;
            while (q.Count > 0)
            {
                node x = q.Dequeue();
                for (i = 0; i < 4; i++)
                {
                    if (x.i + dir[i, 0] >= 0 && x.i + dir[i, 0] < n && x.j + dir[i, 1] >= 0 && x.j + dir[i, 1] < n && x.k + w[x.i + dir[i, 0], x.j + dir[i, 1]] <= m && solve[x.i + dir[i, 0], x.j + dir[i, 1], x.k + w[x.i + dir[i, 0], x.j + dir[i, 1]]] == -1 ) //gidilebilir
                    {
                        solve[x.i + dir[i, 0], x.j + dir[i, 1], x.k + w[x.i + dir[i, 0], x.j + dir[i, 1]]] = solve[x.i, x.j, x.k] + 1;
                        if (x.i + dir[i, 0] == ei && x.j + dir[i, 1] == ej)
                        {
                            Console.WriteLine(solve[x.i, x.j, x.k] + 1);
                            return;
                        }
                        q.Enqueue(new node(x.i + dir[i, 0], x.j + dir[i, 1], x.k + w[x.i + dir[i, 0], x.j + dir[i, 1]]));
                    }
                }
            }
            Console.WriteLine("Impossible");
            return;
        }
    }
}
