SOURCE=../BufferHolder.cpp ../Module.cpp WagoModbusTango.cpp ../LogicalDevice.cpp ../PhysValueTransformer.cpp ../ModbusAbstract.cpp ../WagoDevice.cpp ../ModuleDB.cpp
MYPROGRAM=test
MYINCLUDES= ../
MYLIBRARIES= -lpthread
DEFINES = -DREG_TEST_ENV
CC=g++
OPT = -std=c++0x -g

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) -I$(MYINCLUDES) $(MYLIBRARIES) $(OPT) $(DEFINES) $(SOURCE) -o $(MYPROGRAM) 

clean:
	rm -f $(MYPROGRAM)
