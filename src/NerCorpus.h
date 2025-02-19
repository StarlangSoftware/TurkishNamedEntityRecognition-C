//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_NERCORPUS_H
#define NAMEDENTITYRECOGNITION_NERCORPUS_H

#include <Corpus.h>

Corpus_ptr create_ner_corpus(const char* file_name);

void free_ner_corpus(Corpus_ptr corpus);

#endif //NAMEDENTITYRECOGNITION_NERCORPUS_H
