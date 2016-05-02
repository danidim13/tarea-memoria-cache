BINARY=Tarea.out

$(BINARY): main.cpp CacheMemory.h CacheMemory.cpp CacheSet.h CacheSet.cpp
	g++ -o $(BINARY) main.cpp CacheMemory.cpp CacheSet.cpp

all: $(BINARY)

clean:
	rm -f $(BINARY)
	
