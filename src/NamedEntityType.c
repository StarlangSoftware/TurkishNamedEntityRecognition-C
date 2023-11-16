//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//
#include <Dictionary/Word.h>
#include <string.h>
#include "NamedEntityType.h"

/**
 * Function to convert a string entity type to NamedEntityType type.
 * @param entityType Entity type in string form
 * @return Entity type in NamedEntityType form
 */
Named_entity_type get_named_entity_type(const char *entity_type) {
    char* upperCase = to_uppercase(entity_type);
    if (strlen(upperCase) == 0){
        return NER_NONE;
    } else {
        if (strcmp(upperCase, "NER_PERSON") == 0){
            return NER_PERSON;
        } else {
            if (strcmp(upperCase, "NER_LOCATION") == 0){
                return NER_LOCATION;
            } else {
                if (strcmp(upperCase, "NER_ORGANIZATION") == 0){
                    return NER_ORGANIZATION;
                } else {
                    if (strcmp(upperCase, "NER_TIME") == 0){
                        return NER_TIME;
                    } else {
                        if (strcmp(upperCase, "NER_MONEY") == 0){
                            return NER_MONEY;
                        } else {
                            return NER_NONE;
                        }
                    }
                }
            }
        }
    }
}

/**
 * Function to convert a NamedEntityType to string form.
 * @param entityType Entity type in NamedEntityType form
 * @return Entity type in string form
 */
char *named_entity_type_to_string(Named_entity_type named_entity_type) {
    switch (named_entity_type){
        case NER_PERSON:
            return "NER_PERSON";
        case NER_LOCATION:
            return "NER_LOCATION";
        case NER_ORGANIZATION:
            return "NER_ORGANIZATION";
        case NER_TIME:
            return "NER_TIME";
        case NER_MONEY:
            return "NER_MONEY";
        default:
            return "NER_NONE";
    }
}

