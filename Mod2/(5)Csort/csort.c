#include <stdio.h>
#include <string.h>

void csort(char *src, char *dest)
{
    int sentence_length = strlen(src), max = 0, min = 10001, space = 0;
    int word_length = 0, final_sentence_length = 0;
    for(int i = 0; i <= sentence_length - 1; i++){
        if(src[i] != 32){
            final_sentence_length++;
            word_length++;
        }else{
            if(src[i - 1] != 32){
                if( (word_length > max) || (word_length < min) ){
                    if(word_length > max) max = word_length;
                    else min = word_length;
                }
                space++;
                word_length = 0;
            }
        }
    }
    final_sentence_length += space;
    if(min == 10001) min = max = final_sentence_length;
    
    int word_lengths[max - min + 1], word_quantity[max - min + 1];
    for(int i = 0; i <= max - min; i++) word_lengths[i] = min + i;
    for(int i = 0; i <= max - min; i++) word_quantity[i] = 0;
    word_length = 0;
    for(int i = 0; i <= sentence_length - 1; i++){
        if(src[i] != 32){
            word_length++;
        }else{
            if(src[i - 1] != 32){
                for(int j = 0; j <= max - min; j++)
                    if(word_lengths[j] == word_length)
                        word_quantity[j]++;
                word_length = 0;
            }
        }
    }
    for(int i = 0; i <= max - min; i++) if(word_lengths[i] == word_length) word_quantity[i]++;
    
    int count[max - min + 1];
    count[0] = 0;
    for(int i = 1; i <= max - min; i++)
        count[i] = count[i - 1] + word_lengths[i - 1] * word_quantity[i - 1] + word_quantity[i - 1];
    
    for(int i = 0; i <= final_sentence_length - 1; i++) dest[i] = ' ';
    dest[final_sentence_length] = '\0';
    
    word_length = 0;
    int index;
    int i = 0;
    while(i <= sentence_length - 1){
        if(src[i] != 32){
            index = i;
            while( (src[i] != 32) && (i <= sentence_length - 1) ){
                i++;
                word_length++;
            }
            for(int j = 0; j <= max - min; j++)
                if(word_lengths[j] == word_length){
                    for(int k = count[j]; k <= count[j] + word_length - 1; k++){
                        dest[k] = src[index];
                        index++;
                    }
                    count[j] = count[j] + word_lengths[j] + 1;
                }
            word_length = 0;
        }else i++;
    }
    
}

int main(int argc, char **argv)
{
    char sentence[10001];
    gets(sentence);
    
    int length = strlen(sentence);
    char final_sentence[length + 1];
    
    csort(sentence , final_sentence);
    
    printf("%s\n", final_sentence);
    
    return 0;
}
