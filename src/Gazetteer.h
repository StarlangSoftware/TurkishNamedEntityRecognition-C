//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_GAZETTEER_H
#define NAMEDENTITYRECOGNITION_GAZETTEER_H

#include "HashMap/HashSet.h"

struct gazetteer {
    Hash_set_ptr data;
    char *name;
};

typedef struct gazetteer Gazetteer;

typedef Gazetteer *Gazetteer_ptr;

Gazetteer_ptr create_gazetteer(const char *name, const char *file_name);

void free_gazetteer(Gazetteer_ptr gazetteer);

bool gazetteer_contains(const Gazetteer *gazetteer, const char *word);

#endif //NAMEDENTITYRECOGNITION_GAZETTEER_H
