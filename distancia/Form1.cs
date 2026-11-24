using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace distancia
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serialPort1.BaudRate = 9600;
                serialPort1.PortName = "COM6";
                serialPort1.Open();
            }
            else
            {
                label1.Text = "Problemas ao abrir a porta";
                serialPort1.Close();
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = serialPort1.ReadLine();
        }
    }
}
