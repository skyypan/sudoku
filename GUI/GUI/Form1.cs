using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
    public partial class Form1 : Form
    {
        private const int N = 9;
        TextBox[,] textBoxes = new TextBox[N, N];
        int[,] now = new int[9, 9];
        int[,] check = new int[9, 9];
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //测试行中是否有重复
        public bool test_row(int[,] a )
        {
            for (int i = 0; i < 9; i++)
            {
                int[] flag = new int[10] { 0,0,0,0,0,0,0,0,0,0 };
                for (int j = 0; j < 9; j++)
                {
                    if (flag[a[i,j]] == 0) flag[a[i,j]] = 1;
                    else return false;
                }
            }
            return true;
        }
        //测试列中是否有重复
        public bool test_col(int[,] a)
        {
            for (int i = 0; i < 9; i++)
            {
                int[] flag = new int[10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                for (int j = 0; j < 9; j++)
                {
                    if (flag[a[j,i]] == 0) flag[a[j,i]] = 1;
                    else return false;
                }
            }
            return true;
        }
        //测试块中是否有重复
        public bool test_blo(int[,] a)
        {
            int[,] tmp_a = new int[9,9] {
		    {a[0,0],a[0,1],a[0,2],a[1,0],a[1,1],a[1,2],a[2,0],a[2,1],a[2,2]},
		    {a[3,0],a[3,1],a[3,2],a[4,0],a[4,1],a[4,2],a[5,0],a[5,1],a[5,2]},
		    {a[6,0],a[6,1],a[6,2],a[7,0],a[7,1],a[7,2],a[8,0],a[8,1],a[8,2]},
		    {a[0,3],a[0,4],a[0,5],a[1,3],a[1,4],a[1,5],a[2,3],a[2,4],a[2,5]},
		    {a[3,3],a[3,4],a[3,5],a[4,3],a[4,4],a[4,5],a[5,3],a[5,4],a[5,5]},
		    {a[6,3],a[6,4],a[6,5],a[7,3],a[7,4],a[7,5],a[8,3],a[8,4],a[8,5]},
		    {a[0,6],a[0,7],a[0,8],a[1,6],a[1,7],a[1,8],a[2,6],a[2,7],a[2,8]},
		    {a[3,6],a[3,7],a[3,8],a[4,6],a[4,7],a[4,8],a[5,6],a[5,7],a[5,8]},
		    {a[6,6],a[6,7],a[6,8],a[7,6],a[7,7],a[7,8],a[8,6],a[8,7],a[8,8]},
	        };
	        if (test_row(tmp_a)) return true;
	        else return false;
        }

        public bool test_txt()
        {
            for(int i = 0;i < 9;i++)
            {
                for(int j = 0;j < 9;j++)
                {
                    if (textBoxes[i, j].Text == "")
                        return false;
                    check[i, j] = int.Parse( textBoxes[i, j].Text );
                }
            }
            if (test_row(check) && test_col(check) && test_blo(check))
                return true;
            else return false;
        }

        public void makeempty()
        {
            int[] indexs = new int[81];
            for (int i = 0; i < 81; i++)
            {
                indexs[i] = i;
            }

            //声明一个新数组，这个数组为结果数组
            int[] re = new int[81];
            Random r = new Random();
            int site = 81;//最大的索引位置
            int rindex = 0;
            for (int j = 0; j < 81; j++)
            {
                //从0~最大的索引位置中取索引
                rindex = r.Next(0, site);
                //将随机索引的值插入到新的数组
                re[j] = indexs[rindex];
                //将原数组的rindex位置的值替换成原数组中最后一个值
                indexs[rindex] = indexs[site - 1];
                site--;
            }

            Random p = new Random();
            int num = p.Next(30, 60);
            int[] flag = new int[10] { 0,0,0,0,0,0,0,0,0,0 };
            for(int i = 0;num > 0 && i < 81;i++)
            {
                int row = re[i] / 9;
                int clo = re[i] % 9;
                int block = row / 3 * 3 + clo / 3;
                if (flag[block] < 5)
                {
                    now[row, clo] = 0;
                    flag[block]++;
                    num--;
                }
            }
        }

        public void sudoku()
        {

            int[,] trans = new int[9, 9]
            {
                {5,1,2,3,4,6,7,8,9},
                {3,4,6,7,8,9,5,1,2},
                {7,8,9,5,1,2,3,4,6},
                {1,2,3,4,6,7,8,9,5},
                {4,6,7,8,9,5,1,2,3},
                {8,9,5,1,2,3,4,6,7},
                {2,3,4,6,7,8,9,5,1},
                {6,7,8,9,5,1,2,3,4},
                {9,5,1,2,3,4,6,7,8},
            };
            int[] indexs = new int[10];
            for (int i = 0; i < 9; i++)
            {
                indexs[i] = i + 1;
            }

            //声明一个新数组，这个数组为结果数组
            int[] first = new int[10];
            Random r = new Random();
            int site = 9;//最大的索引位置
            int rindex = 0;
            for (int j = 0; j < 9; j++)
            {
                //从0~最大的索引位置中取索引
                rindex = r.Next(0, site);
                //将随机索引的值插入到新的数组
                first[j] = indexs[rindex];
                //将原数组的rindex位置的值替换成原数组中最后一个值
                indexs[rindex] = indexs[site - 1];
                site--;
            }

            int[] tmp = new int[10];
            for (int i = 0; i < 9; i++)
            {
                tmp[trans[0, i]] = first[i];
            }
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if ((j == 2 || j == 5 || j == 8) && (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8))
                        now[i, j] = 0;
                    else
                        now[i, j] = tmp[trans[i, j]];
                }

            }

            makeempty();

        }

        public void GenerateAllButtons()
        {
            sudoku();
            int x0 = 50, y0 = 10, w = 30, d = 35;
            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                {
                    TextBox txt = new TextBox
                    {
                        MaxLength = 1,
                        Top = y0 + r * d,
                        Left = x0 + c * d,
                        Width = w,
                        Height = w,
                        Visible = true,
                        Tag = r * N + c
                    };

                    if (now[r,c] > 0)
                    {
                        txt.BackColor = Color.Orange;
                        txt.Text = now[r, c].ToString();
                        txt.Font = new Font("黑体", 15);
                        txt.ReadOnly = true;
                    }
                    else
                    {
                        txt.BackColor = Color.White;
                        txt.Font = new Font("宋体", 15);
                        txt.Text = "";
                    }

                    //txt.KeyPress += Txt_KeyPress;
                    //txt.TextChanged += Txt_TextChanged;

                    textBoxes[r, c] = txt;


                    this.Controls.Add(txt);

                }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GenerateAllButtons();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for(int i = 0;i < 9;i++)
            {
                for (int j = 0; j < 9; j++)
                    this.Controls.Remove(textBoxes[i, j]);
            }
            GenerateAllButtons();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (test_txt())
                MessageBox.Show("恭喜你完成数独！");
            else
                MessageBox.Show("数独中存在错误");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
