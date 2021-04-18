#include "test.h"

int main(){
    Test t;
    int check = t.testing();
    while(check != -1){
        check = t.testing();
    }
    return 0;
    // Worker w("Tom", "Jerry", "worker1", 12, 12345);
    // w.add_customer("Lisa");
    // Worker e(w);
    // Worker r = w;

    // cout << w << endl;
    // cout << e << endl;
    // cout << r << endl;

    // r.set_salary(1000);
    // e.set_salary(800);

    // cout << w << endl;
    // cout << e << endl;
    // cout << r << endl;
}