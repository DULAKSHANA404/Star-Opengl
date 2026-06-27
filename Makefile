CXX = g++

TARGET = app

SOURCES = main.cpp Window.cpp Render.cpp glad/src/glad.c

INCLUDES = -Iglad/include -Iglm

LIBS = -lglfw -lGL -ldl


$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(INCLUDES) $(LIBS) -o $(TARGET)


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET)