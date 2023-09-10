src = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = a.out
CXX = g++
MEMORY = -fsanitize=address

$(target):$(src)
	$(CXX) $(src) -o $(target) $(MEMORY)

%.o:%.cpp
	$(CXX) -c $< -o $@

.PHONY:clean
clean:
	rm $(src) $(target)
