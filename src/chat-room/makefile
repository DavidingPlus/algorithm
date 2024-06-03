OBJECTS=ThreadPool.c LinkQueue.c DoubleLinkList.c main.c StdThread.c
main:${OBJECTS}
	gcc ${OBJECTS} -o main

OBJECTS_SERVER=StdTcp.c StdThread.c DoubleLinkList.c tcp_server.c ThreadPool.c LinkQueue.c
server:${OBJECTS_SERVER}
	gcc ${OBJECTS_SERVER} -o server

OBJECTS_CLIENT=StdTcp.c StdThread.c DoubleLinkList.c tcp_client.c ThreadPool.c LinkQueue.c
client:${OBJECTS_CLIENT}
	gcc ${OBJECTS_CLIENT} -o client

.PHONY:clean
clean: main server client
	rm main server client
