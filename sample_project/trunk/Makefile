############################ MAKEFILE REMINDER ############################ 
#                                                                         # 
#   $@ is the target                                                      #
#   $< is the first prerequisite                                          #
#   $^ is list of all prerequisites                                       #
#                                                                         #
#   compiler -MM generates dependencies for given files                   #
#   compiler -MT specifies generated dependencie's target                 #
#                                                                         #
########################################################################### 

EXE = sample_project
TARGET = bin/$(EXE)

LIBS =\
 -lstdc++\

CXX = g++
CXXFLAGS = -Wall -std=c++11

#SRCS := $(wildcard src/*.cpp)
SRCS := $(shell find src/ -name "*.cpp")
OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))
DEPS := $(patsubst obj/%.o, obj/%.d, $(OBJS))

all: $(TARGET) tags

$(TARGET): $(OBJS)

	@echo "\nLinking..."	
	$(CXX) $(LIBS) $(OBJS) -o $(TARGET)	


-include $(DEPS)

obj/%.o: src/%.cpp

	@echo "\nCompilation..."	
	$(CXX) $(CXXFLAGS) -c $< -o $@  

	@echo "\nDependencies generation..."	
	$(CXX) -MM $< -MT $@ > $(patsubst obj/%.o, obj/%.d, $@)

clean:	

	@echo "\nCleaning object files..."	
	@-rm -rf obj/*.o 
	@-rm -rf obj/*/*.o 
	@-rm -rf obj/*/*/*.o 

	@echo "\nCleaning dependencies..."	
	@-rm -rf obj/*.d 
	@-rm -rf obj/*/*.d 
	@-rm -rf obj/*/*/*.d 

	@echo "\nCleaning executable..."	
	@-rm -rf $(TARGET) 

	@echo "\nCleaning source tags..."	
	@-rm -rf tags 

	@echo "\nCleaning temporary files..."	
	@-rm -rf *~ .*.swp 

	@echo "\nCleaning docs..."	
	@-rm -rf doc/* 

docs:	

	@echo "\nRunning doxygen..."	
	-doxygen Doxyfile

tags:	

	@echo "\nSource tags generation..."	
	ctags -R ./src
