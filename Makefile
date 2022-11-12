# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC = g++ -std=c++14

# CFLAGS = -g -I/usr/include/jsoncpp

CFLAGS = -g

# CFLAGS = -g -D_ECS36B_HW7_ -I/usr/include/jsoncpp
# CFLAGS = -g -DNOT_RIGHT_NOW -I/usr/include/jsoncpp

# CFLAGS = -g -D_ECS36B_DEBUG_ -I/usr/include/jsoncpp
# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp

INC	=	ecs36b_Common.h

# old: LDFLAGS = 	-lc++ -ljsoncpp

# LDFLAGS = 	-ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client


# rules.
all: 	test_hw3_f2022

#
#

GPS.o:		GPS.cpp GPS.h $(INC)
	$(CC) -c $(CFLAGS) GPS.cpp

Network.o:	Network.cpp Network.h $(INC)
	$(CC) -c $(CFLAGS) Network.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h $(INC)
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h $(INC)
	$(CC) -c $(CFLAGS) Thing.cpp

IOT_Thing.o:	IOT_Thing.cpp IOT_Thing.h Network.h $(INC)
	$(CC) -c $(CFLAGS) IOT_Thing.cpp

test_hw3_f2022.o:	test_hw3_f2022.cpp GPS.h Thing.h IOT_Thing.h Network.h Person.h JvTime.h $(INC)
	$(CC) -c $(CFLAGS) test_hw3_f2022.cpp

test_hw3_f2022:		GPS.o test_hw3_f2022.o Thing.o Person.o JvTime.o IOT_Thing.o Network.o
	g++ -std=c++14 test_hw3_f2022.o GPS.o Thing.o IOT_Thing.o Network.o Person.o JvTime.o -o test_hw3_f2022 $(LDFLAGS)

clean:
	rm -f *.o *~ core test_hw3_f2022


