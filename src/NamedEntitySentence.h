//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H

#include "Sentence.h"

Sentence_ptr create_named_entity_sentence(char *sentence);

void free_name_entity_sentence(Sentence_ptr sentence);

#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H
