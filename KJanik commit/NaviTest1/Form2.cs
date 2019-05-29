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
    public partial class Form2 : Form
    {

        Image imgOriginal;
        public Form2()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            this.Close();
            
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            trackBar1.Minimum = -99;
            trackBar1.Maximum = 100;
            imgOriginal = pictureBox1.Image;
        }
        Image zoom(Image img, Size size)
        {
            Bitmap bmp = new Bitmap(img, img.Width + (img.Width * size.Width / 100), img.Height + (img.Height * size.Height / 100));
            Graphics g = Graphics.FromImage(bmp);
            g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
            return bmp;
        }
        private void TrackBar1_Scroll(object sender, EventArgs e)
        {
            pictureBox1.Image = zoom(imgOriginal, new Size(trackBar1.Value, trackBar1.Value));
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (pictureBox1.Image != null)
                pictureBox1.Dispose();
        }
    }
}
