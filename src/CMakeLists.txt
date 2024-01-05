cmake_minimum_required(VERSION 3.23)
project(NamedEntityRecognition)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(corpus_c REQUIRED)

add_library(NamedEntityRecognition SlotType.h NamedEntityType.h Slot.c Slot.h Gazetteer.c Gazetteer.h NamedEntityWord.c NamedEntityWord.h NamedEntitySentence.c NamedEntitySentence.h NamedEntityType.c NerCorpus.c NerCorpus.h)
target_link_libraries(NamedEntityRecognition corpus_c::corpus_c)
