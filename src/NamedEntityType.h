//
// Created by Olcay Taner YILDIZ on 3.06.2023.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYTYPE_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYTYPE_H

enum named_entity_type{
    NONE, PERSON, ORGANIZATION, LOCATION, TIME, MONEY
};

typedef enum named_entity_type Named_entity_type;

Named_entity_type get_named_entity_type(const char* entity);

char* named_entity_type_to_string(Named_entity_type named_entity_type);

#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYTYPE_H
