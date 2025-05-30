#include "factor.h"

Factor::Factor(int num) {
    value = num;
}
int Factor::getValue() {
    return value;
}
int Factor::getOccurence() {
    return occurence;
}
void Factor::setValue(int num) {
    value = num;
}
void Factor::incrementOccurence() {
    occurence += 1;
}
  
      