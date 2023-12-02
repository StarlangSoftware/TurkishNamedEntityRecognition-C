//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "NamedEntityWord.h"
#include "Memory/Memory.h"

/**
 * A constructor of NamedEntityWord which takes name and nameEntityType as input and sets the corresponding attributes
 * @param name Name of the word
 * @param namedEntityType NamedEntityType of the word
 */
Named_entity_word_ptr create_named_entity_word(const char *name, Named_entity_type named_entity_type) {
    Named_entity_word_ptr result = malloc_(sizeof(Named_entity_word), "create_named_entity_word");
    result->name = str_copy(result->name, name);
    result->named_entity_type = named_entity_type;
    return result;
}

void free_named_entity_word(Named_entity_word_ptr named_entity_word) {
    free_(named_entity_word->name);
    free_(named_entity_word);
}
