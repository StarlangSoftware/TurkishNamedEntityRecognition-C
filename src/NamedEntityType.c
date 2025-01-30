//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//
#include <Dictionary/Word.h>
#include <string.h>
#include <Memory/Memory.h>
#include "NamedEntityType.h"

/**
 * Function to convert a string entity type to NamedEntityType type.
 * @param entity_type Entity type in string form
 * @return Entity type in NamedEntityType form
 */
Named_entity_type get_named_entity_type(const char *entity_type) {
    Named_entity_type result;
    char* upperCase = to_uppercase(entity_type);
    if (strlen(upperCase) == 0){
        result = NER_NONE;
    } else {
        if (strcmp(upperCase, "NER_PERSON") == 0){
            result = NER_PERSON;
        } else {
            if (strcmp(upperCase, "NER_LOCATION") == 0){
                result = NER_LOCATION;
            } else {
                if (strcmp(upperCase, "NER_ORGANIZATION") == 0){
                    result = NER_ORGANIZATION;
                } else {
                    if (strcmp(upperCase, "NER_TIME") == 0){
                        result = NER_TIME;
                    } else {
                        if (strcmp(upperCase, "NER_MONEY") == 0){
                            result = NER_MONEY;
                        } else {
                            result = NER_NONE;
                        }
                    }
                }
            }
        }
    }
    free_(upperCase);
    return result;
}

/**
 * Function to convert a NamedEntityType to string form.
 * @param named_entity_type Entity type in NamedEntityType form
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

