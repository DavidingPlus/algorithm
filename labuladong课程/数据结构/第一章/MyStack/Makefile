src = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = a.out
CXX = g++
MEMORY = -fsanitize=address
LIB = -l MyLinkedList -L ./
INCLUDE = -I ../MyLinkedList

$(target):$(src)
	$(CXX) $(src) -o $(target) $(MEMORY)  

%.o:%.cpp
	$(CXX) -c $< -o $@ $(INCLUDE) $(LIB)

.PHONY:clean
clean:
	rm $(src) $(target)
	