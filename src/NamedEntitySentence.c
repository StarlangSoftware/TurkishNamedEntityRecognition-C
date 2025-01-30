//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <Memory/Memory.h>
#include "NamedEntitySentence.h"
#include "NamedEntityType.h"
#include "NamedEntityWord.h"

/**
 * Another constructor of NamedEntitySentence. It takes input a named entity annotated sentence in string
 * form, divides the sentence with respect to space and sets the tagged words with respect to their tags.
 * @param sentence Named Entity annotated sentence in string form
 */
Sentence_ptr create_named_entity_sentence(char* sentence) {
    Sentence_ptr result = create_sentence();
    Array_list_ptr word_array = split(sentence);
    String_ptr entity_type, candidate;
    Named_entity_type type = NER_NONE;
    for (int i = 0; i < word_array->size; i++){
        String_ptr word = array_list_get(word_array, i);
        if (!string_empty(word)){
            if (!string_equals2(word, "<b_enamex")){
                if (starts_with(word->s, "TYPE=\"")){
                    int typeIndexEnd = str_find_c(&(word->s[6]), "\"");
                    if (typeIndexEnd != -1){
                        entity_type = substring(word->s, 6, typeIndexEnd - 6);
                        type = get_named_entity_type(entity_type->s);
                        free_string_ptr(entity_type);
                    }
                    if (ends_with(word->s, "e_enamex>")){
                        candidate = substring(word->s, str_find_c(word->s, ">") + 1, str_find_c(word->s, "<") - str_find_c(word->s, ">") - 1);
                        if (!string_empty(candidate)){
                            array_list_add(result->words, create_named_entity_word(candidate->s, type));
                        }
                        free_string_ptr(candidate);
                        type = NER_NONE;
                    } else {
                        candidate = substring2(word->s, str_find_c(word->s, ">") + 1);
                        if (!string_empty(candidate)){
                            array_list_add(result->words, create_named_entity_word(candidate->s, type));
                        }
                        free_string_ptr(candidate);
                    }
                } else {
                    if (ends_with(word->s, "e_enamex>")){
                        candidate = substring(word->s, 0, str_find_c(word->s, "<"));
                        if (!string_empty(candidate)){
                            array_list_add(result->words, create_named_entity_word(candidate->s, type));
                        }
                        free_string_ptr(candidate);
                        type = NER_NONE;
                    } else {
                        if (!string_empty(word)){
                            array_list_add(result->words, create_named_entity_word(word->s, type));
                        }
                    }
                }
            }
        }
    }
    free_array_list(word_array, (void (*)(void *)) free_string_ptr);
    return result;
}

/**
 * Frees memory allocates for a named entity sentence. Deallocates the words array.
 * @param sentence Sentence to deallocate.
 */
void free_name_entity_sentence(Sentence_ptr sentence) {
    free_array_list(sentence->words, (void (*)(void *)) free_named_entity_word);
    free_(sentence);
}
