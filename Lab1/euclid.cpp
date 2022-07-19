#include <cpp>
/*int main(){
    let num;
    $$(
        $(l) {num = {112,182};},
        $(l) {
            _&a=l[0],&b=l[1];
            a=a%b;
            swap(a,b);
        },
        $(l){return l[1]!=0;},
        num
    );
    print("Euclid's algorithm, GCD:", num[0], "\n");
}*/

/* int main(){
    let num;
    $$(
        $(l) {num = {112,182};},
        $(l) {
            _ tmp = l[1];
            l[1] = l[0] % l[1];
            l[0] = tmp;
        },
        $(l){return l[1]!=0;},
        num
    );
    print("Euclid's algorithm, GCD:", num[0], "\n");
} */

int main(){
    let num;
    $$(
        $(l) {num = {36,12};},
        $(l) {
            l = {l[1], l[0] % l[1]};
        },
        $(l){return l[1]!=0;},
        num
    );
    print("Euclid's algorithm, GCD:", num[0], "\n");
}