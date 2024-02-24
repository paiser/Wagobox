#
# Resource template
#

#---------------------------------------------------------
# SERVER Wago/wclbl01, Modbus device declaration
#---------------------------------------------------------

Wago/wclbl01/DEVICE/Modbus: "BCG/wclbl01/mb"


BCG/wclbl01/mb->Iphost: 128.3.128.129
BCG/wclbl01/mb->Protocol: TCP
BCG/wclbl01/mb->TCPTimeout: 1000



#---------------------------------------------------------
# SERVER Wago/wclbl01, Wago device declaration
#---------------------------------------------------------

Wago/wclbl01/DEVICE/Wago: "bcg/wclbl01/tg"


bcg/wclbl01/tg->config: "750-432,din1,din2,din3,din4",\ 
                        "750-504,dout2,dout2,dout2,dout2",\  
                        "750-469,temp6,temp6"

bcg/wclbl01/tg->modbusDevName: "BCG/wclbl01/mb"



