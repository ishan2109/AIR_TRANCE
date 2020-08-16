using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;


namespace Flight_Controller
{
    public partial class Form1 : Form
    {
        String pid_pr_p;
        String pid_pr_i;
        String pid_pr_d;
        String pid_y_p;
        String pid_y_i;
        String pid_y_d;
        String throttle;
        String emergency = "0000";
        String tx_array="";
        String rx_array="jhgfdxfgh";
        bool rx_flag = false;
        System.Threading.Thread t;
        public Form1()
        {
            InitializeComponent();
            getAvailablePorts();
            button3.Enabled = false;
           // serialPort1.DataReceived+= new SerialDataReceivedEventHandler(DataReceivedHandler);
            t = new System.Threading.Thread(DoThisAllTheTime);
            t.Start();
            trackBar1.Minimum = 1000;
            trackBar1.Maximum = 2000;
            trackBar1.Value = 1200;
        }
        public void DoThisAllTheTime()
        {
            if (rx_flag)
                textBox15.Text = rx_array; rx_flag = false; rx_array = "";
        }
            void getAvailablePorts()
        {
            String[] port_name = SerialPort.GetPortNames();
            ports.Items.AddRange(port_name);
        }
        String convert_to_string(int x)
        {

            String local = "";
            for (int i = 0; i < 4; i++)
            {
                if ((x % 10) == 0 && (i < 3)) local += "0";
                else local += (x % 10);
                x /= 10;
            }
            if (local == "") local = "0000";
            local = ReverseString(local);
            return local;
        }

        public static string ReverseString(string s)
        {
            char[] arr = s.ToCharArray();
            Array.Reverse(arr);
            return new string(arr);
        }


        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            emergency = "0001";
            int value = Convert.ToInt32(Convert.ToDouble(textBox4.Text) * 1000);
            pid_y_d = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox5.Text) * 1000);
            pid_y_i = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox6.Text) * 1000);
            pid_y_p = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox3.Text) * 1000);
            pid_pr_d = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox2.Text) * 1000);
            pid_pr_i = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox1.Text) * 1000);
            pid_pr_p = convert_to_string(value);

            throttle = convert_to_string(Convert.ToInt32(textBox7.Text));


            tx_array = pid_pr_p + pid_pr_i + pid_pr_d + pid_y_p + pid_y_i + pid_y_d + throttle + emergency;
            textBox15.Text = tx_array;
            serialPort1.Write(tx_array);
            tx_array = "";
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void P_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void ports_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (connect.Text == "Disconnect")
            {
                serialPort1.Close();
                button3.Enabled = false;
                connect.Text = "Connect";

            }
            else
            {
                serialPort1.PortName = ports.Text;
                serialPort1.BaudRate = Convert.ToInt32(baud.Text);
                serialPort1.Open();
                button3.Enabled = true;
                connect.Text = "Disconnect";
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            int value = Convert.ToInt32(Convert.ToDouble(textBox4.Text) * 1000);
            pid_y_d = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox5.Text) * 1000);
            pid_y_i = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox6.Text) * 1000);
            pid_y_p = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox3.Text) * 1000);
            pid_pr_d = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox2.Text) * 1000);
            pid_pr_i = convert_to_string(value);

            value = Convert.ToInt32(Convert.ToDouble(textBox1.Text) * 1000);
            pid_pr_p = convert_to_string(value);

            throttle = convert_to_string(Convert.ToInt32(textBox7.Text));


            tx_array = pid_pr_p + pid_pr_i + pid_pr_d + pid_y_p + pid_y_i + pid_y_d + throttle + emergency;
            textBox15.Text = tx_array;
            serialPort1.Write(tx_array);
            tx_array = "";
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox15_TextChanged(object sender, EventArgs e)
        {

        }
        void set_text()
        {
            textBox15.Text = rx_array;
        }
        /*
        public void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            
            ////SerialPort sp = (SerialPort)sender;
            ////rx_array = sp.ReadExisting();
            //rx_array = serialPort1.ReadExisting();
            //set_text();
            
            SerialPort usb = (SerialPort)sender;
            rx_array = usb.ReadExisting();rx_flag = true;
           

        }
        */

        private void timer1_Tick(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            textBox7.Text = Convert.ToString(trackBar1.Value);
        }
    }
}
