#---------------------------------------------------------
# CLASS Wago properties
# $Id: WagoCatalogue.res,v 1.8 2016/04/05 11:25:48 perez Exp $
#---------------------------------------------------------
#
# List of know WAGO modules usable by the WAGO Device Server
# SYNTAX: 
#   -the first item should be the date the list has been updated
#   -then, for each module, you must supply:
#          -module reference
#          -number of digital  inputs
#          -number of digital outputs
#          -number of word     inputs
#          -number of word    outputs
#          -number of logical channels (typically SSI32bits==2 words)
#          -string for special module  ("none\","ssi\","thc\","thck\",etc)
#          -string for description
#
CLASS/Wago->modulesCatalogue: \
 "750-400,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-401,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-402,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-403,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-404,    0, 0, 3, 0, 3, \"none\",      \"32 bit Counter\"", \
 "750-405,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-406,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-408,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-409,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-410,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-411,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-412,    2, 0, 0, 0, 2, \"none\",      \"2 Channel Digital Input\"", \
 "750-414,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-415,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-422,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-432,    4, 0, 0, 0, 4, \"none\",      \"4 Channel Digital Input\"", \
 "750-430,    8, 0, 0, 0, 8, \"none\",      \"8 Channel Digital Input\"", \
 "750-436,    8, 0, 0, 0, 8, \"none\",      \"8 Channel Digital Input\"", \
 "750-485,    0, 0, 2, 0, 2, \"fs4-20_13\", \"2 Channel 4/20mA Input\"",  \
 "750-501,    0, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-502,    0, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-504,    0, 4, 0, 0, 4, \"none\",      \"4 Channel Digital Output\"", \
 "750-506,    2, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-507,    2, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-508,    2, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-509,    0, 2, 0, 0, 2, \"none\",      \"2 Channel Digital Output\"", \
 "750-512,    0, 2, 0, 0, 2, \"none\",      \"2 Normally Open Relay Output\"", \
 "750-513,    0, 2, 0, 0, 2, \"none\",      \"2 Normally Open Relay Output\"", \
 "750-514,    0, 2, 0, 0, 2, \"none\",      \"2 Changeover Relay Output\"", \
 "750-516,    0, 4, 0, 0, 4, \"none\",      \"4 Channel Digital Output\"", \
 "750-517,    0, 2, 0, 0, 2, \"none\",      \"2 Changeover Relay Output\"", \
 "750-519,    0, 4, 0, 0, 4, \"none\",      \"4 Channel Digital Output\"", \
 "750-530,    0, 8, 0, 0, 8, \"none\",      \"8 Channel Digital Output\"", \
 "750-531,    0, 4, 0, 0, 4, \"none\",      \"4 Channel Digital Output\"", \
 "750-536,    0, 8, 0, 0, 8, \"none\",      \"8 Channel Digital Output\"", \
 "750-452,    0, 0, 2, 0, 2, \"fs20_13\",   \"2 Channel 0/20mA Input\"", \
 "750-454,    0, 0, 2, 0, 2, \"fs4-20_13\", \"2 Channel 4/20mA Input\"", \
 "750-455,    0, 0, 4, 0, 4, \"fs4-20_13\", \"4 Channel 4/20mA Input\"", \
 "750-456,    0, 0, 2, 0, 2, \"fs10_13\",   \"2 Channel +-10V Differential Input\"", \
 "750-457,    0, 0, 4, 0, 4, \"fs10_13\",   \"4 Channel +-10V Input\"", \
 "750-461,    0, 0, 2, 0, 2, \"thc\",       \"2 Channel PT100 Input\"", \
 "750-462,    0, 0, 2, 0, 2, \"thc\",       \"2 Channel Thermocouple Input\"", \
 "750-465,    0, 0, 2, 0, 2, \"fs20_13\",   \"2 Channel 0/20mA Input\"", \
 "750-466,    0, 0, 2, 0, 2, \"fs4-20_13\", \"2 Channel 4/20mA Input\"", \
 "750-467,    0, 0, 2, 0, 2, \"fs10_13\",   \"2 Channel 0/10V Input\"", \
 "750-468,    0, 0, 4, 0, 4, \"fs10_13\",   \"4 Channel 0/10V Input\"", \
 "750-469,    0, 0, 2, 0, 2, \"thc\",       \"2 Channel Ktype Thermocouple Input\"", \
 "750-472,    0, 0, 2, 0, 2, \"fs20\",      \"2 Channel 0/20mA 16bit Input\"", \
 "750-474,    0, 0, 2, 0, 2, \"fs4-20\",    \"2 Channel 4/20mA 16bit Input\"", \
 "750-476,    0, 0, 2, 0, 2, \"fs10\",      \"2 Channel +-10V Input\"", \
 "750-477,    0, 0, 2, 0, 2, \"fs20\",      \"2 Channel 0/10V Differential Input\"", \
 "750-478,    0, 0, 2, 0, 2, \"fs10\",      \"2 Channel 0/10V Input\"", \
 "750-479,    0, 0, 2, 0, 2, \"fs10_14\",   \"2 Channel +-10V Input\"", \
 "750-480,    0, 0, 2, 0, 2, \"fs20_13\",   \"2 Channel 0/20mA Input\"", \
 "750-483,    0, 0, 2, 0, 2, \"fs30\",      \"2 Channel 0/30V Differential Input\"", \
 "750-492,    0, 0, 2, 0, 2, \"fs4-20_13\", \"2 Channel 4/20mA Differential Input\"", \
 "750-550,    0, 0, 0, 2, 2, \"fs10\",      \"2 Channel 0/10V Output\"", \
 "750-552,    0, 0, 0, 2, 2, \"fs20\",      \"2 Channel 0/20mA Output\"", \
 "750-554,    0, 0, 0, 2, 2, \"fs4-20\",    \"2 Channel 4/20mA Output\"", \
 "750-556,    0, 0, 0, 2, 2, \"fs10\",      \"2 Channel +-10V Output\"", \
 "750-557,    0, 0, 0, 4, 4, \"fs10\",      \"4 Channel +-10V Output\"", \
 "750-562-UP, 0, 0, 0, 2, 2, \"fs10\",      \"2 Channel 0/ 10V 16bit Output\"", \
 "750-562,    0, 0, 0, 2, 2, \"fs10\",      \"2 Channel +-10V 16bit Output\"", \
 "750-630,    0, 0, 2, 0, 1, \"ssi24\",     \"24 bit SSI encoder\"", \
 "750-630-24, 0, 0, 2, 0, 1, \"ssi24\",     \"24 bit SSI encoder\"", \
 "750-630-32, 0, 0, 2, 0, 1, \"ssi32\",     \"32 bit SSI encoder\"", \
 "750-637,    0, 0, 4, 4, 2, \"637\",       \"32 bit Incremental encoder\"", \
 "750-653,    0, 0, 2, 2, 1, \"653\",       \"RS485 Serial Interface\"", \
 "750-1416,   8, 0, 0, 0, 8, \"none\",      \"8 Channel Digital Input\"", \
 "750-1417,   8, 0, 0, 0, 8, \"none\",      \"8 Channel Digital Input\"", \
 "750-1515,   0, 8, 0, 0, 8, \"none\",      \"8 Channel Digital Output\"", \
 "750-459,    0, 0, 4, 0, 4, \"fs10_13\",   \"4 Channel Channel 0/10V Input\""

