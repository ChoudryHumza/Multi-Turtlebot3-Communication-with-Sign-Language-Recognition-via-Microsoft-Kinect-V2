using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            MLApp.MLApp matlab = new MLApp.MLApp();
            matlab.Visible = 0;
            //  state = enableservice('AutomationServer')
            string state = matlab.Execute("enableservice('AutomationServer', true)");
            Console.WriteLine("AutoServer State: " +state);

            string ex0 = matlab.Execute("rosinit('192.168.1.161');"); //CHANGE IP!!!!!, CHECK THE IP OF LISTENER 
            string ex1 = matlab.Execute("chatpub = rospublisher('/turtle', 'std_msgs/String');");
            string ex2 = matlab.Execute("msg = rosmessage(chatpub);");


      

            string wh111 = matlab.Execute("msg.Data = 'forward';");
            string wht5 = matlab.Execute("send(chatpub,msg);");


            string wh11 = matlab.Execute("msg.Data = 'turn left';");
            string wht2 = matlab.Execute("send(chatpub,msg);");




   

        }
    }
}
 
