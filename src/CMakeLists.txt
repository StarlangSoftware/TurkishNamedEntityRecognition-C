cmake_minimum_required(VERSION 3.23)
project(NamedEntityRecognition C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(NamedEntityRecognition src/SlotType.h src/NamedEntityType.h src/Slot.c src/Slot.h src/Gazetteer.c src/Gazetteer.h src/NamedEntityWord.c src/NamedEntityWord.h src/NamedEntitySentence.c src/NamedEntitySentence.h src/NamedEntityType.c src/NerCorpus.c src/NerCorpus.h)
target_link_libraries(NamedEntityRecognition ${CONAN_LIBS})
