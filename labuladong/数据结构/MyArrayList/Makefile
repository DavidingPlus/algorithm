src = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = a.out
CXX = g++
# 内存消毒器
MEMORY = -fsanitize=address

$(target):$(src)
	$(CXX) $(src) -o $(target) $(MEMORY)

%.o:%.cpp
	$(CXX) -c $< -o $@ $(MEMORY)

.PHONY:clean
clean:
	rm $(src) $(target)
