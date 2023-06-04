//
// Created by Olcay Taner YILDIZ on 4.06.2023.
//

#include <FileUtils.h>
#include <string.h>
#include "NerCorpus.h"
#include "NamedEntitySentence.h"

/**
 * Another constructor of {@link NERCorpus} which takes a fileName of the corpus as an input, reads the
 * corpus from that file.
 *
 * @param fileName Name of the corpus file.
 */
Corpus_ptr create_ner_corpus(const char *file_name) {
    FILE* input_file;
    char line[MAX_LINE_LENGTH];
    Corpus_ptr result = create_corpus();
    input_file = fopen(file_name, "r");
    char* input = fgets(line, MAX_LINE_LENGTH, input_file);
    while (input != NULL){
        line[strcspn(line, "\n")] = 0;
        corpus_add_sentence(result, create_named_entity_sentence(line));
        input = fgets(line, MAX_LINE_LENGTH, input_file);
    }
    fclose(input_file);
    return result;
}
