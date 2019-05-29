using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NaviTest1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Opcja w budowie.");
            Form2 f2 = new Form2();
            f2.ShowDialog();
            this.WindowState = FormWindowState.Normal;
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Opcja w budowie.");
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
