src = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = a.out
CXX = g++
# 内存消毒器
MEMORY = -fsanitize=address
# 以下是指定头文件位置和包含静态库
LIB = -l MyLinkedList -L ../MyLinkedList
INCLUDE = -I ../MyLinkedList

$(target):$(src)
	$(CXX) $(src) -o $(target) $(MEMORY) $(INCLUDE) $(LIB)

%.o:%.cpp
	$(CXX) -c $< -o $@ $(MEMORY) $(INCLUDE) $(LIB)

.PHONY:clean
clean:
	rm $(src) $(target)
