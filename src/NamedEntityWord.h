//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H

#include "NamedEntityType.h"

struct named_entity_word {
    char *name;
    Named_entity_type named_entity_type;
};

typedef struct named_entity_word Named_entity_word;

typedef Named_entity_word *Named_entity_word_ptr;

Named_entity_word_ptr create_named_entity_word(const char* name, Named_entity_type named_entity_type);

void free_named_entity_word(Named_entity_word_ptr named_entity_word);

#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
