#
# Resource template
#

#---------------------------------------------------------
# SERVER Wago/wcisgd, Modbus device declaration
#---------------------------------------------------------

Wago/wcisgd/DEVICE/Modbus: "ISG/wcisgd/mb"


ISG/wcisgd/mb->Iphost: 160.103.2.18
ISG/wcisgd/mb->Protocol: TCP
ISG/wcisgd/mb->TCPTimeout: 1000



#---------------------------------------------------------
# SERVER Wago/wcisgd, Wago device declaration
#---------------------------------------------------------

Wago/wcisgd/DEVICE/Wago: "isg/wcisgd/tg"


isg/wcisgd/tg->config: "750-400,din1,din2",\ 
                       "750-630,enc4",\ 
                       "750-504,dout2,dout2,dout2,dout2",\ 
                       "750-562,dac0,dac1",\ 
                       "750-459,adc0,adc1,adc2,adc3",\ 
                       "750-556,dac5,dac6",\ 
                       "750-469,temp6,temp6"

isg/wcisgd/tg->modbusDevName: "ISG/wcisgd/mb"



