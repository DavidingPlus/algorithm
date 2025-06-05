src = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = a.out
CXX = g++
# 内存消毒器
MEMORY = -fsanitize=address
# c++23
VERSION = -std=c++23

$(target):$(src)
	$(CXX) $(src) -o $(target) $(MEMORY) $(VERSION)

%.o:%.cpp
	$(CXX) -c $< -o $@ $(MEMORY) $(VERSION)

.PHONY:clean
clean:
	rm $(src) $(target)
