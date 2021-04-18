#include "test.h"

int main(){
    Test t;
    int check = t.testing();
    while(check != -1){
        check = t.testing();
    }
    return 0;
}