CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
AR = ar
ARFLAGS = rcs
TARGET = main
LIB = libmylib.a
LIB_OBJS = add.o
MAIN_OBJS = main.o
HDRS = add.h


all: $(TARGET)

$(LIB): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TARGET): $(MAIN_OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJS) -L. -lmylib

$(MAIN_OBJS): main.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

$(LIB_OBJS): add.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f $(TARGET) $(LIB_OBJS) $(MAIN_OBJS) $(LIB)

.PHONY: all clean
